//C program to find the sum of 'n' numbers.

#include<stdio.h>
int main()
{       
	int sum=0,n;
	int a[10];
	printf("enter the no of elements");
	scanf("%d",&n);
	printf("enter the array elements");
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&a[i]);
		
	}
	for(int i=0;i<n;i++)
	{	
		sum=sum+a[i];
		
	}
	printf("sum of the array elements are");
	printf("%d",sum);
	return (0);
		
}
