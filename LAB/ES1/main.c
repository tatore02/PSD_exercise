#include <stdio.h>
#include "vettore.h"

int main(){
  int n=5;
  int x[10];
  int scelta=0;
  int el;
  while(1){
    printf("Comandi:\n1-Inserire elementi nel vettore\n2-Stampare contenuto vettore\n3-Ricerca elemento nel vettore\n4-Ricerca del minimo\n5-Ordinare vettore\n6-Eliminare un elemento del vettore\n7-Inserire elemento nel vettore\n");
    scanf("%d", &scelta);
    switch(scelta){
    case 1:
      inputArray(x,n);
    break;
    case 2:
      outputArray(x,n);
    break;
    case 3:
      puts("Inserire elemento da cercare:");
      scanf("%d",&el);
        if(ricerca(x,n,el)==n)
          puts("Elemento non trovato nel vettore");
        else printf("Elemento trovato in posizione %d\n",ricerca(x,n,el));
    break;
    case 4:
      printf("Il minimo é in posizione %d\n", minimo(x,n));
    break;
    case 5:
      while(ordine(x,n)) scambia(x,n);
      outputArray(x,n);
    break;
    case 6:
      puts("Inserire elemento da eliminare:");
      scanf("%d",&el);
      if(eliminare(x,&n,el)==0) puts("Elemento non esiste nel vettore");
      else{
        puts("Nuovo array");
        outputArray(x,n);
      }
    break;
    case 7:
      puts("Inserire elemento da aggiungere:");
      scanf("%d",&el);
      aggiungere(x,&n,el);
      puts("Nuovo array");
      outputArray(x,n);
    break;
    default:
    puts("EXIT");
    return 0;
    }
  }
}
