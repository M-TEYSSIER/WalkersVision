#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream> // 


using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    if ( argc != 2 ){ // Si le nombre d argument depasse 2 (le prog + le nom de l image)
        printf("usage: DisplayImage.out <Image_Path>\n");// Affichage message
        return -1; // ERROR 
    }

    Mat image,hsv; // Stocke les donnees de l image dans Mat
    image = imread( argv[1], 1 ); // Charge l'image

    if ( !image.data ){ // Si le chargement de la variable image n a pas de donnees 
        printf("No image data \n"); 
        return -1; // ERROR
    }

    cvtColor(image, hsv, COLOR_RGB2HSV);

    //namedWindow(argv[1], WINDOW_AUTOSIZE ); // Creer un nom pour l image
    imshow(argv[1], image);    
    imshow("conversion hsv", hsv); // Affiche l image dans une fenetre creer sur la ligne precedente

    Mat dst;
    dst =image- hsv;
    imshow("NEW",dst);

    waitKey(0); // Attend une action via une touche 
    return 0;
}
