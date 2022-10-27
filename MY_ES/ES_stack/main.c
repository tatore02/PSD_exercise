#include <stdio.h>
#include "stack.h"
#include "item.h"

int isOpen(char c){
	if(c == 40 || c == 91 || c == 123)
		return 1;
	else
		return 0;
}

int isClosed(char c){
	if(c == 41 || c == 93 || c == 125)
		return 1;
	else
		return 0;
}

int isCorresponding(char c1,char c2){
	if(c1 == 40 && c2 == 41)
		return 1;
	if(c1 == 91 && c2 == 93)
		return 1;
	if(c1 == 123 && c2 == 125)
		return 1;

	return 0;
}

int isBalanced(char *str){
	Stack s = newStack();

	for(;*str != '\0'; str++){
		if(isOpen(*str)){
			Item ch = str;
			push(s,ch);
		}else if(isClosed(*str)){
			if(isEmptyStack(s))
				return 0;
			char *x = top(s);
			pop(s);
			if(!isCorresponding(*x,*str))
				return 0;
		}
	}
	return isEmptyStack(s);
}

int main(){
	char str[] = "(5+6)∗(7+8)/(4+3)";

	if(isBalanced(str))
		puts("OK");
	else
		puts("NONE");

}
