#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

int Calcul(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f ){
        int A,B,C,D,E,F,r;
        A = (int) a ; 
        B = (int) b ;
        C = (int) c ;
        D = (int) d ;
        E = (int) e ;
        F = (int) f ;
        r=abs((B-E)+(C-F));
        if ((A>3) && (A<14) && (B>40) && (B<190) && (C>100) && (C<250) && (A-D<10) && (B-E<10) && (C-F<10) ){ 
                return r;
        } else {
                r=0;
        }
}

int main(int argc, char **argv){
        int renew=0;
        unsigned char R,G,B,H1,S1,V1,H,S,V,Res,Bes,Ges;  
        VideoCapture cap(atoi(argv[1]));
        Mat webcam, whsv(480,640,CV_8UC3), reference,rhsv(480,640,CV_8UC3), resultat(480,640,CV_8UC3), ero,dil;
        cap>>reference;
        cvtColor(reference,rhsv,COLOR_BGR2HSV);// Passage HSV

        while(true){
                while(renew==2){  
                        cap>>reference;
                        GaussianBlur(reference,reference,Size(5,5),0,0);
                        GaussianBlur(reference,reference,Size(5,5),0,0);
                        GaussianBlur(reference,reference,Size(5,5),0,0);
                        erode(reference,reference,Mat(),Point(1,1),2,1);
                        cvtColor(reference,rhsv,COLOR_BGR2HSV);// Passage HSV
                        renew=0;
                }
                cap>>webcam;
                GaussianBlur(webcam,webcam,Size(5,5),0,0);
                GaussianBlur(webcam,webcam,Size(5,5),0,0);
                GaussianBlur(webcam,webcam,Size(5,5),0,0);
                cvtColor(webcam,whsv,COLOR_BGR2HSV); // Passage HSV
                if(!cap.isOpened()){cout << "Error opening video stream or file" << endl;return -1;}
                for(int i=0;i<480; i++){// Rows 
                        Vec3b *ptr = webcam.ptr<Vec3b>(i) ; // WebCam
                        Vec3b *ptrwhsv = whsv.ptr<Vec3b>(i) ; // Webcam HSV
                        Vec3b *ptrrhsv = rhsv.ptr<Vec3b>(i) ; // Reference HSV
                        Vec3b *ptres = resultat.ptr<Vec3b>(i) ; // Resultat
                        for(int j=0;j<640;j++){ // Cols
                               H=ptrwhsv[j](0); // h webcam 
                               S=ptrwhsv[j](1); // s webcam
                               V=ptrwhsv[j](2); // v webcam
                              H1=ptrrhsv[j](0); // H reference
                              S1=ptrrhsv[j](1); // S reference
                              V1=ptrrhsv[j](2); // V reference
                               int A= Calcul(H,S,V,H1,S1,V1); 
                               if( A>1) {
                                       ptres[j](0)=ptr[j](0);
                                       ptres[j](1)=ptr[j](1);
                                       ptres[j](2)=ptr[j](2);
                               }else{ // Sinon pixel -> Noir
                                       ptres[j](0)=0;
                                       ptres[j](1)=0;
                                       ptres[j](2)=0;
                               }
                        }
                }
                 vector<Vec4i> hierarchy;
                 vector<vector<Point>> contours;
               
               Mat resultat_canny=resultat.clone();
               Canny(resultat,resultat_canny,100,200,3);
               findContours(resultat_canny,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0)) ; 
               rectangle(resultat,Point(200,480),Point(430,380),Scalar(255),2,8,0);
//               imshow("Reference", rhsv);
               imshow("Resultat", resultat);
                if(waitKey(30)>=0){break;}
                renew++;
        }
        cap.release();
        return 0;
}
