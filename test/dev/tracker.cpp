#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>
#include <unistd.h>

#define WINDOW_NAME "Camera"
using namespace cv;
using namespace std;
 
int main(int argc, char **argv) {
    Ptr<Tracker> objectTracker;
    Scalar color = Scalar(0, 165, 255); //Orange
 
    objectTracker = TrackerKCF::create(); //KCF tracker

    VideoCapture camera(0); //open camera

    //set the video size to 640x480 to process faster
    camera.set(3, 640);
    camera.set(4, 480);

    sleep(3);

    Mat frame;
    camera.read(frame);

    Rect2d rect;
    rect = selectROI(WINDOW_NAME, frame, false);

    rectangle(frame, rect, color, 1);
    imshow(WINDOW_NAME, frame);

    objectTracker->init(frame, rect);

    while(camera.read(frame)) {
        if (objectTracker->update(frame, rect)) {
            rectangle(frame, rect, color, 1);
        }
        cout << rect  <<endl;
        imshow(WINDOW_NAME, frame);

        if(waitKey(1) == 27){
            //exit if ESC is pressed
            break;
        }
    }

    return 0;
}
