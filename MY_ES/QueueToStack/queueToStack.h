#include "queue.h"

typedef struct stack *Stack;

Stack newStack();
int isEmptyStack(Stack);
void push(Stack,Item);
Item top(Stack);
void pop(Stack);
void printStack(Stack);
