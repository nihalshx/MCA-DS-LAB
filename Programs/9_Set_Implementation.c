//Write a C program to implement Set data structure using Bit Vector representation and perform operations such Union, Intersection, Set Complement and Set Difference.

#include <stdio.h>
#include <string.h>
#define MAX 32  
void initializeBitVector(int bitVector[], int size) {
	for (int i = 0; i < size; i++) {
		bitVector[i] = 0;  
	}
}
 
void displayBitVector(int bitVector[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", bitVector[i]);
	}
	printf("\n");
}
 
void displaySet(int bitVector[], int size, char universalSet[]) {
	printf("{ ");
	for (int i = 0; i < size; i++) {
		if (bitVector[i] == 1)
		    printf("%c ", universalSet[i]); 
	}
	printf("}\n");
}
 
void unionSet(int set1[], int set2[], int result[], int size) {
	for (int i = 0; i < size; i++) {
		result[i] = set1[i] | set2[i];
	}
}
 
void intersectionSet(int set1[], int set2[], int result[], int size) {
	for (int i = 0; i < size; i++) {
		result[i] = set1[i] & set2[i];
	}
}
 
void complementSet(int set[], int result[], int size) {
	for (int i = 0; i < size; i++) {
		if (set[i] == 0)
		    result[i] = 1;
		else
		    result[i] = 0;
	}
}
 
void differenceSet(int set1[], int set2[], int result[], int size) {
	for (int i = 0; i < size; i++) {
		result[i] = set1[i] & !set2[i];
	}
}
 
void setToBitVector(char set[], int bitVector[], int setSize, int universalSize, char universalSet[]) {
	initializeBitVector(bitVector, universalSize); 
	for (int i = 0; i < setSize; i++) {
		for (int j = 0; j < universalSize; j++) {
			if (set[i] == universalSet[j]) {  
				bitVector[j] = 1; 
				break;
			}
		}
	}
}
 
int main() {
	char universalSet[MAX], set1[MAX], set2[MAX];
	int bitVector1[MAX], bitVector2[MAX], result[MAX];
	int sizeU, size1, size2;
	int choice;

	printf("Enter the size of the universal set (max %d): ", MAX);
	scanf("%d", &sizeU);
	if (sizeU > MAX || sizeU <= 0) {
		printf("Invalid size for the universal set. Exiting.\n");
		return 1;
	}

	printf("Enter the elements of the universal set (characters): ");
	for (int i = 0; i < sizeU; i++) {
		scanf(" %c", &universalSet[i]); 
	}

	printf("Enter the size of Set 1: ");
	scanf("%d", &size1);
	printf("Enter the elements of Set 1 (characters): ");
	for (int i = 0; i < size1; i++) {
		scanf(" %c", &set1[i]);
	}

	printf("Enter the size of Set 2: ");
	scanf("%d", &size2);
	printf("Enter the elements of Set 2 (characters): ");
	for (int i = 0; i < size2; i++) {
		scanf(" %c", &set2[i]);
	}


	setToBitVector(set1, bitVector1, size1, sizeU, universalSet);
	setToBitVector(set2, bitVector2, size2, sizeU, universalSet);

	printf("\nBit Vector Representation of Set 1: ");
	displayBitVector(bitVector1, sizeU);
	printf("Set 1: ");
	displaySet(bitVector1, sizeU, universalSet);

	printf("\nBit Vector Representation of Set 2: ");
	displayBitVector(bitVector2, sizeU);
	printf("Set 2: ");
	displaySet(bitVector2, sizeU, universalSet);

	do {
		printf("\nMenu:\n");
		printf("1. Union\n");
		printf("2. Intersection\n");
		printf("3. Complement of Set 1\n");
		printf("4. Complement of Set 2\n");
		printf("5. Difference (Set 1 - Set 2)\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
			unionSet(bitVector1, bitVector2, result, sizeU);
			printf("Union Bit Vector: ");
			displayBitVector(result, sizeU);
			printf("Union Set: ");
			displaySet(result, sizeU, universalSet);
			break;

			case 2:
			intersectionSet(bitVector1, bitVector2, result, sizeU);
			printf("Intersection Bit Vector: ");
			displayBitVector(result, sizeU);
			printf("Intersection Set: ");
			displaySet(result, sizeU, universalSet);
			break;

			case 3:
			complementSet(bitVector1, result, sizeU);
			printf("Complement of Set 1 Bit Vector: ");
			displayBitVector(result, sizeU);
			printf("Complement of Set 1: ");
			displaySet(result, sizeU, universalSet);
			break;

			case 4:
			complementSet(bitVector2, result, sizeU);
			printf("Complement of Set 2 Bit Vector: ");
			displayBitVector(result, sizeU);
			printf("Complement of Set 2: ");
			displaySet(result, sizeU, universalSet);
			break;

			case 5:
			differenceSet(bitVector1, bitVector2, result, sizeU);
			printf("Difference (Set 1 - Set 2) Bit Vector: ");
			displayBitVector(result, sizeU);
			printf("Difference (Set 1 - Set 2): ");
			displaySet(result, sizeU, universalSet);
			break;

			case 6:
			printf("Exiting program.\n");
			break;

			default:
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 6);

	return 0;
}
