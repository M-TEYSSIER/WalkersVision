#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void help(char *test){
        printf("%s b f x1 x2 y1\n",test);
}

int main(int argc,char * argv[]){
        if(argc<2){
                help(argv[0]);
                return 0;
        }

        float b=atoi(argv[1])*pow(10,-2), // Distance entre les cameras en (m)
              f=atoi(argv[2])*pow(10,-3), // Distance focal en (m)
              x1=atoi(argv[3]), // Valeur du point en coordonnée 'x' de la première camera
              x2=atoi(argv[4]), // Valeur du point en cooronnée 'x' de la deuxième camera
              y1=atoi(argv[5]), // Valeur du point en coordonnée 'y' de la première camera (Même y pour l'autre car ||)
              px=2.5*pow(10,-6), // Valeur en mètre d'un pixel
              Z=0,
              X=0, 
              Y=0;
        printf("Val base: %lf %lf %lf %lf %lf\n",b,f,x1,x2,y1); 
        
        // Pixel 2 Meter
        x1*=px; 
        x2*=px;
        y1*=px;
        printf("Val Px2m: x1= %lf ,x2 %lf ,y1= %lf\n",x1,x2,y1); 

        // Pixel 2 Meter
        Z=(b*f)/(fabs(x1-x2)); // Calcul de la valeur de Z dans sa dimension 
        X=((x1*Z)/f); // Calcul de la valeur de X dans sa dimension 
        Y=((y1*Z)/f); // Calcul de la valeur de Y dans sa dimension
        printf("Z= %lf ,X= %lf ,Y= %lf\n",Z,X,Y); 

        return 0;
}
