#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Stack structure for DFS
typedef struct Stack {
    int top;
    int items[MAX_VERTICES];
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX_VERTICES - 1;
}

// Push an item onto the stack
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

// Pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Perform DFS
void dfs(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Stack s;
    initStack(&s);

    visited[startVertex] = 1;
    printf("%d ", startVertex);
    push(&s, startVertex);

    while (!isEmpty(&s)) {
        int currentVertex = pop(&s);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                push(&s, i);
            }
        }
    }
}

int main() {
    Graph g;
    g.numVertices = 7;

    // Adjacency matrix representation of the graph
    int adjacencyMatrix[7][7] = {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0}
    };

    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            g.adjMatrix[i][j] = adjacencyMatrix[i][j];
        }
    }

    dfs(&g, 0);
    return 0;
}