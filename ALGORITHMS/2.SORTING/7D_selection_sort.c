#include <stdio.h>
#include <stdlib.h>

int minloc(int *arr, int lb, int n)
{
	int loc = lb;
	int i;
	
	for(i = lb+1;i < n;i++)
	{
		if(*(arr+i) < *(arr+loc))
		{
			loc = i;
		}
	}
	
	return loc;
}

void selection_sort(int *arr, int size)
{
	int i, loc, temp;
	
	for(i = 0;i < size-1;i++)           //Sorting first n-1 numbers makes nth number sorted automatically
	{
		loc = minloc(arr, i, size);     //Finding location of the smallest to best suit the particular ith position
		
		if(loc != i)
		{
			temp = *(arr+loc);          //Swap the smallest found data with current data in the ith position
			*(arr+loc) = *(arr+i);
			*(arr+i) = temp;
		}
	}
}                                       //This method of sorting is called selection sort as it makes selective sorting

int main()
{
	printf("SELECTION SORT\n\n");
	
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
	
	//SELECTION SORT FUNCTION CALLED
	
	selection_sort(arr, size);
	
	printf("\n\nSORTED DATA : ");
	
	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
	
	free(arr);
	arr= NULL;
	
	return 0;
}
