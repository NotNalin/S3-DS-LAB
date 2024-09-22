// S3R2-41
#include <stdio.h>
void main()
{
    int r, c, i, j, p, n, count = 0;
    int sp[10][10];
    int ER[10][3];
    printf("Enter row and column of sparse matrix");
    scanf("%d%d", &r, &c);
    printf("Enter the elements : ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &n);
            sp[i][j] = n;
            if (n != 0)
            {
                count++;
            }
        }
    }
    ER[0][0] = r;
    ER[0][1] = c;
    ER[0][2] = count;
    p = 1;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (sp[i][j] != 0)
            {
                ER[p][0] = i;
                ER[p][1] = j;
                ER[p][2] = sp[i][j];
                p++;
            }
        }
    }
    printf("Effective representation of the sparse matrix is \n");
    for (i = 0; i < count + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", ER[i][j]);
        }
        printf("\n");
    }
}
