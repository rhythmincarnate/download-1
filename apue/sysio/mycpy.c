#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>/*errno 全局变量在此头文件中有定义*/

#define BUFSIZE 100

int main(int argc, char **argv)
{
	int rfd, wfd;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 3)
		return 1;

	rfd = open(argv[1], O_RDONLY);
	if (rfd < 0) {
		perror("open()");
		goto ERROR1;	
	}
	//打开argv[2]文件，以只写方式打开，不存在创建，存在截断为0
	//wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	wfd = open(argv[2], O_WRONLY | O_APPEND);
	if (wfd < 0) {
		perror("open()");
		goto ERROR2;
	}

	//将rfd文件复制到wfd
	while (1) {
		cnt = read(rfd, buf, BUFSIZE);	
		if (cnt < 0) {
			perror("read()");
			goto ERROR3;
		}
		if (cnt == 0)
			break;
		write(wfd, buf, cnt);	
	}

	close(rfd);
	close(wfd);

	return 0;
ERROR3:
	close(wfd);
ERROR2:
	close(rfd);
ERROR1:
	return 1;
}

