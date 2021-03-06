#include "../opencv/imgproc.hpp"
#include "../opencv/highgui.hpp"
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

int i,j,score=100,R,G,B,R1,G1,B1,R2,G2,B2,Calcul;  

int main(int argc, char **argv){
        VideoCapture cap(atoi(argv[1]));
        Mat webcam, reference, resultat(480,640,CV_8UC3);
//        reference=imread("ref.png");
        cap>> reference;
        while(true){
                cap>>webcam;
                if(!cap.isOpened()){cout << "Error opening video stream or file" << endl;return -1;}
                for(int i=0;i<480;i++){//Rows 
                        Vec3b* ptr = webcam.ptr<Vec3b>(i);
                        Vec3b* ptref = reference.ptr<Vec3b>(i);
                        Vec3b* ptres = resultat.ptr<Vec3b>(i);
                        
                        for(int j=0;j<640;j++){ // Cols
                               R=ptres[j][2];
                               G=ptres[j][1];
                               B=ptres[j][0];
                               R1=ptr[j][2];
                               G1=ptr[j][1];
                               B1=ptr[j][0];
                               R2=ptref[j][2];
                               G2=ptref[j][1];
                               B2=ptref[j][0];
                               Calcul=sqrt(pow(abs(R1-R2),2)+pow(abs(G1-G2),2)+pow(abs(B1-B2),2));
                           //    printf("Calcul: %d -R1: %d - R2: %d -  G1: %d - G2: %d - B1: %d - B2: %d\n",Calcul,R1,R2,G1,G2,B1,B2);
                               if( score < Calcul ){
                                        ptres[j]=Vec3b(ptr[j][0],ptr[j][1],ptr[j][2]);                               
                               }
                               else if(score > Calcul){
                                        ptres[j]=Vec3b(0,0,0);
                               }
                        }
                }
                imshow("Resultat", resultat);
                imshow("Reference", reference);
                imshow("Webcam", webcam);
                if(waitKey(30)>=0){break;}
        }
        cap.release();
        return 0;
}
