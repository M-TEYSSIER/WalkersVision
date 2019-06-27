#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;
int i,j,score=89925,res, R,G,B,R1,G1,B1,R2,G2,B2;
int Calcul(int R1,int R2,int G1, int G2, int B1, int B2){
        sqrt(pow(abs(R1-R2),2)+pow(abs(G1-G2),2)+pow(abs(B1-B2),2));
}
int main(int argc, char **argv){
        VideoCapture cap(atoi(argv[1]));
        Mat webcam, reference, resultat(640,480,CV_8UC3);
        reference=imread("ref.png");
        while(true){
                cap>>webcam;
                if(!cap.isOpened()){cout << "Error opening video stream or file" << endl;return -1;}
                for(int i=0;i<640;i++){// Cols
                        for(int j=0;j<480;j++){ // rows
                                Vec3b colorW=webcam.at<Vec3b>(Point(i,j));// WebCam
                                Vec3b colorF=reference.at<Vec3b>(Point(i,j));// Ref
                                Vec3b colorS=resultat.at<Vec3b>(Point(i,j));// Res

                                R = colorS[2];
                                G = colorS[1];
                                B = colorS[0];
                                R1 = colorW[2];
                                G1 = colorW[1];
                                B1 = colorW[0];
                                R2 = colorF[2];
                                G2 = colorF[1];
                                B2 = colorF[0];
                               if(score < Calcul(R1,R2,G1,G2,B1,B2)){
                                        R=G=B=200; 
                                        printf("LOOOL");
                                } else{
                                        R=colorW[2]; 
                                        G=colorW[1]; 
                                        B=colorW[0]; 
                                }
                        }
                }
                imshow("Final",resultat);
                if(waitKey(30)>=0){break;}
        }
        cap.release();
        return 0;
}
