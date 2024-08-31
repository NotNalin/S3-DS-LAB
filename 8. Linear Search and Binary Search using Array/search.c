#include <stdio.h>
void main()
{
    int i, j, num, temp, choice, n, lb, ub, mid, flag, A[100];
    printf("Enter size of array ");
    scanf("%d", &n);
    printf("Enter the elements ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    printf("The array is ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    do
    {
        printf("\n1. Linear search\n");
        printf("2. Binary search\n");
        printf("Enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be searched ");
            scanf("%d", &num);
            flag = 0;
            for (i = 0; i < n; i++)
            {
                if (A[i] == num)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                printf("Element found at index %d\n", i);
            else
                printf("Element not found\n");
            break;
        case 2:
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (A[j] > A[j + 1])
                    {
                        temp = A[j];
                        A[j] = A[j + 1];
                        A[j + 1] = temp;
                    }
                }
            }
            printf("Sorted array is : ");
            for (i = 0; i < n; i++)
                printf("%d ", A[i]);

            printf("\nEnter element to be searched ");
            scanf("%d", &num);

            lb = 0;
            ub = n - 1;
            mid = (lb + ub) / 2;

            while (lb <= ub)
            {
                mid = lb + (ub - lb) / 2;
                if (A[mid] == num)
                {
                    printf("Element found at index %d using Binary Search.\n", mid);
                    break;
                }
                else if (A[mid] < num)
                    lb = mid + 1;
                else
                    ub = mid - 1;
            }
            if (lb > ub)
                printf("Element not found using Binary Search.\n");
            break;
        }
    } while (choice != 0);
}
