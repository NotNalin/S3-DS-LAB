#include <stdio.h>
#include <stdlib.h>

struct node {
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

//deletion - no children
case_a(struct node *loc, struct node *par)
{
    struct node *tmp;
    if (loc->lchild != NULL && loc->rchild != NULL)
    {
        child = NULL;
    }
    if (par == NULL)
    {
        root = child;
    }
    if (par != NULL)
    {
        if (par->lchild == loc)
        {
            par->lchild=child;
        }
        else
        {
            par->rchild=child;
        }
    }
}

// deletion - one child
case_b(struct node *loc, struct node *par)
{
    if(loc->lchild != NULL && loc->rchild != NULL)
    {
        child = loc->rchild;
    }
    else if (loc->lchild == NULL && loc->rchild != NULL)
    {
        child = loc->rchild;
    }
    if (par == NULL)
    {
        if(par->lchild == loc)
        {
            par->lchild = child;
        }
    }
}

// deletion - two children
case_c(struct node *loc, struct node *par)
{
    // find suc and parsuc
    struct node *suc, *parsuc;
    save = loc;
    ptr = loc->rchild;
    while(ptr->lchild != NULL)
    {
        save = ptr;
        ptr = ptr->lchild;
    }
    suc = ptr;
    parsuc = save;
    // delete inorder sucessor node
    if(parsuc->lchild == NULL && parsuc->rchild == NULL)
    {
        case_a(parsuc, par);
    }
    else
    {
        case_b(parsuc, par);
    }
    
    if(par == NULL)
    {
        root = suc;
    }
    else if(par->lchild == loc)
    {
        par->lchild = suc;
    }
    else
    {
        par->rchild = suc;
    }
    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
}