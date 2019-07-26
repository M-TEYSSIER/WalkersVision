#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../opencv/core.hpp"
#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include "../opencv/opencv.hpp"

using namespace cv;

int main (int argc, char **argv){
  VideoCapture cap (2);	

  if (!cap.isOpened ()){return -1;}

  Mat frame, edges;

  while{
      cap >> frame;
      cvtColor (frame, edges, COLOR_BGR2HSV);
      inRange (edges, Scalar (1, 79, 98), Scalar (50, 187, 174), edges);
      imshow ("frame", frame);
      imshow ("edges", edges);
      if (waitKey (30) >= 0){break;}
    }
  return 0;
}
