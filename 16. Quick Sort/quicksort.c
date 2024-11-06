#include <stdio.h>

int partition(int A[], int lb, int ub)
{
    int i, j, pivot, temp;
    pivot = A[lb];
    i = lb;
    j = ub;
    while (i < j)
    {
        while (A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[lb];
    A[lb] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int j = partition(A, lb, ub);
        quicksort(A, lb, j - 1);
        quicksort(A, j + 1, ub);
    }
}

void main()
{
    int n, A[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    quicksort(A, 0, n - 1);
    printf("Array after Quick Sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
