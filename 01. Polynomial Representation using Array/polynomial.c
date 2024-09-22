// S3R2-41
#include <stdio.h>
struct poly
{
    int coeff;
    int expo;
};
void main()
{
    int i, n, j, t, c;
    printf("enter the no of terms in polynomial:");
    scanf("%d", &n);
    struct poly p[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the coeff & its power for term %d:", i + 1);
        scanf("%d%d", &p[i].coeff, &p[i].expo);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (p[j].expo < p[j + 1].expo)
            {
                t = p[j].expo;
                p[j].expo = p[j + 1].expo;
                p[j + 1].expo = t;
                c = p[j].coeff;
                p[j].coeff = p[j + 1].coeff;
                p[j + 1].coeff = c;
            }
        }
    }
    printf("The polynomial is: ");
    for (i = 0; i < n; i++)
    {
        printf("%dx^%d", p[i].coeff, p[i].expo);
        if (i != n - 1)
        {
            printf("+");
        }
    }
}
