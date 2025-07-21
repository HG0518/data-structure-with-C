#include <stdio.h>
#include "../10/stack.h"

int main(void) 
{
	int n, q = 1, r, i;
	stack s;
	init(&s);
	
	printf("정수를 입력하시오 : ");
	scanf("%d", &n);

	while (q != 0)
	{
		q = n / 10;
		r = n % 10;

		if (is_empty(&s) || peek(&s) != r) push(&s, r);

		n = q;
	}

	printf("출력 : ");

	int t = s.top;
	for (i = 0; i <= t; i++)
	{
		printf("%d", pop(&s));
	}

	return 0;
}