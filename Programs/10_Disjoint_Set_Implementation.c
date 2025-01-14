//Write a C program to implement Disjoint data structure using an array and perform operations such as MakeSet, FindSet and Union (using union-rank algorithm)


#include <stdio.h>
#define MAX 100
int rank[MAX]; 


void makeset(int n) {

	for (int i = 1; i <= n; i++) {

		rank[i] = -1; 

	}
	printf("after makeset rank matrix is :");
	for (int i = 1; i <= n; i++) {

		printf("%d",rank[i]);

	}

}



int findset(int x) {

	if (rank[x] < 0) {
		return x; 

	}


	rank[x] = findset(rank[x]);
	return rank[x];

}



void unionByRank(int x, int y) {

	int rootX = findset(x);
	int rootY = findset(y);
	if (rootX != rootY) {

		if (rank[rootX] <= rank[rootY]) { 

		    rank[rootX] += rank[rootY]; 

		    rank[rootY] = rootX; 

		} else {

		    rank[rootY] += rank[rootX]; 

		    rank[rootX] = rootY; 

		}

	}

}

 
 
 
void printRanks(int n) {

    printf("Rank Array: ");

    for (int i = 1; i <= n; i++) {

        printf("%d ", rank[i]);

    }

    printf("\n");

}



 int main() {

	int n, choice, x, y;
	printf("Enter the number of elements: ");

	scanf("%d", &n);



	



	while (1) {

		printf("\nMenu:\n");
		printf("1. make-Set\n");
		printf("2. Find-Set\n");
		printf("3. Union\n");
		printf("4. Print Rank Array\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);



		switch (choice) {
			case 1:makeset(n);
				break;
			case 2:

			printf("Enter element to find its set: ");
			scanf("%d", &x);
			printf("Representative of %d is %d\n", x, findset(x));
			break;

			case 3:

			printf("Enter two elements to perform union: ");
			scanf("%d %d", &x, &y);
			unionByRank(x, y);
			break;

			case 4:

			printRanks(n);
			break;

			case 5:
			printf(“exiting”);
			break;

			default:
			printf("Invalid choice! Try again.\n");

		}

	}



	    return 0;

}

