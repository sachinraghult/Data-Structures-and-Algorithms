#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int lb, int ub)
{
	int pivot, start, end, temp;
	pivot = *(arr + lb);start = lb;end = ub;

	while(start < end)
	{
		while(*(arr + start) <= pivot && start < end)
			start++;

		while(*(arr + end) > pivot)
			end--;

		if(start < end)
		{
			temp = *(arr + start);
			*(arr + start) = *(arr + end);
			*(arr + end) = temp;
		}
	}

	*(arr + lb) = *(arr + end);
	*(arr + end) = pivot;

	return end;
}

void quick_sort(int *arr, int lb, int ub)
{
	if(lb < ub)
	{
		int loc = partition(arr, lb, ub);
		quick_sort(arr, lb, loc-1);
		quick_sort(arr, loc+1, ub);
	}
}

int main()
{
	printf("QUICK SORT\n\n");

	int i, size;

	printf("Enter the size of the array to be created : ");
	scanf("%d",&size);

	int *arr;
	arr = (int *)calloc(size, sizeof(arr));

	printf("\nINPUT DATA : ");

	for(i = 0;i < size;i++)
	{
		scanf("%d",arr+i);
	}

	printf("\nInput data to be entered : \n");

	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}

	//QUICK SORT FUNCTION CALLED

	quick_sort(arr, 0, size-1);

	printf("\n\nSORTED DATA : ");

	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}

	free(arr);
	arr= NULL;

	return 0;
}
