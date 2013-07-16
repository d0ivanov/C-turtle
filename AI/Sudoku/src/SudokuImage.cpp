#include "../include/SudokuImage.h"
#include <cstdlib>

using namespace cv;

//Constructor
SudokuImage::SudokuImage(std::string filepath)
{
    //Read the image
    input_image = cv::imread(filepath.c_str());

    //Apply adaptive thresholding
    PreprocessImage();

    //Hough transform parameters
    int phi_bins = PHI_BINS;
    int r_bins = norm(Point(binary_image.size()));
    int line_threshold = LINE_THRESHOLD * norm(Point(binary_image.size()));

    //Apply Hough transform
    CalcHoughPlane(phi_bins, r_bins);
    CalcHoughPeaks(line_threshold);
    CalcHoughLines();

    //Rectify the SUDOKU
    CalcPerspective();

    //Find the cells
    CalcCells();

    //Thin out the digits for better OCR
    PostprocessImage();

    //Display debug images
    DisplayHoughPlane();
    DisplayRectifiedCells();
    cv::imshow("Image", input_image);
}

//Destructor
SudokuImage::~SudokuImage()
{
    peak_centers.clear();
    lines.clear();
    for(unsigned int i = 0; i < cells.size(); i++)
    {
        cells[i].clear();
    }
}

//Return and image with the digit in a specified cell
//- row - the row of the cell (0=top)
//- col - the columnt of the cell (0=left)
//- sz  - the size of the returned image
cv::Mat SudokuImage::GetDigit(int row, int col, cv::Size sz)
{
    Mat digit = rect_sudoku(cells[row][col]);
    resize(digit, digit, sz);
    threshold(digit, digit, 64, 255, THRESH_BINARY); //64,255
    return digit;
}

//Display the solution
//- s - the sudoku to be displayed
cv::Mat SudokuImage::DrawSolution(const Sudoku& s)
{
    Mat result;
    warpPerspective(input_image, result, Q, SUDOKU_SIZE);

    char text[4];
    for(int i = 0; i < SUDOKU_ORDER * SUDOKU_ORDER; i++)
    {
        if(s.BlueprintChromosome[i] != 0) continue;

        itoa(s.Chromosome[i], text, 10);
        Rect& r = cells[i / SUDOKU_ORDER][i % SUDOKU_ORDER];
        Point ctr = (r.tl() + r.br()) * 0.5;
        ctr += Point(-8, 10);
        putText(result,
                text,
                ctr,
                FONT_HERSHEY_SIMPLEX,
                1.0,
                Scalar(0, 255, 0),
                2,
                true);
    }
    return result;
}
//------------------- Image routines -------------------//
//Preprocess the input image. Apply adaptive thresholding.
void SudokuImage::PreprocessImage()
{
    cv::Mat grayscale;
    cv::cvtColor(input_image, grayscale, CV_BGR2GRAY);

    Mat integral_img = Mat::zeros(grayscale.rows, grayscale.cols, CV_32SC1);
    int sum = 0;

    //Calculate integral image
    for(int i = 0; i < grayscale.rows; i++)
    {
        sum = 0;
        for(int j = 0; j < grayscale.cols; j++)
        {
            sum = sum + grayscale.at<unsigned char>(i, j);
            if(i == 0)
            {
                integral_img.at<unsigned int>(i, j) = sum;
            }
            else
            {
                integral_img.at<unsigned int>(i, j) = integral_img.at<unsigned int>(i - 1, j) + sum;
            }
        }
    }

    binary_image = Mat(grayscale.rows, grayscale.cols, CV_8UC1);
    Point top_left, bottom_right;
    Size half_size = Size((int)(grayscale.cols * 0.125) / 2, (int)(grayscale.rows * 0.125) / 2);
    int count;

    //Perform thresholding
    for(int i = 0; i < grayscale.rows; i++)
    {
        for(int j = 0; j < grayscale.cols; j++)
        {
            top_left = Point(max(0, j - half_size.width),
                             max(0, i - half_size.height));

            bottom_right = Point(min(grayscale.cols - 1, j + half_size.width),
                                 min(grayscale.rows - 1, i + half_size.height));

            count = (bottom_right.x - top_left.x + 1) * (bottom_right.y - top_left.y + 1);

            sum = integral_img.at<unsigned int>(bottom_right);

            sum -= integral_img.at<unsigned int>(max(0, top_left.y - 1),
                                                 bottom_right.x);

            sum -= integral_img.at<unsigned int>(bottom_right.y, max(0,
                                                 top_left.x - 1));

            sum += integral_img.at<unsigned int>(max(0, top_left.y - 1),
                                                 max(0, top_left.x - 1));

            if(grayscale.at<unsigned char>(i, j) * count < sum * 0.85)
            {
                binary_image.at<unsigned char>(i, j) = FOREGROUND;
            }
            else
            {
                binary_image.at<unsigned char>(i, j) = BACKGROUND;
            }
        }
    }

}

//Postprocess the input image. Thin out the digits.
void SudokuImage::PostprocessImage()
{
    //Thin out the digits
    int dilation_size = 1;
    Mat element = getStructuringElement(MORPH_ELLIPSE,
                                        Size( 2 * dilation_size , 2 * dilation_size),
                                        Point(dilation_size, dilation_size));
    erode(rect_sudoku, rect_sudoku, element);
}

//--------------- Hough transform routines -------------//
//Calculate the hough plane.
//- phi_bins - number of angle bins
//- r_bins - number of distance bins
void SudokuImage::CalcHoughPlane(int phi_bins, int r_bins)
{
    //Allocate memory for the hough plane
    hough_plane = Mat::zeros(r_bins, phi_bins, CV_32SC1);

    //Find the resolution of r and phi
    float diag_len = norm(Point(binary_image.size()));//sqrt(input_image.cols * input.cols + input.rows * input.rows);
    r_step = diag_len / r_bins;
    phi_step = 2 * M_PI / phi_bins;

    //Variable used through-out the function
    float phi = 0, r = 0;

    //Calculate trigonometric look-up tables
    vector<float> sin_table(phi_bins);
    vector<float> cos_table(phi_bins);
    for (int i = 0; i < phi_bins; i++)
    {
        sin_table[i] = sin(phi);
        cos_table[i] = cos(phi);
        phi += phi_step;

    }

    //Populate the bins
    int phi_bin, r_bin;

    //For each row of the input image
    for(int i = 0; i < binary_image.rows; i++)
    {
        //For each column of the input image
        for(int j = 0; j < binary_image.cols; j++)
        {
            //pixel belongs to a line?
            if(binary_image.at<unsigned char>(i, j) == FOREGROUND)
            {
                //for each value along the hough plane phi axis
                for(phi_bin = 0; phi_bin < phi_bins; phi_bin++)
                {
                    r = j * cos_table[phi_bin] + i * sin_table[phi_bin];

                    if(r > 0)
                    {
                        r_bin = (int)(r / r_step);
                        hough_plane.at<int>(r_bin, phi_bin)++;
                    }
                }
           }
        }
    }
}

//Find the peaks in the plane.
//- line_threshold - threshold for the peak intensity
void SudokuImage::CalcHoughPeaks(int line_threshold)
{
    //Threshold the Hough plane
    threshed_plane = Mat(hough_plane.size(), CV_8UC1);
    for(int i = 0; i < hough_plane.rows; i++)
    {
        for(int j = 0; j < hough_plane.cols; j++)
        {
            if(hough_plane.at<int>(i, j) > line_threshold)
            {
                threshed_plane.at<unsigned char>(i, j) = 255;
            }
            else
            {
                threshed_plane.at<unsigned char>(i, j) = 0;
            }
        }
    }

    //Merge peaks close to each other
    int dilation_size = 2;
    Mat element = getStructuringElement(MORPH_ELLIPSE,
                                        Size( 2 * dilation_size + 1, 2 * dilation_size + 1),
                                        Point(dilation_size, dilation_size));
    Mat dilated_plane;
    dilate(threshed_plane, dilated_plane, element);

    //Find the peaks in the hough_plane
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(dilated_plane, contours, hierarchy, CV_RETR_LIST , CV_CHAIN_APPROX_NONE);

    //Find the centres of the peaks
    peak_centers.clear();
    for(unsigned int i = 0; i < contours.size(); i++)
    {
        Point p = Point(0, 0);
        for(unsigned int j = 0; j < contours[i].size(); j++)
        {
            p += contours[i][j];
        }
        p *= 1.0 / contours[i].size();
        peak_centers.push_back(p);
    }
}

//Find the lines defined by the peaks.
void SudokuImage::CalcHoughLines()
{
    //Manage with the cyclic nature of the Hough plane
    //Minimum cyclic distance between two peaks
    int dist_thresh = MIN_PEAK_DIST * norm(Point(hough_plane.size()));
    //For each peak i
    for(unsigned int i = 0; i < peak_centers.size(); i++)
    {
        Point p = peak_centers[i];

        //Has the peak already been merged?
        if(p == Point(-1, -1))
        {
            continue;
        }

        int count = 1;
        float cyclic_dist, dist;
        //For each other peak j
        for(unsigned int j = 0; j < peak_centers.size(); j++)
        {
            //Has the peak already been merged?
            if(j == i || peak_centers[j] == Point(-1, -1)) continue;

            //Calculate the regular and cyclic distance between peak i and peak j
            dist = norm(p - peak_centers[j]);
            if(p.x < peak_centers[j].x)
            {
                cyclic_dist = norm(p - peak_centers[j] + Point(hough_plane.cols, 0));
            }
            else
            {
                cyclic_dist = norm(p - peak_centers[j] - Point(hough_plane.cols, 0));
            }


            //Are the two peaks closer than the min separation distance?
            if(cyclic_dist < dist_thresh || dist < dist_thresh)
            {
                //Merge peaks
                if(dist < cyclic_dist)
                {
                    p += peak_centers[j];
                }
                else
                {
                    p += peak_centers[j] - Point(hough_plane.cols, 0);
                }

                peak_centers[j] = Point(-1, -1);
                count++;
            }
        }
        //Adjust the centre of the merged peaks
        p *= 1.0 / count;

        //Create the corresponding hough line
        Line l;
        l.len = hough_plane.at<int>(p);
        l.phi = p.x * phi_step;
        l.r = p.y * r_step;
        lines.push_back(l);

        //Mark the centre
        threshed_plane.at<unsigned char>(p) = 128;
    }

    //Sort the detected lines:
    // -first 10 are vertical
    // -second 10 are horizontal
    sort(lines.begin(), lines.end(), compare_lines_phi);
    sort(lines.begin(), lines.begin() + 10, compare_lines_r);
    sort(lines.begin() + 10, lines.end(), compare_lines_r);

    //Debug
    //DrawLines(input_image);
}

//-------------- Sudoku extraction routines ------------//
//Calculate the homographic transformation Q.
void SudokuImage::CalcPerspective()
{
    //Find the SUDOKU corners
    int edge_lines[] = {0, 10, 9, 19};
    vector<Point2f> intersections;
    Point2f p;
    for(int i = 0; i < 4; i++)
    {
        if(lines[edge_lines[i]].Intersects(lines[edge_lines[(i + 1) % 4]], p))
        {
            intersections.push_back(p);
        }
    }

    //Debug
    //Mark the corners on the input image
    //for(unsigned int i = 0; i < intersections.size(); i++)
    //{
    //    circle(input_image, intersections[i], 5, Scalar(0, 0, 255), -1);
    //}

    //Find the perspective transfrom to rectify the image
    vector<Point2f> new_intersections;
    new_intersections.push_back(Point2f(0.0f, 0.0f));
    new_intersections.push_back(Point2f(SUDOKU_WIDTH, 0.0f));
    new_intersections.push_back(Point2f(SUDOKU_WIDTH, SUDOKU_HEIGHT));
    new_intersections.push_back(Point2f(0.0f, SUDOKU_HEIGHT));

    Q = getPerspectiveTransform(intersections, new_intersections);
}

//Find the centers of each sudoku cell
void SudokuImage::CalcCellCenters()
{
    //Find the centres of each SUDKOU cell in the input image
    vector<Point2f> intersections;
    Mat centers = Mat(9, 9, CV_32FC2);
    for(int i = 10; i < 20 - 1; i++)
    {
        Point2f p;
        for(int j = 0; j < 10 - 1; j++)
        {
            intersections.clear();
            if(lines[i].Intersects(lines[j], p)) intersections.push_back(p);
            if(lines[i].Intersects(lines[j + 1], p)) intersections.push_back(p);
            if(lines[i + 1].Intersects(lines[j + 1], p)) intersections.push_back(p);
            if(lines[i + 1].Intersects(lines[j], p)) intersections.push_back(p);

            p = Point(0, 0);
            for(unsigned int k = 0; k < intersections.size(); k++)
            {
                p += intersections[k];
            }
            p *= 1.0f / intersections.size();
            centers.at<Vec2f>(i - 10, j) = Vec2f(p.x, p.y);

            //Debug
            //circle(input_image, p, 2, Scalar(255, 255, 0), -1);
        }
    }

    //Find the ransformed centres
    perspectiveTransform(centers, centers, Q);

    //Find the SUDOKU cells rects
    cells.resize(9);
    for(int i = 0; i < centers.rows; i++)
    {
        Vec2f pt;
        for(int j = 0; j < centers.cols; j++)
        {
            pt = centers.at<Vec2f>(i, j);
            Point p = Point((int)pt[0], (int)pt[1]) - 0.5 * Point(CELL_SIZE);
            Rect r = Rect(p, CELL_SIZE);
            cells[i].push_back(r);
        }
    }
}

//Find the cells for each digit
void SudokuImage::CalcCells()
{
    //rectify the SUDOKU image
    warpPerspective(binary_image, rect_sudoku, Q, SUDOKU_SIZE);

    //Calculate the center position of each cell
    CalcCellCenters();

    //Binarize the SUDOKU image
    threshold(rect_sudoku, rect_sudoku, 128, 255, THRESH_BINARY);

    //Remove the SUDOKU grid
    floodFill(rect_sudoku, Point (rect_sudoku.cols / 2, 0), Scalar(0), 0);
    floodFill(rect_sudoku, Point (0, rect_sudoku.rows / 2), Scalar(0), 0);

    //Refine the SUDOKU cells rects so that the digit area is maximized
    for(unsigned int i = 0; i < cells.size(); i++)
    {
        for(unsigned int j = 0; j < cells[i].size(); j++)
        {
            vector<vector<Point> > contours;
            vector<Vec4i> hierarchy;
            findContours(rect_sudoku.clone()(cells[i][j]), contours, hierarchy, CV_RETR_EXTERNAL , CV_CHAIN_APPROX_NONE);
            if(contours.size() > 0)
            {
                Rect r = boundingRect(contours[0]);

                Point offset = Point(7, 7);
                cells[i][j] = Rect(cells[i][j].tl() + r.tl() - offset, r.size() + Size(2 * offset));

                if(cells[i][j].x < 0) cells[i][j].x = 0;
                if(cells[i][j].y < 0) cells[i][j].y = 0;
            }
        }
    }
}

//---------------- Debug functions ---------------------//
//Display the calculated Hough plane.
void SudokuImage::DisplayHoughPlane()
{
    double max_val;
    minMaxLoc(hough_plane, NULL, &max_val);
    Mat image = Mat(hough_plane.size(), CV_8UC1);

    for(int i = 0; i < image.rows; i++)
    {
        for(int j = 0; j < image.cols; j++)
        {
           image.at<unsigned char>(i, j) = (unsigned char)(200 * (hough_plane.at<int>(i, j) / max_val));
        }
    }
    imshow("Hough Plane", image);
}

//Draw the detected lines.
//- image - the image on which the lines are drawn
void SudokuImage::DrawLines(cv::Mat& image)
{
    Point a, b;
    srand(time(NULL));
    for(unsigned int i = 0; i < lines.size(); i++)
    {
        //Avoid dividing by close to zero number
        if(fabs(sin(lines[i].phi)) > 0.01)
        {
            a.x = 0;
            a.y = -a.x / tan(lines[i].phi) + lines[i].r / sin(lines[i].phi);


            b.x = image.cols - 1;
            b.y = -b.x / tan(lines[i].phi) + lines[i].r / sin(lines[i].phi);
        }
        else
        {
            a.x = lines[i].r;
            a.y = 0;

            b.x = lines[i].r;
            b.y = image.rows - 1;
        }
        line(image, a, b, Scalar(rand() % 255, rand() % 255, rand() % 255));
    }
}

//Display the rectified thresholded sudoku with the cells.
void SudokuImage::DisplayRectifiedCells()
{
    Mat image = rect_sudoku.clone();
    for(unsigned int i = 0; i < cells.size(); i++)
    {
        for(unsigned int j = 0; j < cells[i].size(); j++)
        {
            rectangle(image, cells[i][j], Scalar(128));
        }
    }
    imshow("Rectified Cells", image);
}


