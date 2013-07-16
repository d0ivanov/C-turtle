#ifndef SUDOKUIMAGE_H
#define SUDOKUIMAGE_H

#include <ctime>
#include <opencv2/opencv.hpp>

#include "Sudoku.h"
#include "HoughLine.h"

//Thresholding constants
#define BACKGROUND 0
#define FOREGROUND 255

#define LINE_THRESHOLD  0.38
#define PHI_BINS        1440 //4 * 360
#define MIN_PEAK_DIST   0.01

class SudokuImage
{
    public:
         SudokuImage(std::string filepath);
        ~SudokuImage();

        //Return and image with the digit in a specified cell
        //- row - the row of the cell (0=top)
        //- col - the columnt of the cell (0=left)
        //- sz  - the size of the returned image
        cv::Mat GetDigit(int row, int col, cv::Size sz);

        //Display the solution
        //- s - the sudoku to be displayed
        cv::Mat DrawSolution(const Sudoku& s);

    private:
        cv::Mat input_image;    //original sudoku image
        cv::Mat binary_image;   //thresholded original image
        cv::Mat rect_sudoku;    //perspective rectified original image

        cv::Mat hough_plane;    //constructed Hough plane
        cv::Mat threshed_plane; //thresholded Hough plane
        float phi_step;         //angle step in the Hough plane
        float r_step;           //distance step in the Hough plane
        cv::Mat Q;              //perspective transform matrix

        std::vector<cv::Point> peak_centers;        //centers of the peaks in the Hough plane
        std::vector<Line> lines;                    //found Hough lines
        std::vector<std::vector <cv::Rect> > cells; //position and size of each cell in the rectified sudoku image

        //------------------- Image routines -------------------//
        //Preprocess the input image. Apply adaptive thresholding.
        void PreprocessImage();
        //Postprocess the input image. Thin out the digits.
        void PostprocessImage();

        //--------------- Hough transform routines -------------//
        //Calculate the hough plane.
        //- phi_bins - number of angle bins
        //- r_bins - number of distance bins
        void CalcHoughPlane(int phi_bins, int r_bins);
        //Find the peaks in the plane.
        //- line_threshold - threshold for the peak intensity
        void CalcHoughPeaks(int line_threshold);
        //Find the lines defined by the peaks.
        void CalcHoughLines();

        //-------------- Sudoku extraction routines ------------//
        //Calculate the homographic transformation Q.
        void CalcPerspective();
        //Find the centers of each sudoku cell
        void CalcCellCenters();
        //Find the cells for each digit
        void CalcCells();

        //---------------- Debug functions ---------------------//
        //Display the calculated Hough plane.
        void DisplayHoughPlane();
        //Draw the detected lines.
        //- image - the image on which the lines are drawn
        void DrawLines(cv::Mat& image);
        //Display the rectified thresholded sudoku with the cells.
        void DisplayRectifiedCells();
};

#endif
