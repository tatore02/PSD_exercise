#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct punto{
  float x;
  float y;
};

Punto creapunto(float x, float y){
  Punto p=malloc(sizeof(struct punto));
  p->x=x;
  p->y=y;
  return p;
}

float ascissa(Punto p){
  return p->x;
}

float ordinata(Punto p){
  return p->y;
}

float distanza(Punto p1, Punto p2){
  float dx,dy;
  dx = p1->x - p2->x;
  dy = p1->y - p2->y;
  return sqrt((dx*dx)+(dy*dy));
}

void spostamento(Punto p,float x, float y){
  p->x += x;
  p->y += y;
}

void stampaCoordinata(Punto p){
  printf("[x] : %.2f  [y] : %.2f\n",p->x,p->y);
}

Punto centroide(Punto vettore[], int dim){
  int i;
  float x=0,y=0;
  for(i=0;i<dim;i++){
    x+=vettore[i]->x;
    y+=vettore[i]->y;
  }
  x = x/dim;
  y = y/dim;

  Punto centroide = creapunto(x,y);
  return centroide;
}

int distCoppie(Punto vettore[],int dim,float dist){
  int i,j;
  int count=0;
  for(i=0;i<dim-1;i++){
    for(j=i+1;j<dim;j++)
      if(distanza(vettore[i],vettore[j])<dist)
        count++;
  }
  return count;
}

float distMax(Punto vettore[], int dim){
  float max=0;
  int i,j;
  for(i=0;i<dim-1;i++){
    for(j=i+1;j<dim;j++)
      if(distanza(vettore[i],vettore[j])>max)
        max = distanza(vettore[i],vettore[j]);
  }
  return max;
}
