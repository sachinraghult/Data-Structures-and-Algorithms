#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int size)
{
	int i, j, temp;
	
	for(i = 1;i <= size-1;i++)        //Sorting n-1 data , makes the nth data automatically sorted
	{
		for(j = 1;j <= size-i;j++)    //Comparing each and every dta with the other till size-i as the rest of data are larger and are in right order
		{
			if(*(arr+j-1) > *(arr+j)) //Note the index starts from 1 so that we subtract -1 in the conditions else you can start from 0 and dont need to subtract
			{
				temp = *(arr+j-1);    //By swapping the larger one to the right on every comparison(outer for loop) on each data with the other one(inner for loop)
				*(arr+j-1) = *(arr+j);//The larger data moves on the right similar to the bubble rising in water
				*(arr+j) = temp;
			}
		}
	}
}

int main()
{
	printf("BUBBLE SORT\n\n");
	
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
	
	//BUBBLE SORT FUNCTION CALLED
	
	bubble_sort(arr, size);
	
	printf("\n\nSORTED DATA : ");
	
	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
	
	free(arr);
	arr= NULL;
	
	return 0;
}
