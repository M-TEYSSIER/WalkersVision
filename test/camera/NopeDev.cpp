#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;

int Calcul(int R1,int R2,int G1, int G2, int B1, int B2){
        sqrt(pow(abs(R1-R2),2)+pow(abs(G1-G2),2)+pow(abs(B1-B2),2));
}

int i,j,score=89925,res;
uchar R,G,B,R1,G1,B1,R2,G2,B2;

int test=0;

int main (int argc, char **argv){

        VideoCapture cap (argc > 1 ? atoi (argv[1]) : 0); 
        Mat frame_ref=imread("ImageRef.png"), frame_base, frame_res(640,480, CV_8UC3,Scalar(0,0,0)); 
        
        while (true){
                cap >> frame_base; 
               if (frame_base.empty () ){break;} 
                for (i = 0; i < frame_base.rows; i++){
                        for (j = 0; j < frame_base.cols; j++){

                                R = frame_res.at<Vec3b>(i,j)[2];  
                                G = frame_res.at<Vec3b>(i,j)[1]; 
                                B = frame_res.at<Vec3b>(i,j)[0]; 
                                R1 = frame_base.at<Vec3b>(j,i)[2]; 
                                G1 = frame_base.at<Vec3b>(j,i)[1];  
                                B1 = frame_base.at<Vec3b>(j,i)[0]; 
                                R2 = frame_ref.at<Vec3b>(j,i)[2];  
                                G2 = frame_ref.at<Vec3b>(j,i)[1];   
                                B2 = frame_ref.at<Vec3b>(j,i)[0]; 

                                        printf("OOOsiris");
                                if(score < Calcul(R1,R2,G1,G2,B1,B2)){
                                        R=G=B=0; 
                                        printf("LOOOL");
                                } else{
                                        R=frame_base.at<Vec3b>(i,j).val[2]; 
                                        G=frame_base.at<Vec3b>(i,j).val[1]; 
                                        B=frame_base.at<Vec3b>(i,j).val[0]; 
                                }
                        }
                }
//                imshow("OSIRIS", frame_res);
                if(waitKey (30) >= 0){break;}
        }
        cap.release();
        return 0;
}

/*
printf("0: %d ", frame_base.at<Vec3b>(i,j).val[0]);
printf("1: %d ", frame_base.at<Vec3b>(i,j).val[1]);
printf("2: %d\n", frame_base.at<Vec3b>(i,j).val[2]);
printf("3: %d ", frame_ref.at<Vec3b>(i,j).val[0]);
printf("4: %d ", frame_ref.at<Vec3b>(i,j).val[1]);
printf("5: %d\n", frame_ref.at<Vec3b>(i,j).val[2]); 
printf("6: %d ", frame_res.at<Vec3b>(i,j).val[0]);
printf("7: %d ", frame_res.at<Vec3b>(i,j).val[1]);
printf("8: %d\n", frame_res.at<Vec3b>(i,j).val[2]); 
        frame_ref=imread("ImageRef.png");
*/
