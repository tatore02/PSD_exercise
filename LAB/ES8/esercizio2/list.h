#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List);

Item searchList(List, Item, int *);
Item removeListItem(List, Item);
Item removeListItemPos(List, int );
int addListItem (List, Item, int);
int addListTail (List, Item);
int addListTail2(List ,Item );
Item removeListTail(List );
void reverseList(List);
List cloneList(List);

void sortList(List);

//ES 7
void printListRec(List );
Item searchListRec(List ,Item ,int *);
int countItemListRec(List ,Item );
void destroyListRec(List);

//ES8
int countNode(List );
