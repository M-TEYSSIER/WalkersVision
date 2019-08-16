#include "opencv2/opencv.hpp"

using namespace cv;

int main (int argc, char **argv){
  VideoCapture cap (atoi (argv[1])); //Open the default video camera

  if (!cap.isOpened ()){ // check if we succeeded
      return -1;
    }

  Mat edges;
  namedWindow ("edges", 1);
  for (;;)
    {
      Mat frame;
      cap >> frame;		// get a new frame from camera
//      cvtColor (frame, edges, COLOR_BGR2HSV);
//      imshow ("edges", edges);
      imshow ("Webcam", frame);
      if (waitKey (30) >= 0)
	break;
    }
  return 0;
}
