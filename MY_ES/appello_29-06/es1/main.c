#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

int isOpen(char a){
	if(a==40 || a==91 || a==123)
		return 1;
	else return 0;
}

int isClosed(char a){
	if(a==41 || a==93 || a==125)
		return 1;
	else return 0;
}

int isCorresponding(char a,char b){
	if(a==40 && b==41)
		return 1;
	if(a==91 && b==93)
		return 1;
	if(a==123 && a==125)
		return 1;

	return 0;
}

char *soloParentesi(char *str){
	char *nuova;
	nuova = malloc(sizeof(char) * strlen(str));

	for(int i=0,j=0; i < strlen(str); i++){
		if(isOpen(str[i]) || isClosed(str[i])){
			nuova[j] = str[i];
			j++;
		}
	}
	printf("Stringa solo parentesi: %s\n",nuova);
	return nuova;
}

int isBalanced(char *x){
	Stack s = newStack();

	for(;*x != '\0';x++){
		if(isOpen(*x)){
			Item tmp = x;
			push(s,tmp);
		}
		else if(isClosed(*x)){
			if(isEmptyStack(s))
				return 0;
			char *y = top(s);
			pop(s);
			if(!isCorresponding(*y,*x))
				return 0;
		}
	}
	return 1;
}


	int main(){
		char x[] = "(4+a)*{[1–(2/x)]*(8–a)}";
		if(isBalanced(soloParentesi(x)))
			puts("OK");
		else puts("NO");
	}
