#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int y=0;

int main (int argc, char *argv[])
{
  // Declaration de Matrices
  Mat frame,frame_base, frame_HSV, frame_threshold, PH, ero, dil, diff, res;

  VideoCapture cap (argc > 1 ? atoi (argv[1]) : 0);
  cap >> frame_base;
  while (true)
    {
      // ----------------------- Recuperation video (BEGIN) --------------------------
      cap >> frame;
      if (frame.empty () ){break;}
      imshow("Fenetre",frame);
      // ------------------------ Recuperation video (END) ---------------------------
      ////////////////////////////////////////////////////////////////////////////////
      // ------------------- Recuperation Peau Humaine (BEGIN)  ----------------------
      cvtColor (frame, frame_HSV, COLOR_BGR2HSV, 0);
      inRange (frame_HSV, Scalar (1, 27, 120), Scalar (64, 187, 254),frame_threshold);
      PH = frame.clone ();
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
      ////////////////////////////////////////////////////////////////////////////////
      // ------------ Mise en place de Erosion / Dilatation (BEGIN) ------------------
      dilate (PH, dil, Mat (), Point (-1, 1), 1, 1, 1);
      erode (dil, ero, Mat (), Point (-1, 1), 1, 1, 1); 
      // ------------ Mise en place de Erosion / Dilatation (END) --------------------
      ////////////////////////////////////////////////////////////////////////////////
      // ---------------- Difference ImageRef | ImageModif (BEGIN) -------------------
      absdiff(ero, frame_base, res); // Soustraction image de ref et image DilEro
      imshow ("Difference entre Ref / EroDil", res);
      // ---------------- Difference ImageRef | ImageModif (END) ---------------------
      ////////////////////////////////////////////////////////////////////////////////
      if (waitKey (30) >= 0){break;}
    }
  return 0;
}
