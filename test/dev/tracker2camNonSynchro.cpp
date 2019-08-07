#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>
#include <unistd.h>

#define WINDOW_NAME "Camera"
#define WINDOW_NAME2 "Camera2"
using namespace cv;
using namespace std;
 
int main(int argc, char **argv) {
    Ptr<Tracker> objectTracker, objectTracker2;
    Scalar color = Scalar(0, 165, 255); //Orange
 
    objectTracker = TrackerKCF::create(); //KCF tracker
    objectTracker2 = TrackerKCF::create(); //KCF tracker

    VideoCapture camera(0); //open camera
    VideoCapture camera2(2); //open camera

    //set the video size to 640x480 to process faster
    camera2.set(3, 640);
    camera2.set(4, 480);   
    camera.set(3, 640);
    camera.set(4, 480);

    Mat frame,frame2;
    camera.read(frame);
    camera2.read(frame2);

    Rect2d rect,rect2;
    rect = selectROI(WINDOW_NAME, frame, false);
    rect2 = selectROI(WINDOW_NAME2, frame2, false);

    rectangle(frame, rect, color, 1);
    imshow(WINDOW_NAME, frame);
    rectangle(frame2, rect2, color, 1);
    imshow(WINDOW_NAME2, frame2);

    objectTracker->init(frame, rect);
    objectTracker2->init(frame2, rect2);

    while(camera.read(frame) && camera2.read(frame2)) {
        if (objectTracker->update(frame, rect) && objectTracker2->update(frame2, rect2)) {
            rectangle(frame, rect, color, 1);
            rectangle(frame2, rect2, color, 1);
        }
        cout << "rect: " << rect << "-" << "rect 2:" << rect2 <<endl;
        imshow(WINDOW_NAME, frame);
        imshow(WINDOW_NAME2, frame2);

        if(waitKey(1) == 27){
            //exit if ESC is pressed
            break;
        }
    }

    return 0;
}
