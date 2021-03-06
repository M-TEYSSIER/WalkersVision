#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int
main (int argc, char *argv[])
{
  VideoCapture cap (argc > 1 ? atoi (argv[1]) : 0);
  Mat frame, frame_HSV, frame_threshold, PH,ero,dil;

  int frame_width = static_cast < int >(cap.get (CAP_PROP_FRAME_WIDTH));	//get the width of frames of the video
  int frame_height = static_cast < int >(cap.get (CAP_PROP_FRAME_HEIGHT));	//get the height of frames of the video
  Size frame_size (frame_width, frame_height);
  int frames_per_second = 10;

  VideoWriter oVideoWriter ("./Video.avi",VideoWriter::fourcc ('M', 'J', 'P', 'G'),frames_per_second, frame_size, true);

  if (oVideoWriter.isOpened () == false){
      cout << "Cannot save the video to a file" << endl;
      cin.get ();		//wait for any key press
      return -1;
    }

  string window_name = "My Camera Feed";
  namedWindow (window_name);	//create a window called "My Camera Feed"

  while (true){
      cap >> frame;
      if (frame.empty ()){break;}

      PH = frame.clone ();

// ------------------- Recuperation Peau Humaine (BEGIN)  ----------------------
      cvtColor (frame, frame_HSV, COLOR_BGR2HSV, 0);
      inRange (frame_HSV, Scalar (1, 8, 20), Scalar (46, 137, 200),frame_threshold);

      for (int i = 0; i < PH.rows; i++){
	  for (int j = 0; j < PH.cols; j++){
	      if (frame_threshold.at < unsigned char >(Point (j, i)) != 255){
		  PH.at < Vec3b > (Point (j, i)) = Vec3b (0, 0, 0);
		}
	    }
	}
// ------------------- Recuperation Peau Humaine (END)  ------------------------
//                                                                            //
// ------------ Mise en place de Erosion / Dilatation (BEGIN) ------------------
      erode (PH, ero, Mat (), Point (-1, 1), 1, 1, 1);
      dilate (ero, dil, Mat (), Point (-1, 1), 1, 1, 1);
      erode (dil, ero, Mat (), Point (-1, 1), 1, 1, 1);
      dilate (ero, dil, Mat (), Point (-1, 1), 1, 1, 1);
// ------------ Mise en place de Erosion / Dilatation (END) ------------------
      imshow ("Image Traite", dil);
      char key = (char) waitKey (30);
      if (key == 'q' || key == 27){break;}
      bool isSuccess = cap.read (frame);
      if (isSuccess == false){
	  cout << "Video camera is disconnected" << endl;
	  cin.get();
	  break;
	}

      oVideoWriter.write (dil);
      imshow (window_name, frame);

      if (waitKey (10) == 27){
	  cout << "Esc key is pressed by the user. Stopping the video" <<endl;
	  break;
	}
    }

  oVideoWriter.release ();
  return 0;
}
