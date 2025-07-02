#include <stdio.h>
#include <math.h>

void put_arr(int arr[], int size_arr);
void print_arr(int arr[], int size_arr);

int main(void)
{
	int arr[10];
	put_arr(arr, 10);
	print_arr(arr, 10);

	return 0;
}

void put_arr(int arr[], int size_arr)
{
	int i;
	for (i = 0; i < size_arr; i++)
	{
		arr[i] = pow(2, i);
	}
}

void print_arr(int arr[], int size_arr)
{
	int i;
	for (i = 0; i < size_arr; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}



