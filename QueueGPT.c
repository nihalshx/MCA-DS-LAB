#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size = 5, item, arr_queue[5];

// Function to check if the queue is full
int isFull() {
    return (front == 0 && rear == size - 1) || (front == rear + 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Enqueue function
void enqueue() {
    if (isFull()) {
        printf("Overflow! Queue is full.\n");
    } else {
        printf("Enter your Item: ");
        scanf("%d", &item);
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;  // Wrap around rear using modulo
        arr_queue[rear] = item;
        printf("Enqueued %d\n", item);
    }
}

// Dequeue function
void dequeue() {
    if (isEmpty()) {
        printf("Underflow! Queue is empty.\n");
    } else {
        item = arr_queue[front];
        printf("Dequeued item is %d\n", item);
        if (front == rear) {  // Queue becomes empty after this dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % size;  // Wrap around front using modulo
        }
    }
}

// Display function
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d\t", arr_queue[i]);
            }
        } else {
            for (int i = front; i < size; i++) {
                printf("%d\t", arr_queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d\t", arr_queue[i]);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;
    printf("You've got a Circular Queue of Size %d\n", size);
    while (1) {
        printf("1. Enqueue\t 2. Dequeue\t 3. Display\t 4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
