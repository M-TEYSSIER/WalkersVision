#include "../opencv/imgcodecs.hpp"
#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

int main(int argc, char **argv){

        VideoCapture cap(atoi(argv[1]));

        double alpha = 0.5, beta, input;
        Mat ref,ref_HSV, ref_F, src2, src2_HSV, src2_F, diff;
        cap >> ref;
        cvtColor(ref,ref_HSV,COLOR_BGR2HSV,0);
        inRange(ref_HSV, Scalar(1, 10, 0), Scalar(46, 127, 255), ref_F);

        while(true){
                cap >> src2;
                cvtColor(src2,src2_HSV,COLOR_BGR2HSV,0);
                inRange(src2_HSV, Scalar(1, 10, 0), Scalar(46, 127, 255), src2_F);

                absdiff(ref_F,src2_F,diff);

                imshow("Image ref",  ref_F);
                imshow("Difference", diff);
                usleep(1000);
                if(waitKey(30) >= 0) ;
        }
        return 0;
}
