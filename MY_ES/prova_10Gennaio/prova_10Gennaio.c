#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 8

typedef struct{
      char *lunga;
      char *corta;
      int totale;
}report;

void alloca_parole (char **parole, FILE *fp);
report *maxmin(char **parole);
void stampa(report *r);

int main(){
  char* parole[MAX];
  FILE *fp = fopen("prova_10Gennaio.txt","r");
  report *r;
  alloca_parole(parole, fp);
  r = maxmin(parole);
  stampa(r);
  free(r->lunga);
  free(r->corta);
  free(r);
  fclose(fp);
  return 0;
}

 void alloca_parole(char **parole, FILE *fp){
   int a=0,i=0;
   while(!feof(fp)){
     fscanf(fp,"%d",&a);
     parole[i] =(char*)malloc(a*sizeof(char));
     printf("Inserire stringa (max %d caratteri): ",a);
     scanf("%s",parole[i]);
     i++;
   }
 }

 report *maxmin(char **parole){
   int i;
   report *t;
   char max[10];
   char min[10];

   strcpy(max,parole[0]);
   strcpy(min,parole[0]);

   for(i=1;i<MAX;i++){
     if(strlen(parole[i])>strlen(max))
        strcpy(max,parole[i]);
     if(strlen(parole[i])<strlen(min))
        strcpy(min,parole[i]);
   }
   t = malloc(sizeof(report));
   t->lunga = malloc(strlen(max) * sizeof(char));
   t->corta = malloc(strlen(min) * sizeof(char));

   strcpy(t->lunga,max);
   strcpy(t->corta,min);

   t->totale = strlen(t->corta) + strlen(t->lunga);
   return t;
 }

  void stampa(report *r){
    printf("Parola lunga: %s\nParola corta: %s\nLunghezza parole: %d\n",r->lunga,r->corta,r->totale);
  }
