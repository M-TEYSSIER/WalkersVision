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
  VideoCapture cap (atoi (argv[1]));	//Open the default video camera

  VideoCapture cap2 (atoi (argv[2]));
  if (!cap.isOpened () && !cap2.isOpened ())
    {				// check if we succeeded
      return -1;
    }

  Mat edges;
  namedWindow ("edges", 1);
  Mat edges2;
  namedWindow ("edges2", 1);
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

      Mat frame2;
      cap2 >> frame2;		// get a new frame from camera
      cvtColor (frame2, edges2, COLOR_BGR2GRAY);
      GaussianBlur (frame2, edges2, Size (7, 7), 0, 0);	// Couleurs
      imshow ("edges2", edges2);
      if (waitKey (30) >= 0)
	break;
    }

  return 0;
}
