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

int sommaNodi(BTree);
int cercaMax(BTree);

int sommaLeaf(BTree);
void outputLeaf(BTree);

int sizeTree(BTree);
int max(int ,int ); //funzione di supporto
int altezza(BTree);

void invertSon(BTree ); //RICORSIVA

void printForLevel(BTree);
void printCurrentLevel(BTree,int);

int BTreeSum(BTree);

int searchItem(BTree,Item);

int isEqualTree(BTree,BTree);

void printMinDiItemBTree(BTree,Item);

void sum(BTree, int*,int);
int* sumByLevel(BTree);

int *heightAndNodes(BTree);
void heightAndNodes2(BTree,int*,int*,int);

void swap(BTree*,BTree*);
void convertToMirror(BTree);

void printAllPaths(BTree);
void printAllPaths2(BTree,Item *,int);
void printArrayItem(Item *,int);

void printTree2(BTree,int);
void printTree(BTree);
