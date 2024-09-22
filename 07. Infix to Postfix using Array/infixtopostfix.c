#include <stdio.h>

int prec(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void main()
{
    char infix[100], postfix[100], stack[100];
    int j = 0, top = -1, i;
    printf("Enter the infix expression ");
    scanf("%s", infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(' && top != -1)
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '^'))
        {
            while ((prec(stack[top]) >= prec(infix[i])) && top != -1)
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else
        {
            postfix[j++] = infix[i];
        }
    }
    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("Postfix expression : %s \n", postfix);
}
