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
                               if( Vec3b(ptr[j][0],ptr[j][1],ptr[j][2]) !=  Vec3b(ptref[j][0],ptref[j][1],ptref[j][2]) ){
                                        ptres[j]=Vec3b(ptr[j][0],ptr[j][1],ptr[j][2]);                               
                               }
                               else if(Vec3b(ptr[j][0],ptr[j][1],ptr[j][2]) ==  Vec3b(ptref[j][0],ptref[j][1],ptref[j][2])){
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
