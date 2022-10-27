#include "item.h"

typedef struct stack *Stack;

Stack newStack();
int isEmptyStack(Stack);
int push(Stack, Item);
int pop(Stack);
Item top(Stack);
void printStack(Stack);

void printStackReverse(Stack );

char* reverseStr(char *);

void IntToBin(int);

void reverseStackRic(Stack);
Stack reverseStack(Stack);

int isEqualStack(Stack,Stack);
int isEqualStackRic(Stack,Stack);

int palindromaNumeri(int);
int palindromaStringa(char*);

float mediaStack(Stack);

void sortedInsert(Stack,Item);
void sortStack(Stack);
