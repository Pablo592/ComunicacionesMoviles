//gcc -o salida nivelDeSeniaRadiobase.c -lm

#include <stdio.h>
#include <math.h>

double FC = 2132.5; // Promedio entre 2110 y 2155 que son los limites de frecuencia de la banda 4
double HM = 1.5; // Altura de la antena del móvil en m.
double HB = 30; // Altura efectiva de la estaciòn base en metros
double CM = -12; // Factor de corrección (Para entornos sub-urbanos con pequeños edificios)
double D = 3.10901; //Distancia D en Km
double PTX = 30;    //Potencia de la antena
double GTX = 14;      // Ganancia de la antena en DB. Fuente
double GRX = 2;      // Ganancia del celular
double atenuacionConectores = 1;
double conectorCelular = 1;



//Es decir, la potencia recibida por el celular Prx, los -101 dBm, es igual a la potencia transmitida por la 
//antena de la torre mas la ganancia de la antena menos la atenuacion del medio menos 1 dB de atenuacion de 
//los conectores mas la ganancia de la antena del celular que pueden ser 2dB menos 1 dB de atenuacio del conector del celular.



double l();
double a();
double prx();

int main() {

    printf("Los decibeles que me llegan son: %f \n", prx());

    return 0;
}

//Prx = Ptx + Gtx - 144 dB - 1 dB + Grx - 1 dB
double prx(){
return PTX + GTX - l() - atenuacionConectores + GRX - conectorCelular;
}

//L( dB ) = 46,3 + 33,9 log( f c ) − 13,82 log( hb ) − a( hm ) + ( 44,9 − 6,55 log( hb )) log(d) + Cm
double l(){
return 46.3 + 33.9*log10(FC) - 13.82*log10(HB) - a() + (44.9 - 6.55*log10(HB))*log10(D) + CM;
}


//a (hm ) = hm (1,1log( f c ) − 0,7) − (1,56 log( f c ) − 0,8)
double a(){
return HM*(1.1*log10(FC)-0.7) - (1.56*log10(FC)-0.8);
}