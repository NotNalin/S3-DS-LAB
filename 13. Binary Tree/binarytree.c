#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *lchild;
	int data;
	struct node *rchild;
};

void insert(struct node *x)
{
	int l,r;
	struct node *lchild=NULL,*rchild=NULL;
	
	printf("Enter left child of %d : ",x->data);
	scanf("%d",&l);
	printf("Enter right child of %d : ",x->data);
	scanf("%d",&r);
	if(l==0)
	{
		x->lchild=NULL;
	}
	else
	{
		lchild = malloc(sizeof(struct node));
		lchild->data=l;
		x->lchild=lchild;
		insert(lchild);
	}
	if(r==0)
	{
		x->rchild=NULL;
	}
	else
	{
		rchild = malloc(sizeof(struct node));
		rchild->data=r;
		x->rchild=rchild;
		insert(rchild);
	}	
}
void preorder(struct node *x)
{
	if (x!=NULL)
	{
		printf("%d ",x->data);
		preorder(x->lchild);
		preorder(x->rchild);
	}
}

void inorder(struct node *x)
{
	if (x!=NULL)
	{
		inorder(x->lchild);
		printf("%d ",x->data);
		inorder(x->rchild);
	}
}

void postorder(struct node *x)
{
	if (x!=NULL)
	{
		postorder(x->lchild);
		postorder(x->rchild);
		printf("%d ",x->data);
	}
}

void main()
{
	struct node *root=NULL, *tmp=NULL;
	int choice;
	printf("Enter root node ");
	tmp = malloc(sizeof(struct node));
	scanf("%d",&tmp->data);
	root = tmp;
	insert(root);
	do
	{
		printf("\n1.Preorder\n2.Inorder\n3.Postorder\n0.Exit\n");
		printf("Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				preorder(root);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				postorder(root);
				break;
		}
	} while (choice!=0);
}
