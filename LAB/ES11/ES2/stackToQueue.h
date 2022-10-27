#include "item.h"

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
void enqueue(Queue,Item);
void dequeue(Queue);
void printQueue(Queue);
