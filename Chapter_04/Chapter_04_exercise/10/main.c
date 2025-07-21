#include <stdio.h>
#include "stack.h"

int main(void)
{
	stack s;
	init(&s);
	
	int n, i, num;
	printf("정수 배열의 크기 : ");
	scanf("%d", &n);
	printf("정수를 입력하시오 : ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		push(&s, num);
	}

	printf("반전된 정수 배열 : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", pop(&s));
	}

	free_s(&s);

	return 0;
}
