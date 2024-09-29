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
    int choice, data, i;

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
        case 1: // Insert at Beginning
            temp = malloc(sizeof(struct node));
            printf("Enter data to insert: ");
            scanf("%d", &data);
            temp->data = data;
            temp->link = start;
            start = temp;
            break;
        case 2: // Delete from Beginning
            if (start == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                ptr = start;
                start = start->link;
                free(ptr);
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
                    printf("%d\n", ptr->data);
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