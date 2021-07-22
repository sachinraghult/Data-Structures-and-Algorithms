#include <stdio.h>
#include <stdlib.h>

int *output;

int getmax(int *a, int n)
{
	int i, max = *a;
	
	for(i = 0;i < n;i++)
		if(*(a+i) > max)
			max = *(a+i);
			
	return max;
}

void count_sort(int *a, int n, int exp)
{
	int i, count[10] = {0};
	
	for(i = 0;i < n;i++)
		count[(*(a+i)/exp)%10]++;
		
	for(i = 1;i < 10;i++)
		count[i] += count[i-1];
		
	for(i = n-1;i >= 0;i--)
	{
		*(output + count[(*(a+i)/exp)%10] - 1) = *(a + i);
		count[(*(a+i)/exp)%10]--;
	}
	
	for(i = 0;i < n;i++)
		*(a + i) = *(output + i);
}

void radix_sort(int *a, int n)
{
	int exp, maxdata = getmax(a, n);
	
	for(exp = 1;maxdata/exp > 0;exp *= 10)
	{
		count_sort(a, n, exp);
	}
}

int main()
{
	printf("RADIX SORT\n\n");
	
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
	
	output = (int *)calloc(size, sizeof(output));
	
	//RADIX SORT FUNCTION CALLED
	
	radix_sort(arr, size);
	
	printf("\n\nSORTED DATA : ");
	
	for(i = 0;i < size;i++)
	{
		printf("%d ",*(arr+i));
	}
	
	free(arr);
	arr= NULL;
	
	return 0;
}
