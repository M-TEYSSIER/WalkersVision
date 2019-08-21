#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char ** argv){

        char * imageName = argv[1];
        Mat image;
        image =imread(imageName, IMREAD_COLOR);
        if(argc!=2 || !image.data){
                printf("ERROR");
                return -1;
        }
        Mat gray_image;
        cvtColor(image, gray_image, COLOR_BGR2HSV);
        imshow(imageName, image);
        imshow("Lena HSV", gray_image);

        waitKey(0);

        return 0;



}
