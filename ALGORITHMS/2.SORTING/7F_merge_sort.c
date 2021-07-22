#include <stdio.h>
#include <stdlib.h>

int *b;

void merge(int *a, int lb, int mid, int ub)
{
	int start, k, l;

	start = lb;                          //For atlast copying new array to old array
	k = mid+1;                           //ub already declared is used as upper bound of PART2 and k is used as lower bound of PART2
	l = lb;                              //l variable is used for tracking the new created array for sorting(ie. b array)

	while(lb <= mid && k <= ub)
	{
		if(*(a + lb) < *(a + k))
		{
			*(b + l) = *(a + lb);
			lb++;
		}
		else
		{
			*(b + l) = *(a + k);
			k++;
		}
		l++;
	}

	while(k <= ub)
	{
		*(b + l) = *(a + k);
		k++;l++;
	}
	while(lb <= mid)
	{
		*(b + l) = *(a + lb);
		lb++;l++;
	}


	for(l = start;l <= ub;l++)
	{
		*(a + l) = *(b + l);
	}
}

void merge_sort(int *a, int lb, int ub)
{
	if(lb < ub)
	{
		int mid = (lb + ub)/2;
		merge_sort(a, lb, mid);
		merge_sort(a, mid+1, ub);
		merge(a, lb, mid, ub);
	}
}

int main()
{
	printf("MERGE SORT\n\n");

	int i, size;

	printf("Enter the size of the array to be created : ");
	scanf("%d",&size);

	int *arr;
	arr = (int *)calloc(size, sizeof(arr));

//	printf("\nInput the data to be sorted : \n\n");

	printf("\nINPUT DATA : ");

	for(i = 0;i < size;i++)
	{
		scanf("%d",arr+i);
	}

/*	printf("\nINPUT DATA : ");

	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
*/
	b = (int *)calloc(size, sizeof(b));

	//MERGE SORT FUNCTION CALLED

	merge_sort(arr, 0, size-1);

	printf("\nSORTED DATA : ");

	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}

	free(arr);
	arr= NULL;

	return 0;
}
