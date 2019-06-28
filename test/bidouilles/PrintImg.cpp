#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream> // 

using namespace cv;
int main(int argc, char** argv )
{
    if ( argc != 2 ){ // Si le nombre d argument depasse 2 (le prog + le nom de l image)
        printf("usage: DisplayImage.out <Image_Path>\n");// Affichage message
        return -1; // ERROR 
    }
    Mat image; // Stocke les donnees de l image dans Mat
    image = imread( argv[1], 1 ); // Charge l'image
    if ( !image.data ){// Si le chargement de la variable image n a pas de donnees 
        printf("No image data \n"); 
        return -1; // ERROR
    }
    namedWindow(argv[1], WINDOW_AUTOSIZE ); // Creer un nom pour l image
    imshow(argv[1], image); // Affiche l image dans une fenetre creer sur la ligne precedente
    waitKey(0); // Attend une action via une touche 
    return 0;
}
