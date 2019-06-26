#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;


int
main (int argc, char *argv[])
{
  VideoCapture cap (argc > 1 ? atoi (argv[1]) : 0);

  Mat frame, frame_HSV, frame_threshold;
  Mat test;;

  while (true)
    {
      cap >> frame;
      if (frame.empty ())
	{
	  break;
	}

      test = frame.clone ();

      cvtColor (frame, frame_HSV, COLOR_BGR2HSV, 0);
      inRange (frame_HSV, Scalar (1, 3, 130), Scalar (46, 127, 245),
	       frame_threshold);


      for (int i = 0; i < test.rows; i++)
	{			// NbRow = 480 (0-479)
	  for (int j = 0; j < test.cols; j++)
	    {			// NbCols = 640 (0-639)
	      //printf("Row: %d -- Cols:%d -- Values: %d\n",i,j,frame_threshold.data[i,j]);
	      // Value => (0 <- threshold -> 255)
	      if (frame_threshold.at < unsigned char >(Point (j, i)) != 255)
		{
		  test.at < Vec3b > (Point (j, i)) = Vec3b (0, 0, 0);
		}
	    }
	}

      imshow ("OSIRIIIIIIIIIIIIIIIIIIIIIIIStest", test);
//        imshow("OSIRIIIIIIIIIIIIIIIIIIIIIIISframe", frame);
//        imshow("OSIRIIIIIIIIIIIIIIIIIIIIIIISft", frame_threshold);

      char key = (char) waitKey (30);
      if (key == 'q' || key == 27)
	{
	  break;
	}
    }
  return 0;
}
