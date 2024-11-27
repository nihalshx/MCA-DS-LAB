#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the size of the Circular Queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to add an element to the queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", element);
        return;
    }
    
    if (front == -1) {
        front = rear = 0;  // Initialize front and rear to 0 for the first element
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;  // Wrap around
    } else {
        rear++;  // Increment rear normally
    }
    
    queue[rear] = element;
    printf("Enqueued %d to the queue.\n", element);
}

// Function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    
    int data = queue[front];
    
    if (front == rear) {  // Queue has only one element
        front = rear = -1;  // Reset the queue
    } else if (front == MAX - 1) {
        front = 0;  // Wrap around
    } else {
        front++;  // Increment front normally
    }
    
    printf("Dequeued %d from the queue.\n", data);
    return data;
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements are: ");
    
    if (front <= rear) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
