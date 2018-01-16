#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE	32

int main(int argc, char **argv)
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt;

	if (argc < 2)
		return 1;

	fd = open(argv[1], O_RDONLY | O_CREAT, 0666);//mode &(~umask)
	if (fd < 0) {
		printf("open() failed\n");
		goto ERROR;
	}
	printf("succefully fd:%d\n", fd);
	
	//将文件的全部内容读到标准输出
	while (1) {
		cnt = read(fd, buf, BUFSIZE);	
		if (cnt < 0) {
			printf("read() failed\n");
			goto ERROR2;
		}
		if (cnt == 0) {
			//文件末尾
			break;
		}
		//读到字节
		write(1, buf, cnt);
	}

	close(fd);

	return 0;
ERROR2:
	close(fd);
ERROR:
	return 1;
}

