//C program to create a STACK using array data structure and implement the operations PUSH, POP and TRAVESE.

#include<stdio.h>
#define max 5
int stack[max];
int top=-1;
void push();
void pop();
void traversal();
int main()
{       
	int choice;
	printf("1.push\n2.pop\n3.traversal\n4.exit\n");
	do
	{
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:traversal();
			break;
			case 4:printf("program exited\n");
			break;
			default:printf("wrong choice\n");
			break;

		}


	}while(choice !=4);
}

void push()
{    
int element;
if(top==max-1)
{
	printf("stack overflow");
}
else
{    
	printf("enter the element");
	scanf("%d",&element);
	top++;
	stack[top]=element;

}

}
void pop()
{
	int element;
	if(top==-1)
	{
		printf("STACK EMPTY");
	}
	else
	{
		element=stack[top];
		top--;
		printf("element deleted is %d",element);
	}
}
void traversal()
{    
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d",stack[i]);
	}
}
