#include <stdio.h>
typedef void *Item;

Item inputItem(FILE *);
void outputItem(Item);
int compareItem(Item,Item);

int ItemToInt(Item );
void swapItem(Item*,Item*);
