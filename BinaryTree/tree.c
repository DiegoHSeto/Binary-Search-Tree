#include "tree.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Tree *createBinaryTree()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));

    if(t == NULL)
    {
        printf("Falha na alocacao da arvore");
        return 0;
    }

    *t = NULL;

    return t;
}

void freeNode(Node *node)
{
    if(node==NULL)
    {
        return;
    }

    freeNode(node->left);
    freeNode(node->right);
    free(node);
    node = NULL;
}

void freeBinaryTree(Tree *t)
{
    if(t==NULL)
    {
        return;
    }

    freeNode(*t);
    free(t);
}

void searchForAdd(Tree *t, int num, Node *prev)
{
    if((*t)!=NULL && (*t)->data == num)
    {
        printf("\nNumero %d ja esta presente na arvore. Impossivel inserir\n", num);
        return;
    }

    if((*t)==NULL)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = num;

        if(num < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }

        return;
    }

    prev = (*t);

    if(num < (*t)->data)
    {
        searchForAdd(&(*t)->left, num, prev);
    }
    else
    {
        searchForAdd(&(*t)->right, num, prev);
    }
}

void addElement(Tree *t, int num)
{
    if(t==NULL)
    {
        printf("Arvore nao alocada");
        return;
    }
    else
    {
        if(*t==NULL)
        {
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->data = num;

            *t = newNode;
        }
        else
        {
            Node *previous = NULL;

            searchForAdd(t, num, previous);
        }
    }
}

Node* getNewChild(Node *node)
{
    Node *aux, *aux2;

    if(node->left == NULL)
    {
        aux2 = node->right;

        free(node);
        return aux2;
    }

    aux = node;
    aux2 = node->left;

    while(aux2->right != NULL)
    {
        aux = aux2;
        aux2 = aux2->right;
    }

    if(aux != node)
    {
        aux->right = aux2->left;
        aux2->left = node->left;
    }

    aux2->right = node->right;

    free(node);

    return aux2;


}

void searchForRemove(Tree *t, int num, Node *prev, int *f)
{

    if((*t)==NULL)
    {
        return;
    }

    if((*t)->data == num)
    {

        *f = 1;

        if(prev == NULL)
        {
            *t = getNewChild(*t);
        }
        else
        {
            if(prev->left == *t)
            {
                prev->left = getNewChild(*t);
            }
            else
            {
                prev->right = getNewChild(*t);
            }
        }

        return;

    }

    prev = *t;

    searchForRemove(&(*t)->left, num, prev, f);
    searchForRemove(&(*t)->right, num, prev, f);

}

void removeElement(Tree *t, int num)
{
    if(t==NULL)
    {
        printf("Arvore nao alocada");
        return;
    }

    if(*t==NULL)
    {
        printf("Impossivel remover em uma arvore vazia");
        return;
    }

    Node *previous = NULL;
    int flag = 0;

    searchForRemove(t, num, previous, &flag);

    if(flag == 0)
    {
        printf("\nElemento nao encontrado. Impossivel remover\n");
    }
}

void printPreOrder(Tree *t)
{
    if((*t)==NULL)
    {
        return;
    }

    printf("%d ", (*t)->data);
    printPreOrder(&(*t)->left);
    printPreOrder(&(*t)->right);
}

void printPostOrder(Tree *t)
{
    if((*t)==NULL)
    {
        return;
    }


    printPostOrder(&(*t)->left);
    printPostOrder(&(*t)->right);
    printf("%d ", (*t)->data);
}

void printInOrder(Tree *t)
{
    if((*t)==NULL)
    {
        return;
    }

    printInOrder(&(*t)->left);
    printf("%d ", (*t)->data);
    printInOrder(&(*t)->right);
}
