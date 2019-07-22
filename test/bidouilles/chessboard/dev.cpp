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
        VideoCapture cap(atoi(argv[1]));        
	if (!cap.isOpened ()){return -1;}

        Size patternsize1(atoi(argv[2]),atoi(argv[3]));	//number of centers
	Size patternsize2(atoi(argv[4]),atoi(argv[5]));
	Mat frame, frame2;
	vector < Point2f > centers, centers2;
	
	while (1) {
                cap>>frame; cap>>frame2;

                bool patternfound = findChessboardCorners(frame, patternsize1, centers);
                drawChessboardCorners(frame, patternsize1, Mat(centers),patternfound);

		// Probleme avec le cercle en vertical (ex: 8x12, les reperes pop à cotés)
                bool found = findCirclesGrid(frame2, patternsize2, centers2);
                drawChessboardCorners(frame2, patternsize2, Mat(centers2),found);

		imshow("Carres", frame);
		imshow("Cercles", frame2);
		if(waitKey(33)>=0){break;};
	}
	return 0;
}
