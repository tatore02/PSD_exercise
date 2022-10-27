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

void sumByLevel(BTree b,int level,int sum[]);
int height(BTree);
int max(int,int);

void printTree(BTree);
void printTree2(BTree,int);
