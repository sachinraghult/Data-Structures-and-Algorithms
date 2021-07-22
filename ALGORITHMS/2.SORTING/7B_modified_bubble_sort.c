#include <stdio.h>                         //Modified bubble sort is to avois execution of the already sorted array
#include <stdlib.h>

void modify_bubble_sort(int *arr, int size)
{
	int i, j, temp, flag = 1;              //This intoduction of flag variable is used to make trace whether the inputed data are already in sorted order or not      
	
	for(i = 1;i <= size-1 && flag == 1;i++)
	{
		flag = -1;                         //This flag variable reduces time complexity in case the data are already sorted by the above conditon
		
		for(j = 1;j <= size-i;j++)
		{
			if(*(arr+j-1) > *(arr+j))    //Note the index starts from 1 so that we subtract -1 in the conditions else u can start from 0 and dont need to subtract
			{
				temp = *(arr+j-1);
				*(arr+j-1) = *(arr+j);
				*(arr+j) = temp;
				flag = 1;
			}
		}
	}
}

int main()
{
	printf("MODIFIED BUBBLE SORT\n\n");
	
	int i, size;
	
	printf("Enter the size of the array to be created : ");
	scanf("%d",&size);
	
	int *arr;
	arr = (int *)calloc(size, sizeof(arr));
	
	printf("\nInput the data to be sorted : \n\n");
	
	for(i = 0;i < size;i++)
	{
		scanf("%d",arr+i);
	}
	
	printf("\nINPUT DATA : ");
	
	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
	
	//MODIFIED BUBBLE SORT FUNCTION CALLED
	
	modify_bubble_sort(arr, size);
	
	printf("\n\nSORTED DATA : ");
	
	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
	
	free(arr);
	arr= NULL;
	
	return 0;
}
