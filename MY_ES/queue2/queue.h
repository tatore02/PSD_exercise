#include "item.h"

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
int enqueue(Queue, Item);
Item dequeue(Queue);
Item top(Queue);
void printQueue(Queue);

Queue cancFinoItem(Queue ,Item);
int presente(Queue , Item );
Queue fondiDaItem(Queue,Queue,Item);

Item estraiMaxN(Queue,int);

Item estraiMaxNRic(Queue,int);
Item fSupp(Queue,int,Item);

void cancFinoItemRic(Queue,Item);

int presenteRic(Queue,Item,int,Item*);
void completaQueue(Queue,int,Item*);
