/*
Si scriva un programma che legga da input una sequenza di caratteri, e stampi a video tale sequenza in ordine invertito.
Si memorizzino i dati nella struttura dati ritenuta più adatta per l’esecuzione del programma.
La funzione stamperà i caratteri in ordine invertito usando una strategia ricorsiva.
Inoltre, la funzione ricorsiva restituirà il numero di caratteri stampati.
Esempio:
  se inserito “abcdef”, il programma deve stampare: “fedcba 6”
*/
#include <stdio.h>

void reverse(char *,int*);

int main(){
  char str[20];
  int i=0;
  printf("Inseire stringa: ");
  scanf("%s",str);
  puts("Stringa riversata:");
  reverse(str,&i);
  printf("\nNumero caratteri: %d\n",i);
}

void reverse(char *str,int *i){
  if(*str){
    (*i)++;
    reverse(str+1,i);
    printf("%c",*str);
  }
}
