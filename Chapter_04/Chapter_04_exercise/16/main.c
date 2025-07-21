#include <stdio.h>
#include <string.h>
#include "../10/stack.h"

int main(void)
{
	char str[30];
	stack s;
	init(&s);
	int i;
	int check = 0;

	printf("문자열을 입력하시오 : ");
	gets(str, sizeof(str));
	
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
			push(&s, str[i]);
		}
		else if (str[i] >= 97 && str[i] <= 122) push(&s, str[i]);
	}

	int size = s.top + 1;
	for (i = 0; i <= size / 2; i++)
	{
		if (s.data[i] != pop(&s))
		{
			check++;
			break;
		}
	}

	if (check) printf("회문이 아닙니다.\n");
	else printf("회문입니다.\n");

	return 0;
}