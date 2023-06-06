//gcc -o salida nivelDeSeniaRadiobase.c -lm

#include <stdio.h>
#include <math.h>

double FC = 2132.5; // Promedio entre 2110 y 2155 que son los limites de frecuencia de la banda 4
double HM = 1.5; // Altura de la antena del móvil en m.
double HB = 30; // Altura efectiva de la estaciòn base en metros
double CM = -12; // Factor de corrección (Para entornos sub-urbanos con pequeños edificios)
double D = 3.10901; //Distancia D en Km


double l();
double a();

int main() {

    printf("Los decibeles que me llegan son: %f \n", l());

    return 0;
}

//L( dB ) = 46,3 + 33,9 log( f c ) − 13,82 log( hb ) − a( hm ) + ( 44,9 − 6,55 log( hb )) log(d) + Cm
double l(){
return 46.3 + 33.9*log10(FC) - 13.82*log10(HB) - a() + (44.9 - 6.55*log10(HB))*log10(D) + CM;
}


//a (hm ) = hm (1,1log( f c ) − 0,7) − (1,56 log( f c ) − 0,8)
double a(){
return HM*(1.1*log10(FC)-0.7) - (1.56*log10(FC)-0.8);
}