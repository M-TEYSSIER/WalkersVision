#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int
main (int argc, char *argv[])
{
  VideoCapture cap (argc > 1 ? atoi (argv[1]) : 0);

  Mat frame, frame_HSV, frame_threshold, PH;

  int frame_width = static_cast < int >(cap.get (CAP_PROP_FRAME_WIDTH));	//get the width of frames of the video
  int frame_height = static_cast < int >(cap.get (CAP_PROP_FRAME_HEIGHT));	//get the height of frames of the video

  Size frame_size (frame_width, frame_height);

  int frames_per_second = 10;

  //Create and initialize the VideoWriter object 
  VideoWriter oVideoWriter ("./Video.avi",
			    VideoWriter::fourcc ('M', 'J', 'P', 'G'),
			    frames_per_second, frame_size, true);

  //If the VideoWriter object is not initialized successfully, exit the program
  if (oVideoWriter.isOpened () == false)
    {
      cout << "Cannot save the video to a file" << endl;
      cin.get ();		//wait for any key press
      return -1;
    }

  string window_name = "My Camera Feed";
  namedWindow (window_name);	//create a window called "My Camera Feed"



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
      //inRange(frame_HSV, Scalar(1, 7, 120), Scalar(46, 147, 250), frame_threshold);
      inRange (frame_HSV, Scalar (0, 7, 150), Scalar (55, 147, 240),
	       frame_threshold);

      for (int i = 0; i < PH.rows; i++)
	{
	  for (int j = 0; j < PH.cols; j++)
	    {
	      F if (frame_threshold.at < unsigned char >(Point (j, i)) != 255)
		{
		  PH.at < Vec3b > (Point (j, i)) = Vec3b (0, 0, 0);
		}
	    }
	}
// ------------------- Recuperation Peau Humaine (END)  ------------------------
//                                                                            //
// ------------ Mise en place de Erosion / Dilatation (BEGIN) ------------------
      Mat ero, dil;

      dilate (PH, dil, Mat (), Point (-1, 1), 1, 1, 1);
      erode (dil, ero, Mat (), Point (-1, 1), 1, 1, 1);

// ------------ Mise en place de Erosion / Dilatation (END) ------------------


      imshow ("Image Traite", ero);
      imshow ("Image", frame);

      char key = (char) waitKey (30);
      if (key == 'q' || key == 27)
	{
	  break;
	}

      bool isSuccess = cap.read (frame);	// read a new frame from the video camera

      if (isSuccess == false)
	{
	  cout << "Video camera is disconnected" << endl;
	  cin.get ();		//Wait for any key press
	  break;
	}

      oVideoWriter.write (dil);
      oVideoWriter.write (frame);
      imshow (window_name, frame);

      if (waitKey (10) == 27)
	{
	  cout << "Esc key is pressed by the user. Stopping the video" <<
	    endl;
	  break;
	}

    }

  oVideoWriter.release ();
  return 0;
}
