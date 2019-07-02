#include "../../opencv/imgproc.hpp"
#include "../../opencv/highgui.hpp"
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

        if ((A>1) && (A<50) && (B>70) && (B<150) && (C>50) && (C<250) && (A!=D) && (B!=E) && (C!=F) ){
                r=0;
        } else {
                r=1;
        }
        return r;
}

int main(int argc, char **argv){
        int renew=0;
        unsigned char R,G,B,H1,S1,V1,H,S,V,Res,Bes,Ges;  
        VideoCapture cap(atoi(argv[1]));

        Mat webcam, whsv(480,640,CV_8UC3), reference,rhsv(480,640,CV_8UC3), resultat(480,640,CV_8UC3), ero,dil;

        /////////// Capture de l image de reference ! ////////////////
        cap>>reference;
        cvtColor(reference,rhsv,COLOR_BGR2HSV);// Passage HSV
        //////////////////////////////////////////////////////////////

        while(true){
                while(renew==200){ // Permet de rafraichir l image de reference (10s)
                        cap>>reference;
                        renew=0;
                }
                
                ////////// Capture frame en continu ////////////////////////
                cap>>webcam;
                cvtColor(webcam,whsv,COLOR_BGR2HSV); // Passage HSV
                ////////////////////////////////////////////////////////////                

                if(!cap.isOpened()){cout << "Error opening video stream or file" << endl;return -1;}

                for(int i=0;i<480; i++){// Rows 
                        
                        /////////////// Pointeurs /////////////////
                        Vec3b *ptr = webcam.ptr<Vec3b>(i) ; // WebCam
                        Vec3b *ptrwhsv = whsv.ptr<Vec3b>(i) ; // Webcam HSV
                        Vec3b *ptrrhsv = rhsv.ptr<Vec3b>(i) ; // Reference HSV
                        Vec3b *ptres = resultat.ptr<Vec3b>(i) ; // Resultat
                        //////////////////////////////////////////

                        for(int j=0;j<640;j++){ // Cols

                               H=ptrwhsv[j](0); // h webcam 
                               S=ptrwhsv[j](1); // s webcam
                               V=ptrwhsv[j](2); // v webcam
                                
                              H1=ptrrhsv[j](0); // H reference
                              S1=ptrrhsv[j](1); // S reference
                              V1=ptrrhsv[j](2); // V reference

                               int A= Calcul(H,S,V,H1,S1,V1); 

                                if( A==0 && (Vec3b(ptrwhsv[j](0),ptrwhsv[j](1),ptrwhsv[j](2))!=Vec3b(ptrrhsv[j](0),ptrrhsv[j](1)),ptrrhsv[j](2))) {
                                        ptres[j](0)=ptr[j](0);
                                        ptres[j](1)=ptr[j](1);
                                        ptres[j](2)=ptr[j](2);
                                }else{
                                        ptres[j](0)=0;
                                        ptres[j](1)=0;
                                        ptres[j](2)=0;
                                }
                        }
                }
                imshow("Resultat", resultat);
                imshow("Ref", reference);
                if(waitKey(30)>=0){break;}
                renew++;
        }
        cap.release();
        return 0;
}
