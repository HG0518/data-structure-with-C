#include <stdio.h>
#include <string.h>
#include "quick_sort.h"

void quick_sort(Word list[], int left, int right)
{
	if (left < right)
	{
		int pivot = pivoting(list, left, right);
		quick_sort(list, left, pivot - 1);
		quick_sort(list, pivot + 1, right);
	}
}

int pivoting(Word list[], int left, int right)
{
	int size = right - left + 1;
	Word pivot = list[left];
	int low = left;
	int high = right + 1;
	Word t;

	do
	{
		do
			low++;
		while (low <= right && strcmp(pivot.word, list[low].word) > 0);

		do
			high--;
		while (strcmp(pivot.word, list[high].word) < 0);

		if (low < high)
		{
			SWAP(list[low], list[high], t);
		}

	} while (high > low);
	SWAP(list[left], list[high], t);

	return high;
}

