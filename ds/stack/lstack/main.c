#include <stdio.h>

#include <lstack.h>

//argv[1]字符串中的每一个字符入栈
int main(int argc, char **argv)
{
	lstack_t *s = NULL;
	char ch;

	if (argc < 2)
		return 0;	

	lstack_init(sizeof(char), &s);

	for (int i = 0; argv[1][i] != '\0'; i++) {
		lstack_push(s, argv[1] + i);	
	}	

	while (!lstack_isempty(s)) {
		lstack_pop(s, &ch);	
		printf("%c ", ch);
	}
	printf("\n");

	lstack_destory(s);

	return 0;
}

