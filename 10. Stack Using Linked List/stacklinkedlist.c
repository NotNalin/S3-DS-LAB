#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *start = NULL, *ptr, *temp, *prev;
    int choice, data, pos, i;

    do
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Insertion at end
            temp = malloc(sizeof(struct node));
            printf("Enter data to insert: ");
            scanf("%d", &data);
            temp->data = data;
            temp->link = NULL;
            if (start == NULL)
            {
                start = temp;
            }
            else
            {
                ptr = start;
                while (ptr->link != NULL)
                {
                    ptr = ptr->link;
                }
                ptr->link = temp;
            }
            break;
        case 2: // Deletion from end
            if (start == NULL)
            {
                printf("List is empty\n");
            }
            else if (start->link == NULL)
            {
                free(start);
                start = NULL;
            }
            else
            {
                ptr = start;
                while (ptr->link->link != NULL)
                {
                    ptr = ptr->link;
                }
                free(ptr->link);
                ptr->link = NULL;
            }
            break;
        case 3: // Display
            if (start == NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                for (ptr = start; ptr != NULL; ptr = ptr->link)
                {
                    printf("%d ", ptr->data);
                }
            }
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (choice != 0);
}