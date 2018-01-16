#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd, newfd;

	if (argc < 2)
		return 1;

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		perror("open()");
		return 1;
	}
	printf("fd:%d\n", fd);

#if 0
	//不原子操作
	close(0);
	newfd = dup(fd);
	printf("newfd:%d\n", newfd);
#endif
	//原子操作
	dup2(fd, 0);

	write(0, "hello", 5);
	
	close(fd);

	return 0;
}

