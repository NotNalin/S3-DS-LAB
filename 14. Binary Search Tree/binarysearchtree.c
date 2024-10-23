#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL, *tmp = NULL, *loc = NULL, *par = NULL, *ptr = NULL, *save = NULL, *child = NULL, *suc = NULL, *parsuc = NULL;

void find(int item)
{
    loc = NULL;
    par = NULL;

    if (root == NULL)
        return;

    ptr = root;
    save = NULL;

    while (ptr != NULL)
    {
        if (item == ptr->data)
        {
            loc = ptr;
            par = save;
            return;
        }
        else if (item < ptr->data)
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
    loc = NULL;
    par = save;
    return;
}

void insert(int item)
{
    find(item);
    if (loc != NULL)
        return;

    tmp = malloc(sizeof(struct node));
    tmp->data = item;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if (par == NULL)
        root = tmp;
    else if (item < par->data)
        par->lchild = tmp;
    else
        par->rchild = tmp;
}

// deletion - no children
void case_a(struct node *loc, struct node *par)
{
    if (par == NULL)
        root = NULL;
    else if (loc == par->lchild)
        par->lchild = NULL;
    else
        par->rchild = NULL;
}

// deletion - one child
void case_b(struct node *loc, struct node *par)
{
    if (loc->lchild != NULL)
        child = loc->lchild;
    else
        child = loc->rchild;

    if (par != NULL)
    {
        if (loc == par->lchild)
            par->lchild = child;
        else
            par->rchild = child;
    }
    else
        root = child;
}

// deletion - two children
void case_c(struct node *loc, struct node *par)
{
    save = loc;
    ptr = loc->rchild;
    while (ptr->lchild != NULL)
    {
        save = ptr;
        ptr = ptr->lchild;
    }
    suc = ptr;
    parsuc = save;

    if (suc->lchild == NULL && suc->rchild == NULL)
        case_a(suc, parsuc);
    else
        case_b(suc, parsuc);

    loc->data = suc->data;

    if (par == NULL)
        root = suc;
    else if (loc == par->lchild)
        par->lchild = suc;
    else
        par->rchild = suc;
    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
}

void preorder(struct node *x)
{
    if (x != NULL)
    {
        printf("%d ", x->data);
        preorder(x->lchild);
        preorder(x->rchild);
    }
}

void inorder(struct node *x)
{
    if (x != NULL)
    {
        inorder(x->lchild);
        printf("%d ", x->data);
        inorder(x->rchild);
    }
}

void postorder(struct node *x)
{
    if (x != NULL)
    {
        postorder(x->lchild);
        postorder(x->rchild);
        printf("%d ", x->data);
    }
}

int main()
{
    int choice, item, n, i;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    printf("Enter nodes : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        insert(item);
    }
    do
    {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display Inorder\n");
        printf("4. Display Preorder\n");
        printf("5. Display Postorder\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item to insert: ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            printf("Enter item to delete: ");
            scanf("%d", &item);
            find(item);
            if (loc != NULL)
            {
                if (loc->lchild == NULL && loc->rchild == NULL)
                    case_a(loc, par);
                else if (loc->lchild == NULL || loc->rchild == NULL)
                    case_b(loc, par);
                else
                    case_c(loc, par);
                free(loc);
            }
            break;
        case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (choice != 0);
}