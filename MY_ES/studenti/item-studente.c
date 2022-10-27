#include "item.h"

Item inputItem(FILE *fp){

  char *nome = malloc(10 * sizeof(char));
  char *cognome = malloc(10 * sizeof(char))
  char *codice = malloc(10 * sizeof(char));
  int g,m,a;

  char *buf1 = malloc(2*sizeof(char));
  char *buf2 = malloc(2*sizeof(char));
  char *buf3 = malloc(4*sizeof(char));


  fscanf(fp,"%s ",nome);
  fscanf(fp,"%s\n",cognome);
  fscanf(fp,"%s\n",codice);
  fscanf(fp,"%s ",buf1);
  fscanf(fp,"%s ",buf2);
  fscanf(fp,"%s\n",buf3);

  g = atoi(buf1);
  m = atoi(buf2);
  a = atoi(buf3);

  createData(g,m,a);
  
}
