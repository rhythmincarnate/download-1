#include <stdio.h>

#define BUFSIZE 16 

int main(void)
{
	char buf[BUFSIZE] = {};

	fgets(buf, BUFSIZE, stdin);
	fputs(buf, stdout);

	return 0;
}

