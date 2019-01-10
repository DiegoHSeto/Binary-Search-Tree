#include <stdio.h>
#include <stdlib.h>

typedef struct node *Tree;

Tree *createBinaryTree();
void freeNode(struct node *node);
void freeBinaryTree(Tree *t);
void searchForAdd(Tree *t, int num, struct node *prev);
void addElement(Tree *t, int num);
struct node* getNewChild(struct node *node);
void searchForRemove(Tree *t, int num, struct node *prev, int *f);
void removeElement(Tree *t, int num);
void printPreOrder(Tree *t);
void printPostOrder(Tree *t);
void printInOrder(Tree *t);
void add(Tree *t, int num);

