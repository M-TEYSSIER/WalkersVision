#include "../opencv/core.hpp"
#include "../opencv/imgcodecs.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], IMREAD_GRAYSCALE);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}

//        image = imread(imageName, IMREAD_COLOR);
//        image = imread(imageName, IMREAD_UNCHANGED);
//        image = imread(imageName, IMREAD_GRAYSCALE);

