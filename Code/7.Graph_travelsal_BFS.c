#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Queue structure for BFS
typedef struct Queue {
    int front, rear;
    int items[MAX_VERTICES];
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAX_VERTICES == q->front;
}

// Enqueue an item
void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_VERTICES;
    q->items[q->rear] = item;
}

// Dequeue an item
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_VERTICES;
    }
    return item;
}

// Perform BFS
void bfs(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue q;
    initQueue(&q);

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
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

    bfs(&g, 0);
    return 0;
}