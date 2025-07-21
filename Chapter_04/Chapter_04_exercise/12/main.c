#include <stdio.h>
#include "../10/stack.h"

int main(void)
{
	char ch;
	stack s;
	init(&s);

	printf("문자열을 입력하시오 : ");
	ch = getchar();
	printf("압축된 문자열 : ");

	while (ch != '\n')
	{
		if (ch < 97) ch += 32;

		if (is_empty(&s) || peek(&s) == ch) push(&s, ch);
		else
		{
			printf("%d%c", s.top + 1, peek(&s));
			s.top = -1;
			push(&s, ch);
		}
		ch = getchar();
	}
	printf("%d%c", s.top + 1, peek(&s));

	return 0;
	
}