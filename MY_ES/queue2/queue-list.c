#include <stdlib.h>
#include "queue.h"
#include "list.h"
#include "item.h"

struct queue{
  List elements;
};

Queue newQueue(){
  Queue q = malloc(sizeof(struct queue));
  q->elements = newList();

  return q;
}

int isEmptyQueue(Queue q){
  return isEmpty(q->elements);
}

int enqueue(Queue q, Item e){
  return addListTail(q->elements,e);
}

Item dequeue(Queue q){
  return removeHead(q->elements);
}

void printQueue(Queue q){
  printList(q->elements);
}

int presente(Queue q, Item el){
  Queue temp = newQueue();
  Item a;
  int flag=0;
  while(!isEmptyQueue(q)){
    a = dequeue(q);
    if(compareItem(a,el) == 0)
        flag=1;
    enqueue(temp,a);
  }

  while(!isEmptyQueue(temp)){
    a = dequeue(temp);
    enqueue(q,a);
  }

  return flag;
}

Queue cancFinoItem(Queue q,Item el){
  Queue new = newQueue();
  Item a;
  while(!isEmptyQueue(q)){
    a = dequeue(q);
    if(compareItem(a,el) == 0){
      break;
    }else{
      enqueue(new,a);
    }
  }
  return q;
}

Queue fondiDaItem(Queue q1,Queue q2,Item el){
  Queue new = newQueue();
  Item temp;

  if(presente(q1,el) && presente(q2,el)){
    q1 = cancFinoItem(q1,el);
    q2 = cancFinoItem(q2,el);
    while(!isEmptyQueue(q1)){
      temp = dequeue(q1);
      if(presente(q2,temp))
        enqueue(new,temp);
    }
  }
  return new;
}

Item estraiMaxN(Queue q,int n){
  Item max,a;
  Queue tmp = newQueue();

  max = dequeue(q);
  enqueue(tmp,max);
  n--;
  while(!isEmptyQueue(q) && n>0){
    n--;
    a = dequeue(q);
    enqueue(tmp,a);
    if(compareItem(a,max) > 0)
      max = a;
  }
  while(1){
    a = dequeue(tmp);
    if(compareItem(a,max) == 0)
      break;
  }

  while(!isEmptyQueue(tmp)){
    a = dequeue(tmp);
    enqueue(q,a);
  }
  return max;
}


Item estraiMaxNRic(Queue q,int n){
  Item a = dequeue(q);
  return fSupp(q,n,a);
}

Item fSupp(Queue q,int n,Item a){
  if(n == 0)
    return a;
  n--;
  Item b = dequeue(q);
  if(compareItem(b,a) > 0)
    a = b;

  return fSupp(q,n,a);
}

void cancFinoItemRic(Queue q,Item a){
  if(isEmptyQueue(q))
    return;
  Item b = dequeue(q);
  if(compareItem(a,b) == 0)
    return;
  else
    cancFinoItem(q,a);
}

int presenteRic(Queue q,Item a,int sent,Item *vett){
  if(isEmptyQueue(q)){
    completaQueue(q,sent,vett);
    return 0;
  }

  Item b = dequeue(q);
  if(compareItem(a,b) == 0){
    vett[sent] = b;
    sent++;
    completaQueue(q,sent,vett);
    return 1;
  }
  else{
    vett[sent] = b;
    sent++;
    return presenteRic(q,a,sent,vett);
  }
}

void completaQueue(Queue q,int sent,Item *vett){
  int i;
  Item a;
  while(!isEmptyQueue(q)){
    a = dequeue(q);
    vett[sent] = a;
    sent++;
  }
  for(i=0;i<sent;i++){
    enqueue(q,vett[i]);
  }
}
