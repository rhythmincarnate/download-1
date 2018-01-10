#include <stdio.h>

#include <squeue.h>

//argv[1]字符串中的每一个字符入队
int main(int argc, char **argv)
{
	squeue_t *s = NULL;
	char ch;

	if (argc < 2)
		return 0;	

	squeue_init(&s, 10,sizeof(char));

	for (int i = 0; argv[1][i] != '\0'; i++) {
		if (squeue_isfull(s)) {
			for (int j = 0; j < 3; j++) {
				squeue_deq(s, &ch);	
				printf("%c ", ch);
			}
			printf("\n");
		}
		squeue_enq(s, argv[1] + i);	
	}	

	while (!squeue_isempty(s)) {
		squeue_deq(s, &ch);	
		printf("%c ", ch);
	}
	printf("\n");

	squeue_destroy(s);

	return 0;
}

