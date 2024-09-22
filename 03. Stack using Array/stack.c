// S3R2-41
#include <stdio.h>

void main()
{
    int A[100], top, size, choice = 1, i;
    top = -1;
    printf("Enter size of stack : ");
    scanf("%d", &size);
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n0.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top >= size - 1)
            {
                printf("Stack overflow");
            }
            else
            {
                top = top + 1;
                printf("Enter element to push ");
                scanf("%d", &A[top]);
                printf("Pushed %d", A[top]);
            }
            break;
        case 2:
            if (top == -1)
            {
                printf("Stack Underflow");
            }
            else
            {
                printf("Popped element %d", A[top]);
                top = top - 1;
            }
            break;
        case 3:
            if (top == -1)
            {
                printf("Stack is empty");
            }
            else
            {
                for (i = top; i >= 0; i--)
                {
                    printf("%d\n", A[i]);
                }
            }
        case 0:
            break;
        }
    } while (choice != 0);
}
