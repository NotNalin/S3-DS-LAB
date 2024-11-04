
#include <stdio.h>
#include <stdlib.h>

void bubble(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void insertion(int A[], int n)
{
    int k, temp, ptr;
    // set A[0] to - infinity
    A[0] = -10000;
    for (k = 2; k <= n; k++)
    {
        temp = A[k];
        ptr = k - 1;
        while (temp < A[ptr])
        {
            A[ptr + 1] = A[ptr];
            ptr--;
        }
        A[ptr + 1] = temp;
    }
}

void min(int A[], int k, int n, int *loc)
{
    int min = A[k];
    *loc = k;
    for (int j = k + 1; j <= n; j++)
    {
        if (min > A[j])
        {
            min = A[j];
            *loc = j;
        }
    }
}

void selection(int A[], int n)
{
    int loc, temp, k;
    for (k = 1; k < n; k++)
    {
        min(A, k, n, &loc);
        temp = A[k];
        A[k] = A[loc];
        A[loc] = temp;
    }
}

void display(int A[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void main()
{
    int choice, n, A[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    do
    {
        printf("Menu:\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion(A, n);
            printf("Array after Insertion Sort:\n");
            display(A, n);
            break;
        case 2:
            selection(A, n);
            printf("Array after Selection Sort:\n");
            display(A, n);
            break;
        case 3:
            bubble(A, n);
            printf("Array after Bubble Sort:\n");
            display(A, n);
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);
}
