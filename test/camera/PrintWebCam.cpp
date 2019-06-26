#include "../opencv/opencv.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../opencv/core.hpp"
#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"

using namespace cv;

int
main (int argc, char **argv)
{
  VideoCapture cap (0);		//Open the default video camera

  if (!cap.isOpened ())
    {				// check if we succeeded
      return -1;
    }

  Mat edges;
  namedWindow ("edges", 1);
  for (;;)
    {
      Mat frame;
      cap >> frame;		// get a new frame from camera
      cvtColor (frame, edges, COLOR_BGR2GRAY);
      GaussianBlur (frame, edges, Size (7, 7), 0, 0);	// Couleurs
//        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5); // Gris
//        Canny(edges, edges, 0, 30, 3); // 
      imshow ("edges", edges);
      if (waitKey (30) >= 0)
	break;
    }
  // the camera will be deinitialized automatically in VideoCapture destructor
  return 0;
}
