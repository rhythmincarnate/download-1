#include <stdio.h>
#include <stdlib.h>

int mygetline(char **lineptr, int *n, FILE *fp)
{




}

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t cnt;

	if (argc < 2)
		return 1;

	fp = fopen(argv[1], "r");
	if (NULL == fp) {
		perror("fopen()");
		return 1;
	}
	if ((cnt = getline(&lineptr, &n, fp)) < 0) {
		perror("getline()");
		goto ERROR;
	}

	printf("n:%ld\n", n);
	printf("共%ld字节\n", cnt);
	printf("%s\n", lineptr);

	free(lineptr);

	return 0;
ERROR:
	fclose(fp);
	return 1;
}

