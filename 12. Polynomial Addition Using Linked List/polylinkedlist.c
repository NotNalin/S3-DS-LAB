#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *link;
} *start = NULL, *start1 = NULL, *start2 = NULL, *start3 = NULL, *ptr, *ptr1, *ptr2, *ptr3, *tmp;

struct node *Create()
{
    int i, coeff, exp, n;
    start = NULL;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the terms: ");
    for (i = 0; i < n; i++)
    {
        tmp = malloc(sizeof(struct node));

        printf("\nEnter coeff and exp: ");
        scanf("%d %d", &coeff, &exp);

        tmp->coeff = coeff;
        tmp->exp = exp;
        tmp->link = NULL;

        if ((start == NULL)||(exp > start->exp))
        {
            tmp->link = start;
            start = tmp;
        }
        else
        {
            ptr = start;
            while (ptr->link != NULL && ptr->link->exp >= exp)
            {
                ptr = ptr->link;
            }
            tmp->link = ptr->link;
            ptr->link = tmp;
        }
    }

    return start;
}

void main()
{
    printf("\nEnter first polynomial.\n");
    start1 = Create();
    printf("\nEnter second polynomial.\n");
    start2 = Create();

    ptr1 = start1;
    ptr2 = start2;
    start3 = NULL;

    printf("\nFirst Polynomial is: \n");
    while (ptr1->link != NULL)
    {
        printf(" %d x^%d +", ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->link;
    }
    printf(" %d x^%d\n\n", ptr1->coeff, ptr1->exp);

    printf("\nSecond Polynomial is : \n");
    while (ptr2->link != NULL)
    {
        printf(" %d x^%d +", ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->link;
    }
    printf(" %d x^%d\n\n", ptr2->coeff, ptr2->exp);

    ptr1 = start1;
    ptr2 = start2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        tmp = malloc(sizeof(struct node));
        tmp->link = NULL;

        if (start3 == NULL)
        {
            start3 = tmp;
            ptr3 = start3;
        }
        else
        {
            ptr3->link = tmp;
            ptr3 = tmp;
        }
        if (ptr1->exp > ptr2->exp)
        {
            tmp->coeff = ptr1->coeff;
            tmp->exp = ptr1->exp;
            ptr1 = ptr1->link;
        }
        
        else if (ptr2->exp > ptr1->exp)
        {
            tmp->coeff = ptr2->coeff;
            tmp->exp = ptr2->exp;
            ptr2 = ptr2->link;
        }
        else
        {
            tmp->coeff = ptr1->coeff + ptr2->coeff;
            tmp->exp = ptr1->exp;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
    }

    while (ptr1 != NULL)
    {
        tmp = malloc(sizeof(struct node));
        tmp->link = NULL;

        tmp->coeff = ptr1->coeff;
        tmp->exp = ptr1->exp;
        ptr1 = ptr1->link;

        if (start3 == NULL)
        {
            start3 = tmp;
            ptr3 = start3;
        }
        else
        {
            ptr3->link = tmp;
            ptr3 = tmp;
        }

    }

    while (ptr2 != NULL)
    {
        tmp = malloc(sizeof(struct node));

        tmp->coeff = ptr2->coeff;
        tmp->exp = ptr2->exp;
        ptr2 = ptr2->link;

        if (start3 == NULL)
        {
            start3 = tmp;
            ptr3 = start3;
        }
        else
        {
            ptr3->link = tmp;
            ptr3 = tmp;
        }
    }

    printf("\nThe resultant polynomial is : \n");
    ptr3 = start3;
    while (ptr3->link != NULL)
    {
        printf(" %d x^%d +", ptr3->coeff, ptr3->exp);
        ptr3 = ptr3->link;
    }
    printf(" %d x^%d\n\n", ptr3->coeff, ptr3->exp);
}