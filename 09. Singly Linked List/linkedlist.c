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
        printf("1. Insert at Beginning\n");
        printf("2. Insert in Between\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete in Between\n");
        printf("6. Delete from End\n");
        printf("7. Display\n");
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
        case 2: // Insert in Between
            temp = malloc(sizeof(struct node));
            printf("Enter data to insert: ");
            scanf("%d", &data);
            temp->data = data;
            printf("Enter data after which to insert: ");
            scanf("%d", &data);
            ptr = start;
            while (ptr->data != data)
            {
                ptr = ptr->link;
            }
            temp->link = ptr->link;
            ptr->link = temp;
            break;
        case 3: // Insert at End
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
        case 4: // Delete from Beginning
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
        case 5: // Delete in Between
            if (start == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("Enter element to delete: ");
                scanf("%d", &data);
                ptr = start;
                while (ptr->data != data && ptr->link != NULL)
                {
                    prev = ptr;
                    ptr = ptr->link;
                }
                if (ptr->link == NULL)
                {
                    printf("Element not found\n");
                }
                else
                {
                    prev->link = ptr->link;
                    free(ptr);
                }
            }
            break;
        case 6: // Delete from End
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
        case 7: // Display
            if (start == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                for (ptr = start; ptr->link != NULL; ptr = ptr->link)
                {
                    printf("%d -> ", ptr->data);
                }
                printf("%d\n", ptr->data);
            }
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (choice != 0);
    return 0;
}