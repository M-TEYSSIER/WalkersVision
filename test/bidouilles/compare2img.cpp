#include "../opencv/imgcodecs.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
        double alpha = 0.5, beta, input;
        Mat src1, src2,diff;
        src1= imread(argv[1]);
        src2= imread(argv[2]);
        if(src1.empty()){cout<<"ERR src1"<<endl; return -1;}
        if(src2.empty()){cout<<"ERR src2"<<endl; return -1;}
        absdiff(src1,src2,diff);
        imshow("Diff Image", diff);;
        waitKey(0);
        return 0;
}
