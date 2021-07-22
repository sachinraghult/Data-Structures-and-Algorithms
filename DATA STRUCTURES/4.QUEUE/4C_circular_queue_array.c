#include <stdio.h>
#include <stdlib.h>

struct queue{
	int *arr;
	int front;
	int rear;
	int N;
}p;

static int size = 0;

void queue_initial();
void menu_card();

int isEmpty();
int isFull();
void enqueue(int val);
int dequeue();
int peek(int pos);
int count();
void change(int pos, int val);
void display();

int main()
{
	queue_initial();
	
	int option, position, value;
	
	do
	{
		menu_card();
		
		scanf("%d",&option);
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				printf("Enter the value to enqueue : ");
				scanf("%d",&value);
				enqueue(value);
				break;
				
			case 2:
				printf("Dequeue function is called . Dequeued value is %d\n",dequeue());
				break;
				
			case 3:
				if(isEmpty())
				{
					printf("Queue is empty\n");
				}
				else
				{
					printf("Queue is not empty\n");
				}
				break;
				
			case 4:
				if(isFull())
				{
					printf("Queue is full\n");
				}
				else
				{
					printf("Queue is not full\n");
				}
				break;
				
			case 5:
				printf("Enter the position in which the value to be displayed : \n");
				scanf("%d",&position);
				printf("Peek function is called - The value at position %d is %d \n", position, peek(position));
				break;
				
			case 6:
				printf("Count function called - Count of queue is %d \n",count());
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

void queue_initial()
{
	int size;
	
	printf("Enter the maximum size of the queue : \n");
	scanf("%d",&size);
	
	p.front = -1;
	p.rear = -1;
	p.N = size;
	p.arr = (int*)calloc(p.N , sizeof(int));
}

void menu_card()
{

		printf("\nEnter the option from the list(1 to 8) to perform that specific operation , and Enter 0 to exit : \n");
		printf("1. Enqueue()\n");
		printf("2. Dequeue()\n");
		printf("3. isEmpty()\n");
		printf("4. isFull()\n");
		printf("5. Peek()\n");
		printf("6. count()\n");
		printf("7. change()\n");
		printf("8. display()\n");
}

int isEmpty()
{
	if(p.front == -1 && p.rear == -1)
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
	if((p.rear+1)%p.N == p.front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(int val)
{
	if(isFull())
	{
		printf("Queue is full\n");
		return;
	}
	else if(isEmpty())
	{
		p.front = 0;
		p.rear = 0;
	}
	else
	{
		p.rear = (p.rear+1)%p.N;
	}
	p.arr[p.rear] = val;
	size++;
}

int dequeue()
{
	int x;
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		return;
	}
	else if(p.front == p.rear)
	{
		x = p.arr[p.front];
		p.arr[p.front] = 0;
		p.front = -1;
		p.rear = -1;
	}
	else
	{
		x = p.arr[p.front];
		p.arr[p.front] = 0;
		p.front = (p.front+1)%p.N;
	}
	size--;
	return x;
}

int peek(int pos)
{
	return p.arr[pos];
}

int count()
{
	return size;
}

void change(int pos, int val)
{
	if(pos >= size)
	{
		printf("Invalid entry \n");
		return;
	}
	p.arr[pos] = val;
	printf("The value at the position %d now is %d", pos, p.arr[pos]);
}

void display()
{
	printf("Queue elements are : \n");
	int i;
	for(i = 0;i < p.N;i++)
	{
		printf("%d ",p.arr[i]);
	}
}
