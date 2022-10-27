#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List);

Item searchList(List, char*, int *);
Item removeListItem(List, char*);
Item removeListItemPos(List, int );
int addListItem (List, Item, int);
int addListTail (List, Item);
void reverseList(List);
List cloneList(List);

void sortList(List);
