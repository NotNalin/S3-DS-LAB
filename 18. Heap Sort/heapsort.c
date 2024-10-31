#include <stdio.h>
void heapify(int A[], int n, int i)
{
    int l, r, largest, temp;
    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, n, largest);
    }
}
void heapsort(int A[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
}
void main()
{
    int n, A[100], i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("Enter array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    heapsort(A, n);
    printf("Sorted array is\n");
    for (i = 0; i < n; i++)
        printf("%d\t", A[i]);
    printf("\n");
}