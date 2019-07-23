#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Size pattern(7,7);
vector < Point2f > cornersL,cornersR;

bool findChessboardCornersAndDraw(Mat imgR, Mat imgL)
{
        bool foundL=false, foundR=false;
        
        cvtColor(imgL, imgL, COLOR_BGR2GRAY);
        cvtColor(imgR, imgR, COLOR_BGR2GRAY);
        
        foundL=findChessboardCorners(imgL, pattern, cornersL, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE);
        foundR=findChessboardCorners(imgR, pattern, cornersR, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE);
        
        drawChessboardCorners(imgL,pattern,cornersL,foundL);
        drawChessboardCorners(imgR,pattern,cornersR,foundR);

        if(foundL && foundR){return true;}
                else{return false;}
        
}




///////////////////////////////// MAIN ////////////////////////////////
int main (int argc, char **argv)
{
        VideoCapture cam1(atoi (argv[1])), cam2(atoi (argv[2]));
        Mat frameL,frameR; // Creation matrices 
        while(true){
                cam1 >> frameL;
                cam2 >> frameR;
                
                findChessboardCornersAndDraw(frameR,frameL);

                imshow ("Camera L", frameL);
                imshow ("Camera R", frameR);
                if (waitKey (30) >= 0){break;}
        }
        return 0;
}
