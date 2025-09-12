#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "dictionary.h"
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void quick_sort(Word list[], int left, int right);
int pivoting(Word list[], int left, int right);

#endif // !QUICK_SORT_H
