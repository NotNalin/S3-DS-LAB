#include <stdio.h>

void main()
{
    int A[100], f, r, size, choice = 1, i, j;
    f = -1;
    r = -1;
    printf("Enter size of queue : ");
    scanf("%d", &size);
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n0.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if ((f == 0 && r == size - 1) || (f == r + 1))
            {
                printf("overflow");
                break;
            }
            if (r == size - 1)
            {
                r = 0;
            }
            else
            {
                r = r + 1;
            }
            printf("Enter element to insert ");
            scanf("%d", &A[r]);
            printf("Inserted %d", A[r]);
            if (f == -1)
            {
                f = 0;
            }
            break;
        case 2:
            if (f == -1)
            {
                printf("Underflow");
                break;
            }
            printf("Deleted element %d", A[f]);
            if (f == r)
            {
                f = -1;
                r = -1;
            }
            else if (f == size - 1)
            {
                f = 0;
            }
            else
            {
                f = f + 1;
            }
            break;
        case 3:
            if (f == -1)
            {
                printf("Queue is empty");
                return;
            }
            else if (f <= r)
            {
                for (i = f; i <= r; i++)
                {
                    printf("%d ", A[i]);
                }
            }
            else
            {
                for (i = f; i < size; i++)
                    printf("%d ", A[i]);
                for (i = 0; i <= r; i++)
                    printf("%d ", A[i]);
            }
        case 0:
            break;
        }
    } while (choice > 0);
}
