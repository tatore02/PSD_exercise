#include <stdlib.h>
#include <stdio.h>
#include "btree.h"
#include "item.h"
#define COUNT 5

struct node{
  Item item;
  struct node *left;
  struct node *right;
};

BTree newTree(){
  return NULL;
}

int isEmptyTree(BTree btree){
  if(btree == NULL)
    return 1;
  return 0;
}

BTree buildTree(BTree b1, BTree b2, Item item){
  BTree b = malloc(sizeof(struct node));
  b->item = item;
  b->left = b1;
  b->right = b2;
  return b;
}

Item getBTreeRoot(BTree b){
  if(isEmptyTree(b))
    return NULL;
  return b->item;
}

BTree getLeft(BTree b){
  if(isEmptyTree(b))
    return NULL;
  return b->left;
}

BTree getRight(BTree b){
  if(isEmptyTree(b))
    return NULL;
  return b->right;
}

void preOrder(BTree b){
  if(!isEmptyTree(b)){
    outputItem(b->item);
    preOrder(b->left);
    preOrder(b->right);
  }
}

void postOrder(BTree b){
  if(!isEmptyTree(b)){
    postOrder(b->left);
    postOrder(b->right);
    outputItem(b->item);
  }
}

void inOrder(BTree b){
  if(!isEmptyTree(b)){
    inOrder(b->left);
    outputItem(b->item);
    inOrder(b->right);
  }
}

int sommaNodi(BTree b){
  if(isEmptyTree(b))
    return 0;
  return ItemToInt(b->item) + sommaNodi(b->left) + sommaNodi(b->right);
}


int cercaMax(BTree b){
  if(isEmptyTree(b))
    return 0;

  int rad = ItemToInt(b->item);
  int radL = cercaMax(b->left);
  int radR = cercaMax(b->right);

  if(radL > rad)
    rad = radL;
  if(radR > rad)
    rad = radR;

  return rad;
}


int sommaLeaf(BTree b){

  if(!isEmptyTree(b)){
    if(getLeft(b) == NULL && getRight(b) == NULL)
      return ItemToInt(b->item);

  return sommaLeaf(b->left) + sommaLeaf(b->right);
  }

  return 0;
}

void outputLeaf(BTree b){

  if(!isEmptyTree(b)){
    if(getLeft(b) == NULL && getRight(b) == NULL)
      outputItem(b->item);

    outputLeaf(b->left);
    outputLeaf(b->right);
  }
  return;
}


int sizeTree(BTree b){
  if(isEmptyTree(b))
    return 0;
  else{
    return sizeTree(b->left) + sizeTree(b->right) + 1;
  }
}

int max(int a,int b){
  if(a > b)
    return a;
  else return b;
}

int altezza(BTree b){
  if(isEmptyTree(b))
    return 0;
  else if(b->left == NULL && b->right == NULL)
    return 0;
  else
    return 1 + max(altezza(b->left),altezza(b->right));
}

void invertSon(BTree b){
  if(isEmptyTree(b))
    return;
  else{
    BTree temp = b->left;
    b->left = b->right;
    b->right = temp;
  }
  invertSon(b->left);
  invertSon(b->right);
}

void printForLevel(BTree b){

  int h = altezza(b);
  for(int i=0; i <= h;i++)
    printCurrentLevel(b,i);
}

void printCurrentLevel(BTree b,int level){
  if(b == NULL)
    return;
  if(level == 0)
    outputItem(b->item);
  else{
    printCurrentLevel(b->left,level-1);
    printCurrentLevel(b->right,level-1);
  }
}

int BTreeSum(BTree b){
  if(isEmptyTree(b))
    return 0;

  int left = BTreeSum(b->left);
  int right = BTreeSum(b->right);

  int old = ItemToInt(b->item);
  int tot = left+right;
  b->item = intToItem(tot);

  return ItemToInt(b->item) + old;
}


int searchItem(BTree b,Item a){
  if(isEmptyTree(b))
    return 0;
  else if(compareItem(b->item,a) == 0)
    return 1;
  else{
    if(getLeft(b))
      return searchItem(b->left,a);
    if(getRight(b))
      return searchItem(b->right,a);
  }
}


int isEqualTree(BTree b1,BTree b2){
  if(isEmptyTree(b1) && isEmptyTree(b2))
    return 1;

  if(compareItem(b1->item,b2->item) != 0)
    return 0;

  return isEqualTree(b1->left,b2->left) && isEqualTree(b1->right,b2->right);

}

void printMinDiItemBTree(BTree b,Item a){
	if(isEmptyTree(b))
		return;

	if(compareItem(b->item,a) < 0)
		outputItem(b->item);

	printMinDiItemBTree(b->left,a);
	printMinDiItemBTree(b->right,a);
}


void sum(BTree b,int *vett,int height){
  if(isEmptyTree(b))
    return;

  int *cast = b->item;

  vett[height] = vett[height] + *cast;
  sum(b->left,vett,height+1);
  sum(b->right,vett,height+1);

}

int* sumByLevel(BTree b){
  int height = altezza(b);
  int *vett = calloc(height,sizeof(int));

  sum(b,vett,0);

  return vett;
}

int *heightAndNodes(BTree b){
  int *vett;
  vett = calloc(2,sizeof(int));

  heightAndNodes2(b,vett,vett+1,0);

  return vett;
}

void heightAndNodes2(BTree b,int *height,int *nodes,int level){
  if(!isEmptyTree(b)){
    (*nodes)++;
    if(level > *height)
      *height = level;
  }
  heightAndNodes2(b->left,height,nodes,level+1);
  heightAndNodes2(b->right,height,nodes,level+1);
}

void swap(BTree *b1,BTree *b2){
  BTree tmp = *b1;
  *b1 = *b2;
  *b2 = tmp;
}

void convertToMirror(BTree b){
  if(isEmptyTree(b))
    return;

  if(getLeft(b) && getRight(b)){
    swap(&b->left,&b->right);
    convertToMirror(b->left);
    convertToMirror(b->right);
  }
}


void printAllPaths(BTree b){
  Item vett[10];
  printAllPaths2(b,vett,0);
}

void printAllPaths2(BTree b,Item vett[],int index){
  if(isEmptyTree(b))
    return;

  vett[index] = b->item;
  index++;

  if(b->left == NULL && b->right == NULL)
    printArrayItem(vett,index);
  else{
    printAllPaths2(b->left,vett,index);
    printAllPaths2(b->right,vett,index);
  }
}

void printArrayItem(Item vett[],int size){
  for(int i=0;i<size;i++)
    outputItem(vett[i]);
  puts("");
}




void printTree(BTree b){
  printf("\nStampa albero:\n");
  printTree2(b,0);
}

void printTree2(BTree b,int space){
  if(isEmptyTree(b))
    return;

  space += COUNT;
  printTree2(b->right,space);

  printf("\n");
  for(int i=COUNT;i < space;i++)
    printf(" ");
  outputItem(b->item);

  printTree2(b->left,space);
}
