// S3R2-41
#include <stdio.h>

void main()
{
    int A[100], f, r, size, choice = 1, i;
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
            if (r >= size - 1)
            {
                printf("overflow");
            }
            else
            {
                r = r + 1;
                printf("Enter element to insert ");
                scanf("%d", &A[r]);
                printf("Inserted %d", A[r]);
                if (f == -1)
                    f = 0;
            }
            break;
        case 2:
            if (f == -1)
            {
                printf("Underflow");
            }
            else
            {
                printf("Deleted element %d", A[f]);
                if (f == r)
                {
                    f = -1;
                    r = -1;
                }
                else
                    f = f + 1;
            }
            break;
        case 3:
            if (f == -1)
            {
                printf("Queue is empty");
            }
            else
            {
                for (i = f; i <= r; i++)
                {
                    printf("%d ", A[i]);
                }
            }
        case 0:
            break;
        }
    } while (choice > 0);
}