#include <stdio.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

int isEmpty();
int isFull();


void push(int item)
{
    if (isFull())
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = item;
        printf("Push %d to the stack\n", item);
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
    }
    else
    {
        int item = stack[top];
        top--;
        return item;
    }
}

int isEmpty()
{
    return (top == -1) ? 1 : 0;
}

int isFull()
{
    return (top == MAX_SIZE - 1) ? 1 : 0;
}

int peek()
{
    if (isEmpty())
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("top element %d\n", peek());

    printf("popped element: %d\n", pop());
    printf("popped element: %d\n", pop());

    printf("stack empty?%s", isEmpty() ? "yes" : "no");    
    printf("stack full?%s", isFull() ? "yes" : "no");
    
    return 0;
}