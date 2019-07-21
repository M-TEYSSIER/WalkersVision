#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char * argv[]) {
        Size patternsize(atoi(argv[2]),atoi(argv[3]));	//number of centers
	Mat frame,frame2;
        VideoCapture cap(atoi(argv[1]));        
        VideoCapture cap2(atoi(argv[2]));        
        if (!cap.isOpened ()){return -1;}
	vector < Point2f > centers;
	while (1) {
                cap>>frame;
                cap2>>frame2;

                bool patternfound = findChessboardCorners(frame, patternsize, centers);
                drawChessboardCorners(frame, patternsize, Mat(centers),patternfound);

                bool found = findCirclesGrid(frame, Size(12,8), centers);
                drawChessboardCorners(frame, Size(12,8), Mat(centers),found);

                bool Foundamantal= findFundamentalMat(frame,frame2);
                drawChessboardCorners(frame2, Size(12,8), Mat(centers),found);
       
cv::Mat pnts3D(1,N,CV_64FC4);
cv::Mat cam0pnts(1,N,CV_64FC2);
cv::Mat cam1pnts(1,N,CV_64FC2);
cv::triangulatePoints(frame,frame2,cam0pnts,cam1pnts,pnts3D);


                cvNamedWindow("window");
                cvNamedWindow("window2");
		imshow("window", frame);
		imshow("window2", frame2);
		cvWaitKey(33);
	}
}
