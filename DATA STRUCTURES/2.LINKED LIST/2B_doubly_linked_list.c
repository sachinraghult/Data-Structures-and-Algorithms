#include <stdio.h>
#include <stdlib.h>

void menu_card();
struct node *key_check(int key);
struct node *getNode();

void append_node();
void prepend_node();
void insert_node_after();
void delete_node();
void update_node();
void display_linked_list();
void display_linked_list_reverse();
void destroy_linked_list();

struct node{
	int key, data;
	struct node *previous, *next;
};

struct node *head = NULL;
static int count = 0;

int main()
{
	int choice, option, key;
	
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
				insert_node_after();
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
				display_linked_list_reverse();
				break;
				
			case 8:
				destroy_linked_list();
				break;
		
			case 9:
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

		printf("\nEnter the option from the list(1 to 9) to perform that specific operation , and Enter 0 to exit : \n");
		printf("1. append_node()\n");
		printf("2. prepend_node()\n");
		printf("3. insert_node_after()\n");
		printf("4. delete_node()\n");
		printf("5. update_node()\n");
		printf("6. display_linked_list()\n");
		printf("7. display_linked_list_reverse()\n");
		printf("8. destroy_Linked_List()\n");
		printf("9. key_check()\n");
}

struct node *getNode()
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	
	if(ptr == NULL)
	{
		printf("Memory Unavailable\n");
	}
	
	printf("Enter the unique key and data for the new Node : \n");
	scanf("%d %d", &ptr->key, &ptr->data);
	
	ptr->previous = NULL;
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
		newNode->previous = temp;
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
	head->previous = newNode;
	head = newNode;
	printf("Node prepended successfully \n");
	count++;
}

void insert_node_after()
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
			newNode->previous = temp;
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
		if(head != NULL)
			head->previous = NULL;
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
					temp->next->previous = current;
					current->next = temp->next;
					printf("Node deleted successfully with key value %d \n",key);
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
	printf("HEAD--->");
	
	while(temp != NULL)
	{
		printf("(%d , %d)--->", temp->key, temp->data);
		temp = temp->next;
	}
	
	printf("TAIL\n");

}

void display_linked_list_reverse()
{
	struct node *temp = head, *tail = NULL;
	
	if(head == NULL)
	{
		printf("Linked list empty \n");
		return;
	}
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	tail = temp;
	
	printf("Reversed Linked List : \n");
	printf("TAIL--->");
	
	while(tail != NULL)
	{
		printf("(%d , %d)--->", tail->key, tail->data);
		tail = tail->previous;
	}
	
	printf("HEAD \n");
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
	
	printf("SINGLY LINKED LIST HAS BEEN DELETED SUCCESSFULLY!!! \n");
}
