
//MERGE AND SORT FUNCTIONS ARE YET TO WRITE CORRECT CODE

#include <stdio.h>
#include <stdlib.h>

void menu_card();
struct node *search_node(int,int);
struct node *getNode();

void create_linked_list();
void append_node();
void prepend_node();
void insert_internal_node();
void delete_node();
void update_node();
void display_linked_list(int);
void display_program();
void destroy_linked_list();
void destroy_program();

void sort_linked_list();
void merge_linked_list();

struct node{
	int key;
	int data;
	struct node *next;
};

static int num = 0;
static int count[10] = {0};

struct node *head[10] = {NULL};

int main()
{
	printf("SINGLY LINKED LIST .........\n\n");
	
	create_linked_list();
	
	int choice, n, key;
	
	do
	{
		menu_card();
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0:
				break;
			case 1:
				create_linked_list();
				break;
			case 2:
				printf("\nAPPEND : \n\n");
				append_node();
				break;
			case 3:
				printf("\nPREPEND : \n\n");
				prepend_node();
				break;
			case 4:
				printf("\nINSERT : \n\n");
				insert_internal_node();
				break;
			case 5:
				printf("\nDELETE : \n\n");
				delete_node();
				break;
			case 6:
				printf("\nUPDATE : \n\n");
				update_node();
				break;
			case 7:
				printf("\nSEARCH : \n\n");
				printf("Enter the Linked List Number and the key of the node to be searched : \n");
				scanf("%d %d", &n, &key);
				
				if(search_node(--n,key) != NULL)
				{
					printf("Searching Successfull\n");
				}
				else
				{
					printf("Searching unsuccessfull\n");
				}
				break;
			case 8:
				printf("\nDISPLAY : \n\n");
				printf("Enter the Linked List Number : ");
				scanf("%d",&n);
				display_linked_list(n);
				break;
			case 9:
				printf("\nDISPLAY PROGRAM : \n\n");
				display_program();
				break;
			case 10:
				printf("\nDESTROY : \n\n");
				destroy_linked_list();
				break;
			case 11:
				destroy_program();
				break;
			case 12:
				printf("\nSORT : \n\n");
				sort_linked_list();
				break;
			case 13:
				printf("\nMERGE : \n\n");
				merge_linked_list();
				break;

			default:
				printf("Invalid choice\n");

		}
	}while(choice != 0);
	
	destroy_program();
	
	printf("\nSESSION ENDED\n");
	
	return 0;
}

void menu_card()
{
	printf("\nEnter the choice from the below menu to perform the specific operation on the linked list present (0 to exit) :\n\n");
	printf("1. create_linked_list()\n");
	printf("2. append_node()\n");
	printf("3. prepend_node()\n");
	printf("4. insert_internal_node()\n");
	printf("5. delete_node()\n");
	printf("6. update_node()\n");
	printf("7. search_node()\n");
	printf("8. display_linked_list()\n");
	printf("9. display_program()\n");
	printf("10. destroy_linked_list()\n");
	printf("11. destroy_program()\n");
	printf("12. sort_linked_list()\n");
	printf("13. merge_linked_list()\n\nCHOICE : ");

}

void create_linked_list()
{
	printf("Linked list %d Creation: \n",num+1);
	
	printf("Enter details of the first node of linked list created : \n");
	struct node *newNode = getNode();
	
	head[num] = newNode;
	
	count[num]++;
	num++;
}

struct node *getNode()
{
	struct node *ptr;
	ptr = (struct node*)calloc(1,sizeof(struct node));
	
	if(ptr == NULL)
	{
		printf("Memory unavailable\n");
		exit(1);
	}
	
	printf("\nEnter the unique key and data of the new node : \n");
	scanf("%d %d", &ptr->key, &ptr->data);
	
	ptr->next = NULL;
	
	return ptr;
}

struct node *search_node(int n, int key)
{
	struct node *temp = head[n];
	
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
	int n;
	printf("Enter the Linked List Number : ");
	scanf("%d",&n);
	
	if(n-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	
	struct node *newNode = getNode(), *temp = head[n];
	
	if(search_node(n,newNode->key) != NULL)
	{
		printf("Node exists already\n");
		return;
	}
	
	if(head[n] == NULL)
	{
		head[n] = newNode;
		printf("Appended successfully");
		count[n]++;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		printf("Appended successfully");
		count[n]++;
	}
}

void prepend_node()
{
	int n;
	printf("Enter the Linked List Number : ");
	scanf("%d",&n);
	
	if(n-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	
	struct node *newNode = getNode();

	if(search_node(n,newNode->key) != NULL)
	{
		printf("Node exists already\n");
		return;
	}

	if(head[n] == NULL)
	{
		head[n] = newNode;
		printf("Prepended successfully");
		count[n]++;
	}
	else
	{
		newNode->next = head[n];
		head[n] = newNode;
		printf("Prepended successfully");
		count[n]++;
	}
}

void insert_internal_node()
{
	int n;
	printf("Enter the Linked List Number : ");
	scanf("%d",&n);
	
	if(n-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	
	struct node *newNode = getNode();
	
	if(search_node(n,newNode->key) != NULL)
	{
		printf("Node exists already\n");
		return;
	}
	
	int key;
	printf("Enter the node key after which the new node to be inserted : ");
	scanf("%d",&key);
	
	if(search_node(n,key) == NULL)
	{
		printf("Node doesn't exists with the given key value, retry\n");
		return;
	}
	
	struct node *temp = head[n];
	
	while(temp != NULL)
	{
		if(temp->key == key)
		{
			newNode->next = temp->next;
			temp->next = newNode;
			printf("Inserted successfully\n");
			count[n]++;
			return;
		}
		temp = temp->next;
	}
}

void delete_node()
{
	int n;
	printf("Enter the Linked List Number to be deleted: ");
	scanf("%d",&n);
	
	if(n-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	
	int key;
	printf("Enter the node key of the node to be deleted : ");
	scanf("%d",&key);
	
	if(search_node(n,key) == NULL)
	{
		printf("Node doesn't exists with the given key value, retry\n");
		return;
	}
	
	struct node *temp = head[n], *current = NULL;
	
	if(head[n]->key == key)
	{
		head[n] = head[n]->next;
		printf("Head node deleted successfully\n");
		count[n]--;
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->key == key)
			{
				if(temp->next == NULL)
				{
					current->next = NULL;
					printf("Tail node deleted successfully\n");
					count[n]--;
					return;
				}
				else
				{
					current->next = temp->next;
					printf("Internal node deleted successfully\n");
					count[n]--;
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
	int n;
	printf("Enter the Linked List Number : ");
	scanf("%d",&n); 
	
	if(n-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
 
	int key;
	printf("Enter the node key of the node to be updated : ");
	scanf("%d",&key);
	
	if(search_node(n,key) == NULL)
	{
		printf("Node doesn't exists with the given key value, retry\n");
		return;
	}
	
	int data;
	printf("Enter the data of the node to be updated : ");
	scanf("%d",&data);
	
	struct node *temp = head[n];
	
	while(temp != NULL)
	{
		if(temp->key == key)
		{
			temp->data = data;
			printf("Updated successfully\n");
			return;
		}
		temp = temp->next;
	}
}

void display_linked_list(int n)
{
	printf("Linked List %d : ",n);
	
	if(n-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	
	struct node *temp = head[n];
	
	printf("\nHEAD-->");
	while(temp != NULL)
	{
		printf("(%d , %d)-->", temp->key, temp->data);
		temp = temp->next;
	}
	printf("TAIL\n");
}

void display_program()
{
	struct node *temp = NULL;
	int i;
	
	for(i = 0;i < num;i++)
	{
		temp = head[i];
		
		printf("\nHEAD-->");
		while(temp != NULL)
		{
			printf("(%d , %d)-->", temp->key, temp->data);
			temp = temp->next;
		}
		printf("TAIL\n");
	}
}

void destroy_linked_list()
{
	int n;
	printf("Enter the Linked List Number to be destroyed : ");
	scanf("%d",&n);
	
	if(n-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	
	struct node *temp = head[n], *current = NULL;
	
	while(temp != NULL)
	{
		current = temp;
		temp = temp->next;
		free(current);
		current = NULL;
	}
	
	count[n] = 0;
	
	int i;
	
	for(i = n; i < n-1; i++)
	{
		head[i] = head[i+1];
		count[i] = count[i+1];
	}
	num--;
	
	printf("Linked List destroyed successfully");
}

void destroy_program()
{
	struct node *temp = NULL, *current = NULL;
	int i;
	
	for(i = 0;i < num;i++)
	{
		temp = head[i];
		
		while(temp != NULL)
		{
			current = temp;
			temp = temp->next;
			free(current);
			current = NULL;
		}
	}
	
	num = 0;
	
	for(i = 0;i < 10;i++)
	{
		count[i] = 0;
		head[i] = NULL;
	}
	
	printf("\nHeap memory space deallocated successfully.....\nEND OF THE PROGRAM!!!\n");
}

void sort_linked_list()
{
	int n;
	printf("Enter the Linked List Number : ");
	scanf("%d",&n);
	
	if(n > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	n--;
	
	int sort[count[n]];
	int i;
	int min = head[n]->data;
	int max = head[n]->data;
	struct node *temp;

	//To find the min and max

	temp = head[n];
	
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
	
	printf("Minimum : %d   Maximum : %d \n", min, max);
	
	//To sort the Linked List in increasing order and storing in an array
	
	int prev = min-1;
	
	for(i = 0 ;i < count[n]; i++)
	{
		temp = head[n];
		sort[i] = max;
		
		while(temp != NULL)
		{
			if(temp->data > prev)
			{
				if(temp->data < sort[i])
				{
					sort[i] = temp->data;
				}
			}
			temp = temp->next;
		}
		prev = sort[i];
	}
		
	//Assigning sorted array to Linked List
		
	temp = head[n];
	i = 0;
	
	while(temp != NULL)
	{
		temp->data = sort[i];
		temp = temp->next;
		i++;
	}
	
	//Printing Sorted Linked List
	
	printf("Sorted Linked List : \n");
	
	display_linked_list(n+1);
}

struct node *merge_memory()
{
	struct node *ptr;
	ptr = (struct node*)calloc(1,sizeof(struct node));
	ptr->next = NULL;
	
	return ptr;
}

void merge_linked_list()
{
	int n1, n2;
	printf("Enter the two Linked List Numbers that are to be merged : \n");
	scanf("%d %d", &n1, &n2);

	if(n1-- > num || n2-- > num)
	{
		printf("Linked List does not exist with the given Number, retry\n");
		return;
	}
	
	int key = 1;
	 	
	struct node *temp1 = head[n1], *temp2 = head[n2], *temp3 = NULL;
	head[num] = NULL;
	
	while(temp1 != NULL)
	{	
		struct node *newNode;
		newNode = merge_memory();
		
		if(head[num] == NULL)
		{
			head[num] = newNode;
			temp3 = head[num];
		}
		else
			temp3 = newNode;
			
		temp3->key = key;
		temp3->data = temp1->data;
		
		temp1 = temp1->next;
		temp3 = temp3->next;
		key++;
	}
	while(temp2 != NULL)
	{
		struct node *newNode;
		newNode = merge_memory();
		
		temp3 = newNode;
			
		temp3->key = key;
		temp3->data = temp2->data;
		
		temp2 = temp2->next;
		temp3 = temp3->next;
		key++;
	}

	display_linked_list(++num);
}
