#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL, *tmp;

void find(int item, struct node **loc, struct node **par)
{
    struct node *ptr, *save;

    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }

    if (root->data == item)
    {
        *loc = root;
        *par = NULL;
        return;
    }

    if (root->data > item)
    {
        ptr = root->lchild;
        save = root;
    }
    else
    {
        ptr = root->rchild;
        save = root;
    }

    while (ptr != NULL)
    {
        if (ptr->data == item)
        {
            *loc = ptr;
            *par = save;
            return;
        }

        if (ptr->data > item)
        {
            save = ptr;
            ptr = ptr->lchild;
        }
        else
        {
            save = ptr;
            ptr = ptr->rchild;
        }
    }

    *loc = NULL;
    *par = save;
}

void insertion(int item)
{
    struct node *loc, *par;

    find(item, &loc, &par);

    if (loc != NULL)
    {
        return;
    }

    tmp = malloc(sizeof(struct node));
    tmp->data = item;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (par == NULL)
    {
        root = tmp;
    }
    else if (par->data > item)
    {
        par->lchild = tmp;
    }
    else
    {
        par->rchild = tmp;
    }
}

// Deletion - no children (Case A)
void case_a(struct node *loc, struct node *par)
{
    if (par == NULL)
    {
        root = NULL;
    }
    else if (par->lchild == loc)
    {
        par->lchild = NULL;
    }
    else
    {
        par->rchild = NULL;
    }
    free(loc);
}

// Deletion - one child (Case B)
void case_b(struct node *loc, struct node *par)
{
    struct node *child;

    if (loc->lchild != NULL)
    {
        child = loc->lchild;
    }
    else
    {
        child = loc->rchild;
    }

    if (par == NULL)
    {
        root = child;
    }
    else if (par->lchild == loc)
    {
        par->lchild = child;
    }
    else
    {
        par->rchild = child;
    }
    free(loc);
}

// Deletion - two children (Case C)
void case_c(struct node *loc, struct node *par)
{
    struct node *suc, *parsuc, *ptr;

    // Find the inorder successor and its parent
    parsuc = loc;
    ptr = loc->rchild;
    while (ptr->lchild != NULL)
    {
        parsuc = ptr;
        ptr = ptr->lchild;
    }

    suc = ptr;

    // Replace the data of the node to be deleted with the successor's data
    loc->data = suc->data;

    // Delete the successor node (it will be either case A or case B)
    if (suc->lchild == NULL && suc->rchild == NULL)
    {
        case_a(suc, parsuc);
    }
    else
    {
        case_b(suc, parsuc);
    }
}