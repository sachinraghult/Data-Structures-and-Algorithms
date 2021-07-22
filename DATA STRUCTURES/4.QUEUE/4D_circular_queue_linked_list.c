#include <stdio.h>
#include <stdlib.h>

struct queue{
	int key;
	int data;
	struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void menu_card();
struct queue *getNode();
struct queue *key_check(int);

int isEmpty();
void enqueue();
void dequeue();
void peek();
void change();
void count();
void display();
void destroy();

int main()
{
	int option;
	
	do
	{
		menu_card();
		
		scanf("%d",&option);
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				enqueue();
				break;
				
			case 2:
				dequeue();
				break;
				
			case 3:
				
				if(isEmpty())
					printf("Queue is empty \n");
				else
					printf("Queue is not empty \n");
				break;
				
			case 4:
				peek();
				break;
				
			case 5:
				change();
				break;
				
			case 6:
				count();
				break;
				
			case 7:
				display();
				break;
				
			case 8:
				destroy();
				exit(1);
				
			default:
				printf("Enter proper option number \n");
		}
		
	}while(option != 0);
	
	destroy();
	
	printf("\nEND \n\n");
	
	return 0;
}

void menu_card()
{

		printf("\nEnter the option from the list(1 to 8) to perform that specific operation , and Enter 0 to exit : \n");
		printf("1. Enqueue()\n");
		printf("2. Dequeue()\n");
		printf("3. isEmpty()\n");
		printf("4. Peek()\n");
		printf("5. change()\n");
		printf("6. count()\n");
		printf("7. display()\n");
		printf("8. destroy()\n");
}

struct queue *getNode()
{
	struct queue *ptr;
	ptr = (struct queue*)malloc(sizeof(struct queue));
	
	if(ptr == NULL)
	{
		printf("Memory Unavailable \n");
		exit(0);
	}
	
	printf("Enter the unique key and data for the new Node : \n");
	scanf("%d %d", &ptr->key, &ptr->data);
	
	ptr->next = NULL;
	
	return ptr;
}

int isEmpty()
{
	if(front == NULL && rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct queue *key_check(int key)
{
	struct queue *temp = front;
	
	if(temp == NULL)
	{
		return temp;
	}
	do
	{
		if(temp->key == key)
		{
			return temp;
		}
		temp = temp->next;
		
	}while(temp != front);
	
	return NULL;
}

void enqueue()
{
	printf("\nENQUEUE \n\n");
	
	struct queue *newNode = getNode(), *temp = NULL;
	
	if(isEmpty())
	{
		front = newNode;
		rear = newNode;
		rear->next = rear;
	}
	else if(key_check(newNode->key) != NULL)
	{
		printf("Node already exists with the key value \n");
		return;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
		newNode->next = front;
	}
	
	printf("Enqueue operation sucessfull! \n");
}

void dequeue()
{
	printf("\nDEQUEUE \n\n");
	
	struct queue *temp = NULL;
	
	if(isEmpty())
	{
		printf("Queue Underflow \n");
	}
	else
	{
		if(front == rear)
		{
			temp = front;
			front = NULL;
			rear = NULL;
		}
		else
		{
			temp = front;
			front = front->next;
			rear->next = front;
		}
		printf("Dequeue operation with node of key %d is successfull! \n", temp->key);
	}
}

void peek()
{
	printf("\nPEEK \n\n");
	
	if(isEmpty())
	{
		printf("Queue Underflow \n");
	}
	else
	{
		printf("Front : (%d , %d) \n", front->key, front->data);
	}
}

void change()
{
	printf("\nCHANGE \n\n");
	
	if(isEmpty())
	{
		printf("Queue Underflow \n");
		return;
	}
	
	int key, data;
	
	struct queue *temp = front;
	
	printf("Enter the existing key and data to be changed : \n");
	scanf("%d %d", &key, &data);
	
	if(key_check(key) == NULL)
	{
		printf("Node doesn't exist with the given key \n");
	}
	else
	{
		do
		{
			if(temp->key == key)
			{
				temp->data = data;
				printf("Now the node with key %d is updated with data %d", temp->key, temp->data);
				return;	
			}
			temp = temp->next;
			
		}while(temp != front);
	}
}

void count()
{
	printf("\nCOUNT \n\n");
	
	int count = 0;
	
	struct queue *temp = front;
	
	if(temp == NULL);
	else
	{
	    do
	    {
		    count++;
		    temp = temp->next;
		
        }while(temp != front);
    }
	
    printf("%d \n",count);
}

void display()
{
	struct queue *temp = front;
	
	printf("\nDISPLAY CIRCULAR QUEUE \n\n");
	if(isEmpty())
	{
		printf("Queue is empty \n");
	}
	else
	{
		do
		{
			printf("(%d , %d)-->", temp->key, temp->data);
			temp = temp->next;
		
		}while(temp != front);
	
		printf("(%d , %d)", front->key, front->data);
	}
}

void destroy()
{
	struct queue *temp = front, *current = NULL;
	
	do
	{
		current = temp;
		temp = temp->next;
		free(current);
		current = NULL;
	}while(temp != front);
	
	front = NULL;
	rear = NULL;
	
	printf("\nQUEUE DESTROYED SUCCESSFULLY!!! \n");
}
