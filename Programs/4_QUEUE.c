//C program to create a QUEUE using array data structure and implement the operations ENQUEUE, DEQUEUE and TRAVERSE.C program to create a QUEUE using array data structure and implement the operations ENQUEUE, DEQUEUE and TRAVERSE.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 
int queue[SIZE];
int front = -1; 
int rear = -1; 
int isFull() {
	return rear == SIZE - 1;
}
int isEmpty() {
	return front == -1 || front > rear;

}

void enqueue(int value) {
	if (isFull()) {
		printf("Queue is full.\n");

	} else 

	{

		if (front == -1) 
		front = 0;
		rear++;
		queue[rear] = value;
		printf("Enqueued %d.\n", value);
}

}

 

int dequeue() {
	int value;
	if (isEmpty()) {
		printf("Queue is empty.\n");

	} else {
		value = queue[front];
		front++; 
		printf("Dequeued %d.\n", value);
		return value;
	}
}

 

 

void display() {
	if (isEmpty()) {
		printf("Queue is empty.\n");
	} else 
	{
		printf("Queue elements are: ");
		for (int i = front; i <= rear; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");
	}

}

int main() {
int choice, value;
while (1) {
	printf("\n--- Linear Queue Menu ---\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
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
		printf("Exiting program.\n");
		exit(0);
		default:
		printf("Invalid choice! Please select a valid option.\n");
	}
}
return 0;
}
