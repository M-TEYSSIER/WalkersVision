#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int
main (int argc, char *argv[])
{
  VideoCapture cap (argc > 1 ? atoi (argv[1]) : 0);

  Mat frame, frame_HSV, frame_threshold, PH, ero, dil, diff;

  while (true)
    {
      cap >> frame;
      if (frame.empty ())
	{
	  break;
	}

      PH = frame.clone ();

// ------------------- Recuperation Peau Humaine (BEGIN)  ----------------------
      cvtColor (frame, frame_HSV, COLOR_BGR2HSV, 0);
      inRange (frame_HSV, Scalar (1, 27, 120), Scalar (64, 187, 254),
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
// ------------------- Recuperation Peau Humaine (END)  ------------------------
//                                                                            //
// ------------ Mise en place de Erosion / Dilatation (BEGIN) ------------------
      dilate (PH, dil, Mat (), Point (-1, 1), 1, 1, 1);
      erode (dil, ero, Mat (), Point (-1, 1), 1, 1, 1);
// ------------ Mise en place de Erosion / Dilatation (END) ------------------

//       imshow("Image Traite", ero);
//       imshow("Image Traite", dil);
//       imshow("Image", frame);

      imshow ("Après erode et dilate", ero);

      // Soustraction d'image
      absdiff (frame, ero, diff);

      Mat mask (frame.size (), CV_8UC1);

      for (int j = 0; j < diff.rows; ++j)
	{
	  for (int i = 0; i < diff.cols; ++i)
	    {
	      cv::Vec3b pix = diff.at < cv::Vec3b > (j, i);
	      int val = (pix[0] + pix[1] + pix[2]);
	      if (val > 10)
		{
		  mask.at < unsigned char >(j, i) = 255;
		}
	    }
	}

      // get the foreground
      Mat res;
      bitwise_and (frame, ero, res, mask);

      imshow ("Difference", res);

      char key = (char) waitKey (30);
      if (key == 'q' || key == 27)
	{
	  break;
	}
      if (waitKey (10) == 27)
	{
	  cout << "Esc key is pressed by the user. Stopping the video" <<
	    endl;
	  break;
	}
    }

  return 0;
}
