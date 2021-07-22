#include <stdio.h>
#include <stdlib.h>

static int count = 0;
int *arr;

void print_menu();
void create_array();
void insert_array();
void delete_array();
void display_array();
void count_array();
void destroy_array();

int main()
{
	printf("DYNAMIC ARRAYS.........\n\n");
	create_array();
	
	int choice;
	
	do
	{
		print_menu();
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0:
				break;
				
			case 1:
				insert_array();
				break;
			
			case 2:
				delete_array();
				break;
				
			case 3:
				display_array();
				break;
				
			case 4:
				count_array();
				break;
				
			case 5:
				destroy_array();
				break;
				
			default:
				printf("Invalid choice \n");
		}
		
	}while(choice != 0);
	
	destroy_array();
	
	printf("\nSESSION ENDED\n");
	
	return 0;
}

void print_menu()
{
	printf("\nEnter the respective numbers from the menu card to perform those specific operations..(Enter 0 to exit) : \n");
	printf("1. insert_array()\n");
	printf("2. delete_array()\n");
	printf("3. display_array()\n");
	printf("4. count_array()\n");
	printf("5. destroy_array()\n");
}

void create_array()
{
	printf("\nCREATE ARRAY : \n\n");
	
	int i, size;
	
	printf("Enter the size of the array to be created : ");
	scanf("%d",&size);
	
	arr = (int*)calloc(size,sizeof(arr));
	
	if(arr == NULL)
	{
		printf("Memory Unavailable\n");
		exit(1);
	}
	
	count = size;
	
	printf("Array Input : \n\n");
	
	for(i = 0;i < count;i++)
	{
		printf("Data %d : ",i+1);
		scanf("%d",arr+i);
	}
	
	display_array();
}

void insert_array()
{
	printf("\nINSERT ARRAY : \n\n");
	
	int choice, number, position, data, i, loop = 1;
	
	printf("   1.Insert all the data to be inserted consecutively from the index mentioned \n");
	printf("   2.Insert in the unique indices for each data that you enter \n");
	
	printf("\nEnter the respective choice from the above menu card to insert in the specified way : ");
	scanf("%d",&choice);
	
	printf("Enter the number of data to be inserted : ");
	scanf("%d",&number);
			
	switch(choice)
	{
		case 1:
			printf("Enter the position from which the data to be inserted consecutively : ");
			scanf("%d",&position);
			
			if(position > count+1)
			{
				printf("Invalid index \n");
				return;
			}
			
			while(loop <= number)
			{
				arr = (int*)realloc(arr, (count+1)*sizeof(arr));
				
				if(arr == NULL)
				{
					printf("Memory Unavailable\n");
					return;
				}
				
				printf("Enter the data %d to be inserted : ",loop);
				scanf("%d",&data);
				
				if(position == count+1)
				{
					*(arr + position - 1) = data;
				}
				else
				{
					for(i = count;i >= position;i--)
					{
						*(arr + i) = *(arr + i - 1);
					}
					*(arr + position - 1) = data;
				}
				count++;
				display_array();
				
				loop++;
				position++;
			}
			break;
			
		case 2:
			while(loop <= number)
			{
				printf("Enter the position and data at which the data %d to be inserted : ",loop);
				scanf("%d %d", &position, &data);
				
				if(position > count+1)
				{
					printf("Invalid index \n");
				}
				else
				{
					arr = (int*)realloc(arr, (count+1)*sizeof(arr));
				
					if(arr == NULL)
					{
						printf("Memory Unavailable\n");
						return;
					}
				
					if(position == count+1)
					{
						*(arr + position - 1) = data;
					}
					else
					{
						for(i = count;i >= position;i--)
						{
							*(arr + i) = *(arr + i - 1);
						}
						*(arr + position - 1) = data;
					}
					count++;			
					display_array();
					loop++;
				}
			}
			break;
			
		default:
			printf("Invalid choice \n");
	}
}

void delete_array()
{
	printf("\nDELETE ARRAY : \n\n");
	
	int choice, number, position, i, loop = 1;
	
	printf("   1.Delete all the data to be deleted consecutively from the index mentioned \n");
	printf("   2.Delete the unique indices that are to be deleted \n");
	
	printf("\nEnter the respective choice from the above menu card to delete in the specified way : ");
	scanf("%d",&choice);
	
	printf("Enter the number of data to be deleted : ");
	scanf("%d",&number);
			
	switch(choice)
	{
		case 1:
			printf("Enter the position from which the data to be deleted consecutively : ");
			scanf("%d",&position);
			
			while(loop <= number)
			{
				if(position == count);
				else if(position > count)
				{
					if(loop == 1){
						printf("Invalid index \n");
						return;
					}
					display_array();
					return;
				}
				else
				{
					for(i = position - 1;i < count - 1;i++)
					{
						*(arr + i) = *(arr + i + 1);
					}
				}
				
				arr = (int*)realloc(arr, (--count)*sizeof(arr));
				
				if(arr == NULL && count != 0)
				{
					printf("Error in memory allocation\n");
					return;
				}
				
				loop++;
			}
			
			display_array();
			
			break;
			
		case 2:
			while(loop <= number)
			{
				printf("Enter the position at which the data %d to be deleted : ",loop);
				scanf("%d",&position);
				
				if(position == count)
				{
					arr = (int*)realloc(arr, (--count)*sizeof(arr));
				
					if(arr == NULL && count != 0)
					{
						printf("Error in memory allocation\n");
						return;
					}
				}
				else if(position > count)
				{
					printf("Invalid index \n");
					loop--;
				}
				else
				{
					for(i = position-1;i < count - 1;i++)
					{
						*(arr + i) = *(arr + i + 1);
					}
				
					arr = (int*)realloc(arr, (--count)*sizeof(arr));
				
					if(arr == NULL && count != 0)
					{
						printf("Error in memory allocation\n");
						return;
					}
				}
				display_array();
				loop++;
			}
			break;
			
		default:
			printf("Invalid choice \n");
	}
}

void display_array()
{
	printf("\nDISPLAY ARRAY : \n\n");
	
	int i;
	
	for(i = 0;i < count;i++)
	{
		printf("arr[%d] = %d \n", i+1, *(arr + i));
	}
}

void count_array()
{
	printf("\nARRAY COUNT = %d \n\n",count);
}

void destroy_array()
{
	free(arr);
	arr = NULL;
	
	printf("\nARRAY DESTROYED SUCCESSFULLY!!! \n\n");
}
