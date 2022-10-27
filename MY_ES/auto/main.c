#include <stdio.h>
#include "car.h"
#include "list.h"

int main(){
  List l = newList();

  Car c;
  for(int i=0;i<3;i++){
    printf("Inserire dati auto:\n");
    c = inputItem();
    addListTail(l,c);
  }
  printf("\nLista auto:\n");
  printList(l);
  sortList(l);
  printf("\nLista auto ordinata per anno di produzione:\n");
  printList(l);

  printf("Inserire targa: ");
  char buffer[10];
  scanf("%s",buffer);
  printf("Auto con targa %s: ",buffer);
  outputItem(searchList(l,buffer,0));

  printf("Inserire nome modello: ");
  scanf("%s",buffer);
  if(removeListItem(l,buffer) != NULL){
    printf("Auto rimossa\n");
    printList(l);
  }

}
