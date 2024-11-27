#include <stdio.h>
int main(){
	int range, sum = 0;
	printf("Enter the range of numbers you want to get sum of\n");
	scanf("%d",&range);
	for(int i = 1; i <= range; i++)
		sum = sum + i;
	printf("Sum of %d numbers  is %d\n",range, sum);
}
