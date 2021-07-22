#include <stdio.h>
#include <stdlib.h>

void menu_card();
struct node *key_check(int key);
struct node *getNode();

void append_node();
void prepend_node();
void insert_after_node();
void delete_node();
void update_node();
void display_linked_list();
void destroy_linked_list();
void sorting();

//ADDITIONAL FUNCTIONS

void addition();
void subtraction();
void multiplication();
void division();

struct node{
	int key;
	int data;
	struct node *next;
};

struct node *head = NULL;
static int count = 0;

int main()
{
	int choice, option, key;
	
	void (*operation[4])() = {addition , subtraction , multiplication , division};
	
	do
	{
	
		menu_card();
	
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0:
				break;
				
			case 1:
				append_node();
				break;
				
			case 2:
				prepend_node();
				break;
				
			case 3:
				insert_after_node();
				break;
				
			case 4:
				delete_node();
				break;
				
			case 5:
				update_node();
				break;
				
			case 6:
				display_linked_list();
				break;
				
			case 7:
				destroy_linked_list();
				break;
				
			case 8:
				printf("Enter the key of the Node to be Checked : ");
				scanf("%d",&key);
				if(key_check(key) != NULL)
				{
					printf("Node exists\n");
				}
				else
				{
					printf("Node doesn't exist with key value %d\n",key);
				}
				break;
				
			case 9:
				sorting();
				break;
				
			case 10:
				
				printf("Enter the option from the below menu card to perform the specified operation : \n");
				printf("     0. Addition()\n");
				printf("     1. Subtraction()\n");
				printf("     2. Multiplication()\n");
				printf("     3. Division()\n");
				
				scanf("%d",&option);
				
				if(option >= 3 && option <= 0)
				{
					printf("Invalid choice \n");
					return;
				}
				
				operation[option]();
				
				break;
				
			default:
				printf("Invalid Choice\n");
		}
	}while(choice != 0);
	
	destroy_linked_list();
	
	printf("\nSESSION ENDED\n");
	
	return 0;
}

void menu_card()
{

		printf("\nEnter the option from the list(1 to 10) to perform that specific operation , and Enter 0 to exit : \n");
		printf("1. append_node()\n");
		printf("2. prepend_node()\n");
		printf("3. insert_after_node()\n");
		printf("4. delete_node()\n");
		printf("5. update_node()\n");
		printf("6. display_linked_list()\n");
		printf("7. destroy_linked_list()\n");
		printf("8. key_check()\n");
		printf("9. sorting()\n");
		printf("10. Operations\n");
}

struct node *getNode()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	
	if(ptr == NULL)
	{
		printf("Memory Unavailable\n");
		exit(1);
	}
	
	printf("Enter the unique key and data for the new Node : \n");
	scanf("%d %d", &ptr->key, &ptr->data);
	
	ptr->next = NULL;
	
	return ptr;
}

struct node *key_check(int key)
{
	struct node *temp = head;
	
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

void append_node()
{
	struct node *newNode = getNode();
	
	if(key_check(newNode->key) != NULL)
	{
		printf("Node already exist with the given key \n");
		return;
	}
		
	struct node *temp = head;
	
	if(head == NULL)
	{
		head = newNode;
		printf("Head node created successfully \n");
		count++;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		printf("Node appended successfully \n");
		count++; 
	}
}

void prepend_node()
{
	struct node *newNode = getNode();
	
	if(key_check(newNode->key) != NULL)
	{
		printf("Node alreaady exist with the given key \n");
		return;
	}
	
	newNode->next = head;
	head = newNode;
	printf("Node prepended successfully \n");
	count++;
}

void insert_after_node()
{
	struct node *newNode = getNode();
	
	if(key_check(newNode->key) != NULL)
	{
		printf("Node alreaady exist with the given key \n");
		return;
	}	
	
	int key;
	
	printf("Enter the Node key after which the node to be inserted : \n");
	scanf("%d",&key);
	
	if(key_check(key) == NULL)
	{
		printf("Node doesn't exist with the key value given. Re-enter the proper key \n");
		return;
	}
	
	struct node *temp = head;
	int flag = 0;
	
	while(temp != NULL)
	{
		flag++;
	
		if(temp->key == key)
		{
			newNode->next = temp->next;
			temp->next = newNode;
			printf("Node inserted successfully after the Node key %d with key %d and data %d at the position %d \n", key, newNode->key, newNode->data, flag +1);
			count++;
			return;
		}
		temp = temp->next;
	}
}

void delete_node()
{
	int key;
	
	printf("Enter the Node key to be deleted : \n");
	scanf("%d",&key);
	
	if(key_check(key) == NULL)
	{
		printf("Node doesn't exist with the key value given. Re-enter the proper key \n");
		return;
	}
	
	if(head->key == key)
	{
		head = head->next;
		printf("Head Node deleted successfully \n");
		count--;
		return;
	}
	else
	{
		struct node *temp = head, *current = NULL;
		
		while(temp != NULL)
		{
			if(temp->key == key)
			{
				if(temp->next == NULL)
				{
					current->next = NULL;
					printf("Tail Node deleted successfully \n");
					count--;
					return;
				}
				else
				{
					current->next = temp->next;
					printf("Node is deleted successfully with key value %d \n",key);
					count--;
					return;
				}
			}
			current = temp;
			temp = temp->next;
		}
	}
}

void update_node()
{
	int key, data;
	
	printf("Enter the Node key to be updated : \n");
	scanf("%d",&key);
	
	if(key_check(key) == NULL)
	{
		printf("Node doesn't exist with the key value given. Re-enter the proper key \n");
		return;
	}
	
	printf("Enter the data to to be updated : \n");
	scanf("%d",&data);
	
	struct node *temp = head;
	
	while(temp != NULL)
	{
		if(temp->key == key)
		{
			temp->data = data;
			printf("Node with key %d updated successfully with the data %d \n",key,temp->data);
			return;
		}
		temp = temp->next;
	}	
}

void display_linked_list()
{
	struct node *temp = head;
	
	printf("Singly Linked List : \n");
		
	printf("HEAD");
	
	while(temp != NULL)
	{
		printf("-->(%d , %d)", temp->key, temp->data);
		temp = temp->next;
	}
	
	printf("-->TAIL\n");
}

void destroy_linked_list()
{
	struct node *temp = head, *current;
	
	while(temp != NULL)
	{
		current = temp;
		temp = temp->next;
		free(current);
		current = NULL;
	}
	count = 0;
	head = NULL;
	
	printf("SINGLY LINKED LIST DELETED SUCCESSFULLY!!! \n");
}

void sorting()
{
	int sort[count];
	int i;
	int min = head->data;
	int max = head->data;
	struct node *temp;

	//To find the min and max

	temp = head;
	
	while(temp != NULL)
	{
		if(temp->data > max)
		{
			max = temp->data;
		}
		if(temp->data < min)
		{
			min = temp->data;
		}
		temp = temp->next;
	}
	
	printf("Minimum : %d   Maximum : %d \n",min,max);
	
	//To sort the Linked List in increasing order and storing in an array
	
	int num = min-1;
	
	for(i = 0 ;i < count; i++)
	{
		temp = head;
		sort[i] = max;
		
		while(temp != NULL)
		{
			if(temp->data > num)
			{
				if(temp->data < sort[i])
				{
					sort[i] = temp->data;
				}
			}
			temp = temp->next;
		}
		num = sort[i];
	}
		
	//Assigning sorted array to Linked List
		
	temp = head;
	i = 0;
	
	while(temp != NULL)
	{
		temp->data = sort[i];
		
		temp = temp->next;
		i++;
	}
	
	//Printing Sorted Linked List
	
	printf("Sorted Linked List : \n");
	
	display_linked_list();
}

//ADDITIONAL FUNCTIONS

void addition()
{
	struct node *temp = head;
	int sum = 0;
	
	printf("Addition : \n");
	
	while(temp != NULL)
	{
		printf("%d + ",temp->data);
		sum += temp->data;
		temp = temp->next;
	}
	
	printf("0 = %d \n",sum);
}

void subtraction()
{
	struct node *temp = head;
	int difference = 0;
	
	printf("Subtraction : \n");
	
	while(temp != NULL)
	{
		printf("%d - ",temp->data);
		difference -= temp->data;
		temp = temp->next;
	}
	
	printf("0 = %d \n",difference);
}

void multiplication()
{
	struct node *temp = head;
	int product = 1;
	
	printf("Multiplication : \n");
	
	while(temp != NULL)
	{
		printf("%d * ",temp->data);
		product *= temp->data;
		temp = temp->next;
	}
	
	printf("1 = %d \n",product);
}

void division()
{
	struct node *temp = head;
	int quotient = 1;
	
	printf("Division : \n");
	
	while(temp != NULL)
	{
		printf("%d / ",temp->data);
		quotient /= temp->data;
		temp = temp->next;
	}
	
	printf("1 = %d \n",quotient);
}
