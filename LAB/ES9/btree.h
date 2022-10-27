#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);

int max(int ,int );
int height(BTree );
int nNodi(BTree );
void printLiv(BTree);
void preOrderIter(BTree);
void postOrderIter(BTree);
void inOrderIter(BTree);
