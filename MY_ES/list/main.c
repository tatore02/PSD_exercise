#include <stdio.h>
#include "item.h"
#include "list.h"
int main(){
	List l = newList();
	int vett[] = {4,7,11,8,1,6};

	for(int i=0;i<6;i++)
		addListTail(l,&vett[i]);

	puts("Lista prima:");
	printList(l);
	printf("Inserire item: ");
	Item item = inputItem();
	cancDaItem(l,item);
	puts("Lista dopo:");
	printList(l);
}
