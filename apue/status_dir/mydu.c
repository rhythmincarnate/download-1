#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>

#define BUFSIZE	128

int mydu(const char *pathname);
int __mydu(const char *pathname);
int main(int argc, char **argv)
{
	int ret = 0;

	if (argc < 2)
		return 1;
	if ((ret = mydu(argv[1])) >= 0)
		printf("%dK %s\n", ret, argv[1]);

	return 0;
}

int mydu(const char *pathname)
{
	int res;

	if ((res = __mydu(pathname)) < 0)
		return -1;

	return res / 2;
}

//占多少blocks
int __mydu(const char *pathname)
{
	struct stat res;
	int sum = 0;
	char buf[BUFSIZE] = {};
	char buf2[BUFSIZE] = {};
	glob_t glres;

	if (stat(pathname, &res) < 0) {
		perror("stat()");
		return -1;
	}
	//判断是否是目录
	if (!S_ISDIR(res.st_mode)) {
		return res.st_blocks;	
	}
	
	//目录本身
	sum += res.st_blocks;
	//解析目录"/etc" 
	strncpy(buf, pathname, BUFSIZE);
	strncat(buf, "/*", BUFSIZE);
	//buf--->"/etc/*"
	glob(buf, 0, NULL, &glres);
	//隐藏文件
	strncpy(buf, pathname, BUFSIZE);
	strncat(buf, "/.*", BUFSIZE);
	glob(buf, GLOB_APPEND, NULL, &glres);

	//组织"/etc/." "/etc/.."
	strncpy(buf, pathname, BUFSIZE);
	strncat(buf, "/.", BUFSIZE);
	strncpy(buf2, pathname, BUFSIZE);
	strncat(buf2, "/..", BUFSIZE);

	for (int i = 0; i < glres.gl_pathc; i++) {
		//去除目录的"." ".."
		if (!strcmp((glres.gl_pathv)[i], buf) || !strcmp((glres.gl_pathv)[i], buf2))
			continue;
		sum += __mydu((glres.gl_pathv)[i]);
	}

	return sum;
}



