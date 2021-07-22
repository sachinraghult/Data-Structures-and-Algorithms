#include <stdio.h>
#include <stdlib.h>

struct stack{
	int *arr;
	int top;
	int N;
}p;

void stack_initial();
void MenuCard();

int isEmpty();
int isFull();
void push(int val);
int pop();
int peek(int pos);
int count();
void change(int pos, int val);
void display();

int main()
{
	stack_initial();
	
	int option, position, value;
	
	do
	{
		MenuCard();
		
		scanf("%d",&option);
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				printf("Enter the value to push into the stack : ");
				scanf("%d",&value);
				push(value);
				break;
				
			case 2:
				printf("Pop function is called . Popped value is %d\n",pop());
				break;
				
			case 3:
				if(isEmpty())
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("Stack is not empty\n");
				}
				break;
				
			case 4:
				if(isFull())
				{
					printf("Stack is full\n");
				}
				else
				{
					printf("Stack is not full\n");
				}
				break;
				
			case 5:
				printf("Enter the position in which the value to be displayed : \n");
				scanf("%d",&position);
				printf("Peek function is called - The value at position %d is %d \n", position, peek(position));
				break;
				
			case 6:
				printf("Count function called - Count of stack is %d \n",count());
				break;
				
			case 7:
				printf("Enter the position at which the value to be changed : \n");
				scanf("%d",&position);
				printf("Enter the value that is to be replaced at that position : \n");
				scanf("%d",&value);
				change(position, value);
				break;
				
			case 8:
				printf("Display function called \n");
				display();
				break;
				
			default:
				printf("Enter proper option number \n");
		}
		
	}while(option != 0);
	
	return 0;
}

void stack_initial()
{
	int size;
	
	printf("Enter the maximum size of the stack : \n");
	scanf("%d",&size);
	
	p.top = -1;
	p.N = size;
	p.arr = (int*)calloc(p.N , sizeof(int));
}

void MenuCard()
{

		printf("\nEnter the option from the list(1 to 8) to perform that specific operation , and Enter 0 to exit : \n");
		printf("1. Push()\n");
		printf("2. Pop()\n");
		printf("3. isEmpty()\n");
		printf("4. isFull()\n");
		printf("5. Peek()\n");
		printf("6. count()\n");
		printf("7. change()\n");
		printf("8. display()\n");
}

int isEmpty()
{
	if(p.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull()
{
	if(p.top == p.N-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int val)
{
	if(isFull())
	{
		printf("Stack Overflow\n");
	}
	else
	{
		p.arr[++p.top] = val;
	}
}

int pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
	}
	else
	{
		int popValue = p.arr[p.top];
		p.arr[p.top--] = 0;
		return popValue;
	}	
}

int peek(int pos)
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		return 0;
	}
	else
	{
		return p.arr[pos];
	}
}

int count()
{
	return p.top+1;
}

void change(int pos, int val)
{
	p.arr[pos] = val;
	printf("The value at position %d is %d", pos, p.arr[pos]);
}

void display()
{
	printf("Stack elemnts are : \n");
	int i;
	for(i = p.N-1;i >= 0;i--)
	{
		printf("%d ",p.arr[i]);
	}
}
