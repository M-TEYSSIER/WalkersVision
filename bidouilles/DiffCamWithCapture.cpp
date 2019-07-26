#include "../opencv/opencv.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../opencv/core.hpp"
#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"

using namespace cv;

int main (int argc, char **argv){
  VideoCapture cap (2);
  if (!cap.isOpened ()){return -1;}

  Mat edges,frame;
    while(true){
      cap >> frame;
      cvtColor (frame, edges, COLOR_BGR2HSV);
      edges = frame - edges;
      imwrite ("test.png", frame);
      imshow ("frame", frame);
      imshow ("edges", edges);
      if (waitKey (30) >= 0){break;}
    }

  return 0;
}
