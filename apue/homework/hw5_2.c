#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

static int src2dest(FILE *sfp, FILE *dfp);
int main(int argc, char **argv)
{
	FILE *fp1, *fp2;
	int n;
	int linecnt = 0;
	char *lineptr = NULL;
	size_t linesize = 0;

	if (argc < 4)
		return 1;
	n = atoi(argv[2]);

	fp1 = fopen(argv[1], "r+");
	if (NULL == fp1) {
		perror("fopen()");	
		return 1;
	}
	fp2 = fopen("./hwtest5", "w+");
	if (NULL == fp2) {
		perror("fopen()");
		goto ERROR1;
	}

	while (1) {
		if (getline(&lineptr, &linesize, fp1) < 0)
			break;
		linecnt ++;
		if (linecnt == n)
			fputs(argv[3], fp2);
		fputs(lineptr, fp2);	
		//free(lineptr);
		//lineptr = NULL;
	}
	if (linecnt < n)
		return 0;
	//fp2文件满足条件				
	rewind(fp1);
	rewind(fp2);
	src2dest(fp2, fp1);

	free(lineptr);
	fclose(fp1);
	fclose(fp2);

	return 0;
ERROR1:
	fclose(fp1);
	return 1;
}

static int src2dest(FILE *sfp, FILE *dfp)
{
	char buf[BUFSIZE] = {};
	int cnt;

	while (1) {
		cnt = fread(buf, 1, BUFSIZE, sfp);	
		if (cnt == 0) {
			if (ferror(sfp))
				return -1;
			break;
		}
		fwrite(buf, 1, cnt, dfp);	
	 }

	return 0;
}


