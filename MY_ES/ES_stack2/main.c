#include <stdio.h>
#include "stack.h"
#include "item.h"

int main(){
	Stack s = newStack();

	char str[] = "(x+y)";

	if(parentesiDuplicate(str))
		puts("OK");
	else puts("NO");
}
