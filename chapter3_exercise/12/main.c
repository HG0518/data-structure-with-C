#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int n;
	char str[20];
}Test;

int main(void)
{
	Test* test = (Test*)malloc(sizeof(Test));
	if (test == NULL)
	{
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}
	test->n = 100;
	strcpy(test->str, "just testing");

	printf("%d\n%s\n", test->n, test->str);

	free(test);

	return 0;
}