#include <stdio.h>
#define SIZE 5

void enQueue(int data);
void deQueue();
void display();

int arr[SIZE], front = -1, rear = -1;

int isFull()
{
    return (rear == SIZE - 1) ? 1 : 0;
}

void enQueue(int value)
{
    if (isFull())
    {
        printf("\n Queue is Full");
    }

    if (front == -1)
    {
        front = 0;
    }
    rear++;
    arr[rear] = value;
    printf("\nInserted %d", value);
}

void deQueue() {
    if (front == -1)
    {
        printf("\nQueue is Empty");
    }
    printf("\ndeleted %d", arr[front]);
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

void display()
{
    if (rear == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            printf("\n%d", arr[i]);
        }
    }
}

int main()
{
    deQueue();

    enQueue(21);
    enQueue(20);
    enQueue(22);
    enQueue(25);
    enQueue(26);

    display();

    return 0;
}