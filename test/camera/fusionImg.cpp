#include "../opencv/imgcodecs.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include "../opencv/opencv.hpp"

using namespace cv;
using namespace std;

int
main (int argc, char **argv)
{

  double alpha = 0.5, beta, input;
  Mat src1, src2, dst;
  cout << "Entrer valeur:" << endl;
  cin >> input;

  VideoCapture cap1 (atoi (argv[1]));	//Open the default video camera
  if (!cap1.isOpened ())
    {				// check if we succeeded
      return -1;
    }
  VideoCapture cap2 (atoi (argv[2]));	//Open the default video camera
  if (!cap2.isOpened ())
    {				// check if we succeeded
      return -1;
    }


  Mat edges1;
  namedWindow ("edges1", 1);
  Mat edges2;
  namedWindow ("edges2", 1);


  if (input >= 0 && input <= 1)
    {
      alpha = input;
    }
  for (;;)
    {

      Mat frame1;
      cap1 >> frame1;
      cvtColor (frame1, edges1, COLOR_BGR2GRAY);
      Mat frame2;
      cap2 >> frame2;
      cvtColor (frame2, edges2, COLOR_BGR2GRAY);



//                src1= imread(src1);
//                src2= imread(src2);

      //              if(cap1.empty()){cout<<"ERR src1"<<endl; return -1;}
//                if(cap2.empty()){cout<<"ERR src2"<<endl; return -1;}

      beta = (1.0 - alpha);
      addWeighted (cap1, alpha, cap2, beta, 0.0, dst);
      imshow ("Linear Blend", dst);
      cvtColor (dst, dst, COLOR_BGR2GRAY);
      waitKey (0);
    }
  return 0;
}
