//Write a C program to represent a Graph using adjacency matrix and implement Breadth First Search (BFS) algorithm.

#include <stdio.h>

#define MAX_NODES 10 // Maximum number of nodes
int Adjmat[MAX_NODES][MAX_NODES]; // Adjacency matrix
int visit[MAX_NODES] = {0};       // Array to keep track of visited nodes
int queue[MAX_NODES];             // Queue for BFS
int front = -1;
int rear = -1;
int n;                            // Number of nodes

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX_NODES - 1;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = element;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return element;
}

void bfs(int startNode) {
    enqueue(startNode);
    visit[startNode] = 1;
    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode + 1); // Printing nodes as 1-based index

        for (int i = 0; i < n; i++) {
            if (Adjmat[currentNode][i] == 1 && visit[i] == 0) {
                enqueue(i);
                visit[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int startNode;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Adjmat[i][j]);
        }
    }

    // Input starting node
    printf("Enter the starting node (1 to %d): ", n);
    scanf("%d", &startNode);
    startNode--; // Convert to 0-based index

    // Perform BFS
    bfs(startNode);

    return 0;
}