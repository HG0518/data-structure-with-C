#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "dictionary.h"
#include "quick_sort.h"

void dictionary()
{
	Dictionary dic;
	insert_dic(&dic);

	quick_sort(dic.list, 0, SIZE);

	printf("정렬 후 사전의 내용 \n");
	print_dic(&dic);
}

void insert_dic(Dictionary* dic)
{
	printf("%d개의 단어와 의미를 입력하시오,\n", SIZE);
	for (int i = 0; i < SIZE; i++)
		scanf("%s %s", dic->list[i].word, dic->list[i].meaning);
	printf("\n");
}

void print_dic(Dictionary* dic)
{
	for (int i = 0; i < SIZE; i++)
		printf("%s : %s\n", dic->list[i].word, dic->list[i].meaning);
	printf("\n");
}