#include <stdio.h>
typedef void *Item;

Item inputItem(FILE *);
void outputItem(Item);
int compareItem(Item,Item);
void swapItem(Item*,Item*);
