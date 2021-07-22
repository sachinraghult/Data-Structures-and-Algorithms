#include <stdio.h>
#include <stdlib.h>

struct stack{
	int key;
	int data;
	struct stack *next;
};

struct stack *top = NULL;

void MenuCard();
struct stack *getNode();
struct stack *key_check(int);

int isEmpty();
void push();
void pop();
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
		MenuCard();
		
		scanf("%d",&option);
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				push();
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				
				if(isEmpty())
					printf("Stack is empty \n");
				else
					printf("Stack is not empty \n");
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
				break;
				
			default:
				printf("Enter proper option number \n");
		}
		
	}while(option != 0);
	
	destroy();
	
	printf("\nSESSION END \n\n");
	
	return 0;
}

void MenuCard()
{

		printf("\nEnter the option from the list(1 to 8) to perform that specific operation , and Enter 0 to exit : \n");
		printf("1. Push()\n");
		printf("2. Pop()\n");
		printf("3. isEmpty()\n");
		printf("4. Peek()\n");
		printf("5. change()\n");
		printf("6. count()\n");
		printf("7. display()\n");
		printf("8. destroy()\n");
}

struct stack *getNode()
{
	struct stack *ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack));
	
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
	if(top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct stack *key_check(int key)
{
	struct stack *temp = top;
	
	while(temp != NULL)
	{
		if(temp->key == key)
		{
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

void push()
{
	printf("\nPUSH \n\n");
	
	struct stack *newNode = getNode(), *temp = NULL;
	
	if(isEmpty())
	{
		top = newNode;
	}
	else if(key_check(newNode->key) != NULL)
	{
		printf("Node already exists with the key value \n");
		return;
	}
	else
	{
		temp = top;
		top = newNode;
		top->next = temp;
	}
	
	printf("Push operation sucessfull! \n");
}

void pop()
{
	printf("\nPOP \n\n");
	
	struct stack *temp = NULL;
	
	if(isEmpty())
	{
		printf("Stack Underflow \n");
	}
	else
	{
		temp = top;
		top = top->next;
		
		printf("Pop operation with node of key %d is successfull! \n", temp->key);
	}
}

void peek()
{
	printf("\nPEEK \n\n");
	
	if(isEmpty())
	{
		printf("Stack Underflow \n");
	}
	else
	{
		printf("Top : (%d , %d) \n", top->key, top->data);
	}
}

void change()
{
	printf("\nCHANGE \n\n");
	
	if(isEmpty())
	{
		printf("Stack Underflow \n");
		return;
	}
	
	int key, data;
	
	struct stack *temp = top;
	
	printf("Enter the existing key and data to be changed : \n");
	scanf("%d %d", &key, &data);
	
	if(key_check(key) == NULL)
	{
		printf("Node doesn't exist with the given key \n");
		
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->key == key)
			{
				temp->data = data;
				printf("Now the node with key %d is updated with data %d", temp->key, temp->data);
				return;
			}
			temp = temp->next;
		}
	}
}

void count()
{
	printf("\nCOUNT \n\n");
	
	int count = 0;
	
	struct stack *temp = top;
	
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	
	printf("%d \n",count);
}

void display()
{
	struct stack *temp = top;
	
	printf("\nDISPLAY STACK \n\n");
	
	if(isEmpty())
	{
		printf("Stack Underflow \n");
		return;
	}
	
	while(temp != NULL)
	{
		printf("(%d , %d)-->", temp->key, temp->data);
		temp = temp->next;
	}
	printf("NULL \n");
}

void destroy()
{
	struct stack *temp = top, *current;
	
	while(temp != NULL)
	{
		current = temp;
		temp = temp->next;
		free(current);
		current = NULL;
	}
	top = NULL;
	
	printf("\nSTACK DESTROYED SUCCESSFULLY!!! \n");
}
