#include <ctime>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

const string IMAGE_FILENAME = "mars_rover.jpg";
const double MIN_DISPLACEMENT = 1;
const int K = 4;

typedef struct Point3D
{
    int x;
    int y;
    int z;

    Point3D() {};
    Point3D(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};

    double DistanceTo(Point3D& p)
    {
        // You should return the distance between this point and point p.
        return -1;
    }
} Point3D;

typedef struct Cluster
{
    Point3D location;
    vector<Point3D> points;

    Cluster() {};
    Cluster(Point3D _location) : location(_location) {};
} Cluster;

// This function returns the index of the closest cluster to point p.
int findClosestCluster(Point3D& p, vector<Cluster>& clusters)
{
    // You should find the closest cluster location to point p and return its index.
    return -1;
}

// This function calculates the new position of the cluster c.
double updateClusterLocation(Cluster& c)
{
    // You should find the new position of the cluster c by
    // calculating the average location of all points assigned to the cluster.

    // The function should return the distance the cluster location has moved.
    return -1;
}

void KMeans(vector<Point3D>& points, vector<Cluster>& clusters, unsigned int K)
{
    // Initialise K clusters with locations randomly selected from points.
    // You can create a new cluster by calling Cluster(location), where
    // location is of type Point3D. Make sure to use different points as
    // cluster centres.

    // Perform K-means iterations. Iterate steps 3 to 5 from the pseudocode
    // until the sum of displacements of all clusters is less than MIN_DISPLACEMENT.
    // The loop should contatin two steps:
    // 1. Assing points to the closest clusters
    // 2. Calculate the new location of each cluster

}

int main()
{
    // Read the input image.
    cv::Mat original_image = cv::imread(IMAGE_FILENAME);
    cv::Mat image = original_image.clone();

    cout << "Size " << image.size() << endl;
    srand(time(NULL));
    vector<Point3D> points;
    vector<Cluster> clusters;

    // Create 3D points from pixels.
    for(int i = 0; i < image.rows; ++i)
    {
        for(int j = 0; j < image.cols; ++j)
        {
            cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
            points.push_back(Point3D(pixel[0], pixel[1], pixel[2]));
        }
    }

    // Run K-means.
    KMeans(points, clusters, K);

    // Replace each pixel in the image with the colour of the closest cluster.
    for(int i = 0; i < image.rows; ++i)
    {
        for(int j = 0; j < image.cols; ++j)
        {
            cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
            Point3D pixel_point(pixel[0], pixel[1], pixel[2]);
            int index = findClosestCluster(pixel_point, clusters);
            pixel_point = clusters[index].location;
            pixel = cv::Vec3b(pixel_point.x, pixel_point.y, pixel_point.z);
            image.at<cv::Vec3b>(i, j) = pixel;
        }
    }

    // Display the images.
    cv::imshow("Original Image", original_image);
    cv::imshow("Compressed Image", image);

    // Save the compressed image.
    cv::imwrite("compressed_image.jpg", image);

    // Display the images until a key is pressed.
    cv::waitKey();

    return 0;
}
