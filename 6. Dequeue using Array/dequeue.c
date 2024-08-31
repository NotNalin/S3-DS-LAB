#include <stdio.h>
void main()
{
  int ch, choice, Q[100], n, R = -1, F = -1, x, y, i;

  do
  {
    printf("\n1 Input Restricted Dequeue \n2 Output Restricted Dequeue\n");
    printf("Enter your Choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
      printf("Enter the max size:");
      scanf("%d", &n);
      printf("\nMENU\n1 Insertion through rear \n2 Deletion through front \n3 Deletion through rear \n4 Display\n5 exit\n");
      do
      {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
          if ((F == 0 && R == n - 1) || (F == R + 1)) // insertion through rear
          {
            printf("Dequeue overflow\n");
            break;
          }
          else
          {
            if (F == -1)
            {
              F = 0;
              R = 0;
            }
            else if (R == n - 1)
            {
              R = 0;
            }
            else
            {
              R = R + 1;
            }
          }
          printf("Enter new element:");
          scanf("%d", &x);
          Q[R] = x;
          break;
        case 2: // deletion through front
          if (F == -1)
          {
            printf("Dequeue underflow\n");
            break;
          }
          else
          {
            y = Q[F];
            printf("The deleted element is %d", y);
            if (F == R)
            {
              F = -1;
              R = -1;
            }
            else if (F == n - 1)
            {
              F = 0;
            }
            else
            {
              F = F + 1;
            }
          }
          break;
        case 3: // Deletion through rear
          if (F == -1)
          {
            printf("Dequeue overflow\n");
            break;
          }

          else
          {
            y = Q[R];
            printf("The deleted element is %d", y);
            if (F == R)
            {
              F = -1;
              R = -1;
            }
            else if (R == 0)
            {
              R = n - 1;
            }
            else
            {
              R = R - 1;
            }
          }
          break;
        case 4: // Display
          if (F == -1)
          {
            printf("Circular Queue is empty");
            break;
          }
          if (F <= R)
          {
            for (i = F; i <= R; i++)
            {
              printf("%d ", Q[i]);
            }
          }
          else
          {
            for (i = F; i <= n; i++)
              printf("%d ", Q[i]);
            for (i = 0; i <= R; i++)
              printf("%d ", Q[i]);
          }
          break;
        case 5:
          break;
        default:
          printf("Invalid choice");
        }
      } while (ch != 5);
    }
    else if (choice == 2) // OUTPUT RESTRICTED DEQUEUE
    {
      printf("Enter the max size");
      scanf("%d", &n);
      printf("\nMENU\n1 Insertion through rear \n2 Deletion through front \n3 Insertion through front \n4 Display\n5 exit\n");
      do
      {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
          if ((F == 0 && R == n - 1) || (F == R + 1)) // insertion through rear
          {
            printf("Dequeue overflow\n");
            break;
          }
          else
          {
            if (F == -1)
            {
              F = 0;
              R = 0;
            }
            else if (R == n - 1)
            {
              R = 0;
            }
            else
            {
              R = R + 1;
            }
          }
          printf("Enter new element:");
          scanf("%d", &x);
          Q[R] = x;
          break;
        case 2: // deletion through front
          if (F == -1)
          {
            printf("Dequeue underflow\n");
            break;
          }
          else
          {
            y = Q[F];
            printf("The deleted element is %d", y);
            if (F == R)
            {
              F = -1;
              R = -1;
            }
            else if (F == n - 1)
            {
              F = 0;
            }
            else
            {
              F = F + 1;
            }
          }
          break;
        case 3: // Insertion through front
          if ((F == 0 && R == n - 1) || (F == R + 1))
          {
            printf("\nDequeue OVERFLOW");
            break;
          }
          else
          {
            if (F == -1)
            {
              F = 0;
              R = 0;
            }
            else if (F == 0)
            {
              F = n - 1;
            }
            else
            {
              F = F - 1;
            }
          }
          printf("Enter new element:");
          scanf("%d", &x);
          Q[F] = x;
        case 4: // Display
          if (F == -1)
          {
            printf("Circular Queue is empty");
            break;
          }
          if (F <= R)
          {
            for (i = F; i <= R; i++)
            {
              printf("%d ", Q[i]);
            }
          }
          else
          {
            for (i = F; i <= n; i++)
              printf("%d ", Q[i]);
            for (i = 0; i <= R; i++)
              printf("%d ", Q[i]);
          }
          break;
        case 5:
          break;
        default:
          printf("Invalid choice");
        }
      } while (ch != 5);
    }
  } while (choice <= 2);
}
