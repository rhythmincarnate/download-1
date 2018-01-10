#include <stdio.h>

#include <stack.h>

//argv[1]字符串中的每一个字符入栈
int main(int argc, char **argv)
{
	stack_t *s = NULL;
	char ch;

	if (argc < 2)
		return 0;	

	s = init(sizeof(char), 10);

	for (int i = 0; argv[1][i] != '\0'; i++) {
		if (isfull(s)) {
			printf("栈已满\n");
			break;
		}
		push(s, argv[1] + i);	
		printf("%c 入栈\n", argv[1][i]);
	}	

	while (!isempty(s)) {
		pop(s, &ch);	
		printf("%c ", ch);
	}
	printf("\n");

	destory(s);

	return 0;
}

