#include "opencv/opencv.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace cv;

int main(int argc, char** argv)
{
    VideoCapture cap(atoi(argv[1]));
       
    if(!cap.isOpened()){ 
        return -1;}

    Mat edges;
    namedWindow("Camera",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; 
        imshow("Camera", frame);
        if(waitKey(30) >= 0) break;
    }
    return 0;
}
