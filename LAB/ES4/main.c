#include <stdio.h>
#include "punto.h"

int main(){
  int n=3;
  Punto array[n];
  float x,y;
  float distanza = 3.2;
  for(int i=0;i<n;i++){
    puts("Inserire x :");
    scanf("%f",&x);
    puts("Inserire y :");
    scanf("%f",&y);

    array[i] = creapunto(x,y);
  }

  Punto centro = centroide(array,n);
  printf("Centroide = ");
  stampaCoordinata(centro);

  printf("Numero di coppie con distanza minore di %.2f : %d\n",distanza, distCoppie(array,n,distanza));
  printf("Distanza massima tra coppie di punti : %.2f\n",distMax(array,n));
}
