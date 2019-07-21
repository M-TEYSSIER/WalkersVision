#include "opencv2/opencv.hpp" 
 
using namespace cv;
using namespace std;
 
int main( int argc, char** argv)
{
    // Read source image.
    Mat im_dst = imread("./photo.png");
    // Four corners of the book in source image
    vector<Point2f> pts_dst;
    pts_dst.push_back(Point2f(270, 120));
    pts_dst.push_back(Point2f(480, 115));
    pts_dst.push_back(Point2f(500, 393));
    pts_dst.push_back(Point2f(267, 392));
 
 
    // Read destination image.
    Mat im_src = imread("./chessboard.png");
    // Four corners of the book in destination image.
    vector<Point2f> pts_src;
    pts_src.push_back(Point2f(100, 100));
    pts_src.push_back(Point2f(900, 100));
    pts_src.push_back(Point2f(900, 900));
    pts_src.push_back(Point2f(100, 900));
 
    // Calculate Homography
    Mat h = findHomography(pts_src, pts_dst);
 
    // Output image
    Mat im_out;
    // Warp source image to destination based on homography
    warpPerspective(im_src, im_out, h, im_dst.size());
 
    // Display images
    imshow("Source Image", im_src);
    imshow("Destination Image", im_dst);
    imshow("Warped Source Image", im_out);
 
    waitKey(0);
}
