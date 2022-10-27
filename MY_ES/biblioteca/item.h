#include <stdio.h>
typedef void *Item;

Item inputItem(FILE *);
void outputItem(Item);
int compareItem(Item,Item);
int compareItem2(int,Item );
int compareItem3(char*,Item);
int compareItem4(Item,Item);
int ItemToInt(Item );
void swapItem(Item*,Item*);
