#include<stdio.h>
#include<conio.h>
#include<string.h>

char stack[30];
int top = -1;
void intopost(char *);
char pop();
int prec(char);
void main()
{
    char infix  [50];
    printf("Enter the INFIX Expression\n\n");
    gets(infix);
    intopost(infix);
    getch();
}

void push(char sym){
    if (top>=30){
        printf("stack Overflow\n");
        getch();
        return;
    }
    else
    {
        top++;
        stack[top]=sym;
    }
}

char pop()
{
    char  x;
    if (top<=-1)
    {
        printf("\nStack is Empty");
        getch();
        return 0;
    }
    else {
        x  = stack[top]; // this have semicolon
        top--;

    }
    return (x);
}

int prec (char ch)
{
    if(ch == '^')
    return (5);
    else if (ch == '*'|| ch == '/')
    return (4);
    else if (ch == '+' || ch == '-')
    return (3);
    else 
    return (2);

}

void intopost(char infix[])
{
    int length;
    static int index = 0, pos = 0;
    char postfix[50];
    char symbol,temp;
    length = strlen (infix);
    while (index < length)
    {
        symbol = infix[index];
        switch(symbol)
        {
            case '(':
            push (symbol);
            break;
            case ')':
            temp = pop();
            while (temp != '(')
            {
                postfix[pos]=temp;
                pos++;
                temp=pop();
            }
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            
            while ( prec(stack[top]) >= prec(symbol))
            {
                temp = pop();
                postfix[pos] = temp;
                pos++;

            }
            push(symbol);
            break;
            default: 
            postfix[pos++]=symbol;
            break;

        }
        index++;
    }
    while(top>=0)
    {
        temp = pop();
        postfix[pos++]=temp;

    }
    postfix[pos++]='\0';
    printf("\nPostfix Exression\n");
    printf(postfix);
    getch();

}