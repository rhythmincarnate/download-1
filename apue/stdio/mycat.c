#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE	32

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	int ch;
	char buf[BUFSIZE] = {};

	if (argc < 2)
		return 1;

	fp = fopen(argv[1], "r");
	if (NULL == fp) {
		perror("fopen()");
		return 1;
	}

	while (1) {
#if 0
		//按字节读取
		ch = fgetc(fp);
		if (ch == EOF) {
			if (ferror(fp)) {
				goto ERROR;
			}
			//文件结束
			break;
		}
		fputc(ch, stdout);
		fflush(NULL);
		//write(1, &ch, 1);
		sleep(1);
#endif
		//按行读写	
		if (fgets(buf, BUFSIZE, fp) == NULL) {
			break;
		}
		fputs(buf, stdout);
		memset(buf, '\0', BUFSIZE);
	}

	if (ferror(fp)) {
		goto ERROR;
	}

	fclose(fp);

	return 0;
ERROR:
	fclose(fp);
	return 1;
}

