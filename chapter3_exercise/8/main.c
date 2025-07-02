#include <stdio.h>

void insert(int array[], int loc, int value);
void delete(int array[], int loc);
void print_arr(int array[]);

int ITEMS = 4;

int main(void)
{
	int arr[100] = { 1,2,3,5 };
	insert(arr, 3, 4);
	print_arr(arr);
	delete(arr, 4);
	print_arr(arr);
	printf("%d", ITEMS);
	return 0;
}

//시간복잡도 O(n)
void insert(int array[], int loc, int value)
{
	int i;
	for (i = ITEMS; i > loc; i--)
	{
		array[i] = array[i - 1];
	}
	array[loc] = value;
	ITEMS++;
}

//시간복잡도 O(n)
void delete(int array[], int loc)
{
	int i;
	for (i = loc; i < ITEMS; i++)
	{
		array[i] = array[i + 1];
	}
	ITEMS--;
}

void print_arr(int array[])
{
	int i;
	for (i = 0; i < ITEMS; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}