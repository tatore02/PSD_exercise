#include "item.h"

typedef struct node *Heap;

Heap newHeap();
int isEmptyHeap(Heap);
Heap getLeft(Heap);
Heap getRight(Heap);
Item getItem(Heap);


void swap(int *,int *);
void outputArray(int *,int);

void insertHeap(int*,int*,int);
