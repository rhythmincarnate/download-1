#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE	100
#define TMPFILE	"./hw"

int mycpyfile(int sfd, int dfd);
int copy_another(int fd, const char *pathname);
int main(int argc, char **argv)
{
	int fd1, fd2;	

	if (argc < 3)	
		return 1;

	//打开argv[1]--->./hw
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0) {
		perror("open()");
		return 1;
	}
	fd2 = open(TMPFILE, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd2 < 0) {
		perror("open()");
		goto ERROR1;
	}

	mycpyfile(fd1, fd2);

	//
	lseek(fd2, 0L, SEEK_SET);
	copy_another(fd2, argv[2]);

	close(fd1);
	close(fd2);

	return 0;
ERROR1:
	close(fd1);
	return 1;
}

/*
fd:要复制的源文件 
pathname:最终fd文件去掉第二行后，写入的文件的路径
 */
int copy_another(int fd, const char *pathname)
{
	char tmp;	
	int dfd;
	int flag = 0;
	int cnt;

	dfd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (dfd < 0) {
		perror("open()");
		return -1;
	}

	//读fd 写dfd
	//先将fd第一行写入dfd
	//读fd第二行
	while (1) {
		cnt = read(fd, &tmp, 1);
		if (cnt < 0) {
			perror("read()");
			close(dfd);
			return -1;
		}
		if (cnt == 0)
			break;
		if (flag != 1)
			write(dfd, &tmp, 1);
		if (tmp == '\n') {
			flag ++;
		}
	}

	return 0;
}

/*
sfd:源文件 
dfd:目标文件
 */
int mycpyfile(int sfd, int dfd)
{
	char buf[BUFSIZE] = {};
	int cnt;

	while (1) {
		cnt = read(sfd, buf, BUFSIZE);	
		if (cnt < 0) {
			perror("read()");
			return -1;
		}
		if (cnt == 0)
			break;
		write(dfd, buf, cnt);	
	}

	return 0;
}


