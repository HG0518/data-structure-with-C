#include <stdio.h>
#include <string.h>
#include "../../deque/deque/deque.h"

int main(void) {
	deque d;
	init_deque(&d);
	char str[MAX_DEQUE_SIZE];
	int i, n, count;

	printf("문자열을 입력하세요 : ");
	gets(str, sizeof(str));

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 65 && str[i] <= 90) insert_rear(&d, str[i] + 32);
		else if (str[i] >= 97 && str[i] <= 122) insert_rear(&d, str[i]);
	}

	n = get_count(&d);
	count = 0;
	while (n > 1) {
		if (delete_front(&d) != delete_rear(&d))
		{
			count++;
			break;
		}
		n = get_count(&d);

	}
	if (!count)printf("회문입니다.");
	else printf("회문이 아닙니다.");
}