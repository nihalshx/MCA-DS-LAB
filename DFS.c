//Write a C program to represent a Graph using adjacency matrix and implement Depth First Search (DFS) algorithm.
#include <stdio.h>
int Adjmat[10][10]; // Adjacency matrix, size increased for flexibility
int visit[10];      // Array to keep track of visited nodes
int stack[10];
int top = -1;
int n; // Number of nodes

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == n - 1;
}

void push(int element) {
    if (isFull()) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = element;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

void dfs(int startNode) {
    push(startNode);
    printf("DFS Traversal: ");

    while (!isEmpty()) {
        int currentNode = pop();

        if (!visit[currentNode]) {
            printf("%d ", currentNode + 1); // Printing nodes as 1-based index
            visit[currentNode] = 1;

            // Push all adjacent vertices of the current node into the stack
            for (int i = 0; i < n; i++) {
                if (Adjmat[currentNode][i] == 1 && !visit[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize the visit array
    for (int i = 0; i < n; i++) {
        visit[i] = 0;
    }

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Adjmat[i][j]);
        }
    }

    printf("Enter the starting node (1-based index): ");
    scanf("%d", &startNode);

    // Convert to 0-based index for internal processing
    dfs(startNode - 1);

    return 0;
}