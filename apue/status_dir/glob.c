#include <stdio.h>
#include <glob.h>

int main(void)
{
	glob_t res;

	if (glob("./abc", GLOB_NOCHECK, NULL, &res) != 0) {
		fprintf(stderr, "glob() failed\n");
		return 1;
	}

	glob("/etc/.*", GLOB_APPEND, NULL, &res);

	for (int i = 0; i < res.gl_pathc; i++) {
		puts((res.gl_pathv)[i]);	
	}

	globfree(&res);

	return 0;
}


