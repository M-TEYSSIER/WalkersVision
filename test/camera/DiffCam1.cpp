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
  VideoCapture cap (2);		//Open the default video camera

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
      cvtColor (frame, edges, COLOR_BGR2HSV);

      //    edges= frame - edges;

      inRange (edges, Scalar (1, 79, 98), Scalar (32, 127, 174), edges);

      imshow ("frame", frame);
      imshow ("edges", edges);

      if (waitKey (30) >= 0)
	break;

    }

  return 0;
}
