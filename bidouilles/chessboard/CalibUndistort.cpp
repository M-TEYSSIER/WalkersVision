#include <opencv2/opencv.hpp>
#include <opencv2/cv.h>
#include <fstream>
#include <opencv2/highgui.h>

using namespace cv;
using namespace std;

int main()
{
    int numBoards = 0;
    int numCornersHor;
    int numCornersVer;

    printf("Enter number of corners along width: ");
    scanf("%d", &numCornersHor);

    printf("Enter number of corners along height: ");
    scanf("%d", &numCornersVer);

    printf("Enter number of boards: ");
    scanf("%d", &numBoards);
    
    int numSquares = numCornersHor * numCornersVer;
    Size board_sz = Size(numCornersHor, numCornersVer);
   
    VideoCapture capture = VideoCapture(0);
    
    vector < vector < Point3f >> object_points;
    vector < vector < Point2f >> image_points;
   
    vector < Point2f > corners;
    int successes = 0;
    
    Mat image;
    Mat gray_image;
    capture >> image;
    
    vector < Point3f > obj;
    for (int j = 0; j < numSquares; j++)
	obj.push_back(Point3f(j / numCornersHor, j % numCornersHor, 0.0f));
    
    while (successes < numBoards) {
        cvtColor(image, gray_image, CV_BGR2GRAY);
        bool found = findChessboardCorners(image, board_sz, corners,
					   CALIB_CB_ADAPTIVE_THRESH |
					   CALIB_CB_FILTER_QUADS);

	if (found) {
	    cornerSubPix(gray_image, corners, Size(11, 11), Size(-1, -1),
			 TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER,
				      30, 0.1));
	    drawChessboardCorners(gray_image, board_sz, corners, found);
	}

	imshow("win1", image);
	imshow("win2", gray_image);

	capture >> image;
	int key = waitKey(1);
	if (key == 27)
	    return 0;

	if (key == ' ' && found != 0) {
	    image_points.push_back(corners);
	    object_points.push_back(obj);

	    printf("Snap stored!");

	    successes++;

	    if (successes >= numBoards)
		break;
	}
    }

    Mat intrinsic = Mat(3, 3, CV_32FC1);
    Mat distCoeffs;
    vector < Mat > rvecs;
    vector < Mat > tvecs;
    intrinsic.ptr < float >(0)[0] = 1;
    intrinsic.ptr < float >(1)[1] = 1;
    calibrateCamera(object_points, image_points, image.size(), intrinsic,
		    distCoeffs, rvecs, tvecs);
// Probleme de sauvegarde
/*    bool saveCameraCalibration(string fname, Mat cameraMatrix, Mat distorceCoefiientes){
                ofstream outStream(fname);
                if (outStream) {
                        uint16_t rows = cameraMatrix.rows;
                        uint16_t cols = cameraMatrix.cols;

                        for (int r = 0; r < rows; r++) {
                                for (int c = 0; c < cols; c++) {
                                        double value = cameraMatrix.at<double>(r, c);
                                        outStream << value << endl;
                                }
                        }

                        rows = distorceCoefiientes.rows;
                        cols = distorceCoefiientes.cols;

                        for (int r = 0; r < rows; r++) {
                                for (int c = 0; c < cols; c++) {
                                        double value = distorceCoefiientes.at<double>(r, c);
                                        outStream << value << endl;
                                }
                        }
                outStream.close();
                return true;
                }
        return false;
        }*/

    Mat imageUndistorted;
    while (1) {
	capture >> image;
	undistort(image, imageUndistorted, intrinsic, distCoeffs);

	imshow("win1", image);
	imshow("win2", imageUndistorted);
	waitKey(1);
    }
    capture.release();

    return 0;
}
