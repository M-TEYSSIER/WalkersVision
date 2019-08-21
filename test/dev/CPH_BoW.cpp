#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int
main (int argc, char *argv[]){

  Mat frame, frame_HSV, frame_threshold, PH;
  frame =imread(argv[1], IMREAD_COLOR);

   PH = frame.clone ();

      cvtColor (frame, frame_HSV, COLOR_BGR2HSV, 0);
      inRange (frame_HSV, Scalar (1, 3, 150), Scalar (9, 147, 240),
	       frame_threshold);

      for (int i = 0; i < PH.rows; i++)
	{
	  for (int j = 0; j < PH.cols; j++)
	    {
	       if (frame_threshold.at < unsigned char >(Point (j, i)) != 255)
		{
		  PH.at < Vec3b > (Point (j, i)) = Vec3b (0, 0, 0);
		}
	    }
	}
      
      Mat ero,dil;
      dilate (PH, dil, Mat (), Point (-1, 1), 1, 1, 1);
      erode (dil, ero, Mat (), Point (-1, 1), 1, 1, 1);

      imshow ("Image Traite", ero);

       waitKey(0); 
  return 0;
}
