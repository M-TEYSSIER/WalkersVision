#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

int i,j,score=150, R,G,B,R1,G1,B1,R2,G2,B2; 

int Calcul(uchar R1,uchar R2,uchar G1,uchar G2,uchar B1,uchar B2){
        int a=sqrt(pow(abs(R1-R2),2)+pow(abs(G1-G2),2)+pow(abs(B1-B2),2));
        return a;
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
                                        R=G=B=0; 
                                       // printf("Mise à 0\n");
                                } else if(score > Calcul(R1,R2,G1,G2,B1,B2)){
                                        R=R1; 
                                        G=G1; 
                                        B=B1; 
                                     //   printf("On laisse les couleurs\n");
                               }
                        }
                }
                imshow("Resultat", resultat);
                imshow("Webcam", webcam);
                if(waitKey(30)>=0){break;}
        }
        cap.release();
        return 0;
}
