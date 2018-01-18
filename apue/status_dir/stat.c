#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char **argv)
{
	struct stat res;

	if (argc < 2)
		return 1;

	if (stat(argv[1], &res) < 0) {
		perror("stat()");		
		return 1;
	}

	printf("%o\n", res.st_mode);

	//判断类型
	if ((res.st_mode & S_IFMT) == S_IFSOCK) {
		putchar('s');
	} else if ((res.st_mode & S_IFMT) == S_IFREG ) {
		putchar('-');
	} else if (S_ISDIR(res.st_mode)) { 
		putchar('d');	
	} else {
		puts("can you guess it?");
	}

	//判断文件权限
	if (res.st_mode & S_IRUSR)
		putchar('r');
	else
		putchar('-');
	if (res.st_mode & S_IWUSR)
		putchar('w');
	else
		putchar('-');
	if (res.st_mode & S_IXUSR) {
		if (res.st_mode & S_ISUID)	
			putchar('s');
		else
			putchar('x');
	}else
		putchar('-');
	
	//判断文件硬链接个数
	printf("  %ld ", res.st_nlink);	

	//拥有者(/etc/passwd)　所属组
	//printf(" %d %d ", res.st_uid, res.st_gid);
	struct passwd *pwd = getpwuid(res.st_uid);
	//if error
	printf(" %s ", pwd->pw_name);
	struct group *grp = getgrgid(res.st_gid);
	printf(" %s ", grp->gr_name);

	//文件字节个数
	printf(" %ld ", res.st_size);

	//时间(mtime)
	struct tm *tmp = NULL;
	char buf[128] = {};
	tmp = localtime(&(res.st_mtim.tv_sec));
	//if error
	strftime(buf, 128, "%m月 %d %H:%M", tmp);
	printf(" %s ", buf);

	putchar('\n');

	return 0;
}

