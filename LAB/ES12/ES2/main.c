#include <stdio.h>
#include "item.h"
#include "car.h"
#include "list.h"

int main(){
  Item i;
  Car a;
  List l = newList();
  for(int j=0;j<3;j++){
    printf("Inserire dati auto numero %d:\n",(j+1));
    i = inputItem();
    addCar(l,i);
  }
  char del[20];
  printf("\nInserire modello da eliminare: ");
  scanf("%s",del);
  deleteCar(l,&del);
  printList(l);
}
