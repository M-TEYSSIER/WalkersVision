#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "../opencv/core.hpp"
#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include "../opencv/opencv.hpp"

using namespace cv;

int main(int argc, char** argv)
{
    VideoCapture cap(2); //Open the default video camera
       
    if(!cap.isOpened()){  // check if we succeeded
        return -1;}

    Mat frame, edges;

    for(;;)
    { 
        cap >> frame; // get a new frame from camera

        cvtColor(frame, edges, COLOR_BGR2HSV);
        
//        imwrite("test.png",frame); Faire une photo

        //Mat res;
        //substract(frame, edges,res);
        
        inRange(edges, Scalar(1, 79, 98), Scalar(50, 187, 174), edges);

        imshow("frame", frame);
        imshow("edges", edges);

        if(waitKey(30) >= 0) break;

    }

    return 0;
}
