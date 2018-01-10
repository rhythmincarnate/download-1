#include <stdio.h>

#include <lqueue.h>

//argv[1]字符串中的每一个字符入队
int main(int argc, char **argv)
{
	lqueue_t *s = NULL;
	char ch;

	if (argc < 2)
		return 0;	

	lqueue_init(sizeof(char), &s);

	for (int i = 0; argv[1][i] != '\0'; i++) {
		lqueue_enq(s, argv[1] + i);	
	}	

	while (!lqueue_isempty(s)) {
		lqueue_deq(s, &ch);	
		printf("%c ", ch);
	}
	printf("\n");

	lqueue_destory(s);

	return 0;
}

