#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL, *tmp = NULL, *loc = NULL, *par = NULL, *ptr = NULL, *save = NULL;

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
    { 
        printf("Element already exists\n");
        return;
    }
        
    tmp = malloc(sizeof(struct node));
    tmp->data = item;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if (par == NULL)
    {
        printf("Inserted %d as root node \n",item);
        root = tmp;
    }
    else if (item < par->data)
    {
        par->lchild = tmp;
        printf("Inserted %d as left child of %d\n",item,par->data);
    }
    else
    {
        par->rchild = tmp;
        printf("Inserted %d as right child of %d\n",item,par->data);
    }
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

void main()
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
        printf("2. Display Inorder\n");
        printf("3. Display Preorder\n");
        printf("4. Display Postorder\n");
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
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (choice != 0);
}
