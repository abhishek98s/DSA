#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtStart(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtLocation(struct Node** head, int data, int position)
{
    struct Node* newNode = createNode(data);
    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int currentPosition = 0;

    while (currentPosition < position - 1 && current->next != NULL)
    {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void display(struct Node* head)
{
    struct Node* current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteAtStart(struct Node** head)
{
    if (*head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next; 
}

void deleteAtEnd(struct Node** head)
{
    if (*head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    current->next = NULL;
}

void deleteAtLocation(struct Node** head, int position)
{
    if (*head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position)
    {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (previous == NULL)
    {
        *head = current->next;
    }
    else
    {
        previous->next = current->next;
    }
}

int main()
{
    struct Node* head = NULL;

    insertAtStart(&head, 13);
    insertAtStart(&head, 53);
    insertAtLocation(&head, 5, 1);

    display(head);

    deleteAtStart(&head);
    display(head);

    deleteAtEnd(&head);
    display(head);

    deleteAtLocation(&head, 0);
    display(head);

    return 0;
}