#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMSIZE	120

int mygetline(char **lineptr, int *n, FILE *stream);
int main(int argc, char **argv)
{
	char *p = NULL;
	int n = 0;
	int c;

	while (1) {
		c = mygetline(&p, &n, stdin);	
		if (c < 0)
			break;
		printf("%dbytes:%s\n", c, p);
		free(p);	
		p = NULL;
	}	

	return 0;
}

int mygetline(char **lineptr, int *n, FILE *stream)
{
	char *buf = *lineptr;	
	int size = *n;
	char ch;
	int i = 0;
	
	if (buf == NULL) {
		size = MEMSIZE;
		buf = malloc(size);	
		if (NULL == buf)
			return -1;
		memset(buf, '\0', size);
	}

	while ((ch = fgetc(stream)) != EOF) {
		//空间是否充足
		if (i+2 >= size && ch != '\n') {//i+1-->ch i+2--->'\0'
			buf = realloc(buf, size + MEMSIZE);
			if (NULL == buf)
				return -1;
			memset(buf+size, '\0', MEMSIZE);
			size += MEMSIZE;
		}
		buf[i++] = ch;
		if (ch == '\n')
			break;
	}

	if (ch == EOF && i == 0) {
		return -1;	
	}
	buf[i] = 0;

	*lineptr = buf;
	*n = size;

	return i;
}

