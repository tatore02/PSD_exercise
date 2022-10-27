#include "item.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>


List newList(){
  List list = malloc(sizeof(struct list));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;

  return list;
}

int isEmpty(List l){
  if(l->size==0) return 1;
  else return 0;
}

void addHead(List l, Item a){
  struct node *n = malloc(sizeof(struct node));
  n->value = a;
  n->next = l->head;
  l->head = n;

  (l->size)++;
}

Item removeHead(List l){
  if(isEmpty(l)) return NULL;

  Item a;
  struct node *tmp = l->head;
  l->head = l->head->next;
  a = tmp->value;
  free(tmp);
  (l->size)--;

  if((l->size) == 0)
    l->tail = NULL;

  return a;
}

Item getHead(List l){
  if(isEmpty(l)) return NULL;

  return(l->head->value);
}

int sizeList(List l){
  return (l->size);
}

void printList(List l){
  struct node *p;

  for(p = l->head; p != NULL; p = p->next)
    outputItem(p->value);
}

Item searchList(List l, Item a, int *pos){
  *pos=0;
  struct node *p;

  for(p = l->head; p != NULL; p = p->next, (*pos)++)
    if(compareItem(a,p->value) == 0)
      return p->value;
  //se non viene trovato alcun elemento
  (*pos) = -1;
  return NULL;
}

Item removeListItem(List l, Item a){
  Item pp;
  struct node *p;
  struct node *prev;

  for(p = l->head; p != NULL; prev = p, p = p->next)
    if(compareItem(a,p->value) == 0){
      if(p == l->head){ //se l'elemento da eliminare è la testa
        removeHead(l);
      }
      else{
        prev->next = p->next;
        pp = p->value;
        free(p);
        (l->size)--;
        return pp;
      }
    }
  return NULL;
}

Item removeListItemPos(List l, int pos){
  Item pp;
  struct node *p;
  struct node *prev;
  int i=0;

  for(p = l->head; p!=NULL; prev = p, p = p->next, i++)
    if(i == pos){
      if(p == l->head){
        removeHead(l);
      }
      else{
        prev->next = p->next;
        pp = p->value;
        free(p);
        (l->size)--;
        return pp;
      }
    }
  return NULL;

}

int addListItem (List l, Item a, int pos){
  if(pos<0 || pos>(l->size))
    return 0;
  if(pos==0){   //se la posizione è 0
    addHead(l,a);
    return 1;
  }
  struct node *p;
  int i;
  for(p = l->head, i=0; i<pos-1; p = p->next, i++)
    ;
  struct node *newNode = malloc(sizeof(struct node));
  newNode->value = a;
  newNode->next = p->next;
  p->next = newNode;
  (l->size)++;
  return 1;
}

int addListTail (List l, Item a){
  struct node *new = malloc(sizeof(struct node));
  new->value = a;
  new->next = NULL;

  if(isEmpty(l))
    l->head = new;
  else
    l->tail->next = new;

  l->tail = new;

  (l->size)++;
  return 1;
}

void reverseList(List l){
  struct node *p;
  struct node *prev = NULL;
  struct node *tmp;

  for(p = l->head; p != NULL; prev = p, p = tmp){
    tmp = p->next;
    p->next = prev;
  }
  l->head = prev;
}

//implementazione dove gli item rimangono gli stessi
List cloneList (List l){
  List new = newList();

  struct node *p;
  for(p = l->head; p != NULL; p = p->next)
    addListTail(new,p->value);

  return new;
}

void sortList(List l){
  struct node *p;
  struct node *prev;
  for(p = l->head; p != NULL; p = p->next)
    for(prev = p->next; prev != NULL; prev = prev->next)
      if(compareItem(p->value,prev->value) > 0)
        swapItem(&(p->value),&(prev->value));
}

int nPicchi(List l){
  int count = 0;
  struct node *q = NULL,*w,*e;
  for(w = l->head, e = w->next; w!=NULL; q = w, w = w->next, e = e->next){
    if(q!=NULL && e != NULL)
      if(compareItem(div2(w->value),q->value) > 0 && compareItem(div2(w->value),e->value) > 0)
        count++;
  }
  return count;
}

Item maxList(List l){
  struct node *max;
	struct node *prox;
	max = l->head;
	prox = max->next;
	Item massimo = max->value;

	for(; prox != NULL; max = prox, prox = prox->next)
		if(compareItem(massimo,prox->value) < 0)
			massimo = prox->value;

	return massimo;
}

Item* max2List(List l){
  Item vett[2];
  Item massimo;

  struct node *max;
  max = l->head;
  massimo = max->value;
  struct node *prox;
  prox = max->next;

  for(;prox != NULL; max = prox, prox = prox->next)
    if(compareItem(massimo,prox->value) < 0)
      massimo = prox->value;

  vett[0] = massimo;

  Item massimo2;
  max = l->head;
  massimo2 = max->value;
  prox = max->next;

  for(;prox != NULL; max = prox, prox = prox->next)
    if(compareItem(massimo2,prox->value) < 0 && compareItem(massimo,prox->value) != 0)
      massimo2 = prox->value;

  vett[1] = massimo2;

  return vett;
}


void elimina(List l,int i){
  int j = (l->size) - i;
  int k = (l->size) -1;
	for(;j>0; j--, k--)
    removeListItemPos(l,k);
}

void cancDaItem(List l,Item a){
	struct node *p;
  int i=0;

	for(p = l->head; p != NULL; p = p->next){
		if(compareItem(p->value,a) == 0)
			elimina(l,i);
    else
      i++;
	}
}
