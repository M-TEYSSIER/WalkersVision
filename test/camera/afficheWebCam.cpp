#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include <fstream>

using namespace cv;

int g_slider_position = 0;
int g_run = 1;
int g_dontset = 0; 

VideoCapture g_cap;

void onTrackbarSlide(int pos, void *){

        g_cap.set(CAP_PROP_POS_FRAMES, pos);

        if(!g_dontset){
                g_run=1;       
        }
        g_dontset=0;
}

int main(int argc, char** argv){
        namedWindow( "Example2_4", WINDOW_AUTOSIZE );
        g_cap.open( std::string(argv[1]) );

        int frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
        int tmpw = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
        int tmph = (int) g_cap.get(CAP_PROP_FRAME_HEIGHT);

        std::cout << "Video has " << frames << " frames of dimensions("<< tmpw << ", " << tmph << ")." << std::endl;

        createTrackbar("Position", "Example2_4", &g_slider_position, frames,onTrackbarSlide);

        Mat frame;

        for(;;) {
                if( g_run != 0 ) {
                        g_cap >> frame; if(frame.empty()) break;
                        int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
                        g_dontset = 1;

                        setTrackbarPos("Position", "Example2_4", current_pos);
                        imshow( "Example2_4", frame );
                        g_run-=1;
                }

                char c = (char) waitKey(10);
                if( c == 's' ) // single step
                        {g_run = 1; std::cout << "Single step, run = " << g_run << std::endl;}
                if( c == 'r' ) // run mode
                        {g_run = -1; std::cout << "Run mode, run = " << g_run <<std::endl;}
                if( c == 27 )
                        break;
        }
        return(0);
}
