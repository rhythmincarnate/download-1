#include <stdio.h>

#include <io.h>

#define BUFSIZE	32

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 2)
		return 1;

	fp = fopen(argv[1], "r");
	if (NULL == fp)
		IO_ERR(fopen);//自定义

	fseek(fp, 10, SEEK_SET);	
	fread(buf, 1, 3, fp);
	printf("buf:%s\n", buf);
	printf("offset:%ld\n", ftell(fp));

	rewind(fp);

#if 1
	while (1) {
		cnt = fread(buf, 1, BUFSIZE, fp);
		if (cnt == 0) {
			if (ferror(fp)) {
				fclose(fp);
				IO_ERR(fread);
			}
			break;
		}
		fwrite(buf, 1, cnt, stdout);
	}
#endif

	fclose(fp);

	return 0;
}

