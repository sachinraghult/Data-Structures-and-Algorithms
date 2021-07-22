#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *a, int n)
{
	int gap, j;
	
	for(gap = n/2;gap > 0;gap /= 2)
	{
		for(j = gap;j < n;j++)
		{
			int temp = *(a + j);
			int i = 0;
			
			for(i = j;i >= gap && *(a + i - gap) > temp;i -= gap)
			{
				*(a + i) = *(a + i - gap);
			}
			*(a + i) = temp;
		}
	}
}

int main()
{
	printf("SHELL SORT\n\n");
	
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
	
	//SHELL SORT FUNCTION CALLED
	
	shell_sort(arr, size);
	
	printf("\n\nSORTED DATA : ");
	
	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
	
	free(arr);
	arr= NULL;
	
	return 0;
}
