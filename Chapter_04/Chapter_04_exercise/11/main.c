#include <stdio.h>
#include "../10/stack.h"

int main(void)
{
	int n = 0;
	char ch;
	stack s;
	init(&s);

	printf("수식 : ");
	ch = getchar();
	printf("괄호 수 : ");
	while (ch != '\n')
	{
		if (ch == '(')
		{
			n++;
			push(&s, n);
			printf("%d ", n);
		}
		else
		{
			printf("%d ", pop(&s));
		}
		ch = getchar();
	}

	free_s(&s);
	return 0;
}