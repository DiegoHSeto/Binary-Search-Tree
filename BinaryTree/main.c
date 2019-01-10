#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{

    Tree *tree = createBinaryTree();

    addElement(tree, 5);
    addElement(tree, 8);
    addElement(tree, 7);
    addElement(tree, 2);
    addElement(tree, 85);
    addElement(tree, 6);
    addElement(tree, 22);

    printf("\nListando elementos em pre-ordem: \n\n");

    printPreOrder(tree);

    removeElement(tree, 5);
    removeElement(tree, 8);
    removeElement(tree, 2);
    removeElement(tree, 85);
    removeElement(tree, 22);
    removeElement(tree, 6);

    addElement(tree, 10);
    addElement(tree, 6);
    addElement(tree, 5);

    printf("\n\nListando elementos em pre-ordem: \n\n");

    printPreOrder(tree);

    return 0;
}
