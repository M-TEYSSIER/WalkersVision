#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;

int main (int argc, char **argv){
        // Recuperation de data
        VideoCapture cap (atoi (argv[1]));
        //Si aucune data -> stop prog
        if (!cap.isOpened ()){return -1;}

        Mat edges,frame; // Creation matrices 
        while(true){
                // Insertion data dans matrice
                cap >> frame;
                // Afficher le contenu de la matrive
                // frame dans une fenetre 'Camera'
                imshow ("Camera", frame);
                // Si touche active -> Stop prog
                if (waitKey (30) >= 0){break;}
        }
        return 0;
}
