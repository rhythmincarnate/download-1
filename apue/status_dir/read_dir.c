#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

extern int errno;//外部声明

int main(int argc, char **argv)
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;

	if (argc < 2)	
		return 1;

	dp = opendir(argv[1]);
	if (NULL == dp) {
		perror("opendir()");
		return 1;
	}

	errno = 0;
	while (1) {
		entry = readdir(dp);
		if (NULL == entry) {
			if (errno == 0)		
				break;
			perror("readdir()");
			goto ERROR;
		}
		puts(entry->d_name);
	}

	closedir(dp);

	return 0;
ERROR:
	closedir(dp);
	return 1;
}

