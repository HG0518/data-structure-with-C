#include <stdio.h>
#include <string.h>
#include "../10/stack.h"
#define MAZE_SIZE 6

element here = { 1,0 }, entry = { 1,0 };
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','0','0','1','1'},
	{'1','1','0','1','1','1'},
	{'1','1','0','1','1','1'},
	{'1','0','0','0','0','x'},
	{'1','1','1','1','1','1'},
};

void push_loc(stack* s, int r, int c)
{
	if (r < 0 || c < 0)return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	stack s;
	stack path;

	init(&s);
	init(&path);
	here = entry;

	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		push(&path, here);
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s))
		{
			printf("실패\n");
			exit(1);
		}
		else here = pop(&s);
	}

	printf("성공\n");
	printf("경로 : ");

	int i;
	int n = path.top;
	element point;
	for (i = 0; i <= n; i++)
	{
		point = path.data[i];
		printf("(%d, %d) > ", point.r, point.c);
	}
	printf("출구\n");


	return 0;
}