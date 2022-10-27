#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

int isOpen(char );
int isClosed(char);
int isCorresponding(char,char);
char *soloParentesi(char *);
int isBalanced(char *);

int main(){
	char str[] = {"(4+a)*{[1–(2/x)]*(8–a)}"};
	char newStr[strlen(str)];
	for(int i=0;i<strlen(str);i++)
		if((isOpen(str[i]) || isClosed(str[i])))
			printf("%c",str[i]);
	puts("");
	if(isBalanced(str))
		printf("L'espressione è bilanciata!\n");
	else
		printf("L'espressione NON è bilanciata!\n");
}

int isOpen(char x){
  if(x == 40 || x == 91 || x == 123)
    return 1;
  else return 0;
}

int isClosed(char x){
  if(x == 41 || x == 93 || x == 125)
    return 1;
  else return 0;
}

int isCorresponding(char x,char y){
  if(x == 40 && y == 41)
    return 1;
  if(x == 91 && y == 93)
    return 1;
  if(x == 123 && y == 125)
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

int isBalanced(char *str){
  int i=0;
  char *c;
  Stack s = newStack();

	while(str[i] != '\0'){
		if(isOpen(str[i]))
			push(s, &str[i]);

		if(isClosed(str[i])){
			if(isEmptyStack(s))
				return 0;

			c = top(s);
			if(!pop(s))
				printf("Rimozione dello stack non riuscita");

			if(!isCorresponding(*c,str[i]))
				return 0;
		}
		i++;
	}
		if(isEmptyStack(s))
			return 1;
		return 0;
}
