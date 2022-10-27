#include <stdio.h>
#include "item.h"
#include "stack.h"
#include "list.h"

void reverseStack(Stack);
void insertAtBottom(Stack,Item);
void reverseStackRic(Stack);



int main(){
	Stack s = newStack();
	int a[] = {1,2,3,4,5};

	for(int i=0;i<5;i++)
		push(s,&a[i]);

	printStack(s);
	reverseStackRic(s);
	printf("\nReverse Stack:\n");
	printStack(s);

}

void reverseStack(Stack s){
	List l = newList();
	Item a;

	while(!isEmptyStack(s)){
		a = top(s);
		pop(s);
		addListTail(l,a);
	}

	while(!isEmpty(l)){
		a = removeHead(l);
		push(s,a);
	}
}

void insertAtBottom(Stack s,Item a){
	if(isEmptyStack(s))
		push(s,a);
	else{
		Item tmp = top(s);
		pop(s);
		insertAtBottom(s,a);
		push(s,tmp);
	}
}

void reverseStackRic(Stack s){
	if(!isEmptyStack(s)){
		Item tmp = top(s);
		pop(s);
		reverseStackRic(s);
		insertAtBottom(s,tmp);
	}

}
