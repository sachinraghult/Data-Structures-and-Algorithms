#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int size)
{
	int i, loc, temp;
	
	for(i = 1;i <= size-1;i++)
	{
		if(*(arr+i-1) > *(arr+i+1-1))   //Note the index starts from 1 so that we subtract -1 in the conditions else u can start from 0 and dont need to subtract
		{
			temp = *(arr+i+1-1);
			loc = i+1-1;
			
			while(loc != 0 && *(arr+loc-1) > temp)
			{
				*(arr+loc) = *(arr+loc-1);     //This code pushes the largest one downwards till it finds its correct position(Shifts without swap ie. insertion)
				loc--;
			}
			*(arr+loc) = temp;                 //Atlast that particular number is inserted in the right position
		}
	}
}                                              //This style of sorting is called insertion sorting (Similar technique used in cards playing)

int main()
{
	printf("INSERTION SORT\n\n");
	
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
	
	//INSERTION SORT FUNCTION CALLED
	
	insertion_sort(arr, size);
	
	printf("\n\nSORTED DATA : ");
	
	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
	
	free(arr);
	arr= NULL;
	
	return 0;
}
