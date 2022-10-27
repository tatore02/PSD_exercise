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

int search(BTree b, Item item);
Item max(BTree b);
int equalTree(BTree b1,BTree b2);

int isEqualRic(BTree,BTree);
