#include "item.h"
#include "list.h"

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

int larghezza(BTree);
void invertSon(BTree);

int isFull(BTree);

List printLeaf(BTree);

List minDiItem(BTree,Item);
void minDiItem2(BTree,Item,List);
