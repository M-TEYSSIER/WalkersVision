#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

Mat frame,fgMaskMOG2; 
Ptr<BackgroundSubtractor> pMOG2; 
int keyboard; 

static void CannyThreshold(Mat src_gray){
    blur( src_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    src.copyTo( dst, detected_edges);
    imshow( window_name, dst );
}

void processWcam(char* NumberOfWebcam);

void processWcam(char* videoFilename){
    VideoCapture capture(atoi(videoFilename));

    if(!capture.isOpened()){exit(EXIT_FAILURE);}
    
    while( (char)keyboard != 'q'  && (char)keyboard != 27 ){
        if(!capture.read(frame)) {exit(EXIT_FAILURE);}
        GaussianBlur(frame,frame,Size(5,5),0,0);
        GaussianBlur(frame,frame,Size(5,5),0,0);
        pMOG2->apply(frame, fgMaskMOG2);
        stringstream ss;

        imshow("Frame", frame);
        imshow("FG Mask MOG 2", fgMaskMOG2);
        CannyThreshold(fgMaskMOG2);
        keyboard = waitKey(30);
    }
    capture.release();
}

int main(int argc, char* argv[]){
        while(true){
            pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 approach
            processWcam(argv[1]);
            destroyAllWindows();
            return EXIT_SUCCESS;
        }
}
