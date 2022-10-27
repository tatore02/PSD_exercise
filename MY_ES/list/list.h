#include "item.h"

typedef struct list *List;

struct list{
  int size;
  struct node *head;
  struct node *tail;
};

struct node{
  Item value;
  struct node *next;
};

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
void reverseList(List);
List cloneList(List);

void sortList(List);

int nPicchi(List);

void ListDiv2(List);

Item maxList(List);
Item* max2List(List);

void elimina(List,int);
void cancDaItem(List,Item);
