#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char ** argv){
        
        Mat image, hsv_image,threshold_image, PH(Size(image.cols,image.rows),CV_8UC3);
        image =imread(argv[1]);

        if(argc!=2 || !image.data){ printf("ERROR"); return -1;}
        
        cvtColor(image, hsv_image, COLOR_BGR2HSV); 
        
        inRange (hsv_image, Scalar (0, 7, 150), Scalar (55, 147, 240),
	       threshold_image);
        
        for (int i = 0; i < PH.rows; i++){
	        for (int j = 0; j < PH.cols; j++){
	            if (threshold_image.at < unsigned char >(Point (j, i)) != 255){
		            PH.at < Vec3b > (Point (j, i)) = Vec3b (0, 0, 0);
		        }
	        }
	    }
	
        imshow("Lena.png", image);
        imshow("Lena HSV capture peau humaine", PH);
        waitKey(0);
        return 0;
} 
