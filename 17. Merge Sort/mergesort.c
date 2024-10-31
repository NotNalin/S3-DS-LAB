#include <stdio.h>

void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            temp[k] = A[i];
            i++;
        }
        else
        {
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = A[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = temp[i - low];
    }
}

void mergesort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);

        merge(A, low, mid, high);
    }
}

void main()
{
    int A[100], n;
    printf("Enter size of Array : ");
    scanf("%d", &n);
    printf("Enter the Array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    mergesort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}