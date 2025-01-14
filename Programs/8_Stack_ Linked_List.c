//Write a C program to implement Stack using Single Linked List


#include <stdio.h>
#include <stdlib.h>
struct Node {

	int data;
	struct Node* next;

};
struct Node* top = NULL; 
int size = 0; 
int maxSize = 5; 
int isEmpty() {

	return size == 0;

}
int isFull() {

	return size == maxSize;

}

void push(int data) {

	if (isFull()) {
		printf("Stack Overflow! Cannot push %d\n", data);
		return;

	}

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) {

		printf("Memory allocation failed\n");
		return;

	}

	newNode->data = data;
	newNode->next = top;
	top = newNode;
	size++;
	printf("Pushed %d onto the stack\n", data);

}

int pop() {

	if(isEmpty()) {
		printf("Stack Underflow! Cannot pop\n");
		return -1;
	}
	struct Node* temp = top;
	int poppedData = temp->data;
	top = temp->next;
	free(temp);
	size--;
	return poppedData;

}

 



void display() {

	if (isEmpty()) {
		printf("Stack is empty\n");
		return;
	}
	struct Node* current = top;
	printf("Stack elements: ");
	while (current) {
		printf("%d ", current->data);
		current = current->next;

	}

	printf("\n");

}

 int main() {

	int choice, element;
	do {
		printf("\nMenu:\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the element to push: ");
			scanf("%d", &element);
			push(element);
			break;
		case 2:
			element = pop();
			if (element != -1) {
			printf("Popped element: %d\n", element);
			}
			break;
		case 3:
			display();
			break;
		case 4:
				printf("Exiting...\n");
				break;
				default:
			printf("Invalid choice! Please try again.\n");

		}

	}while (choice != 4);
	return 0;

}
