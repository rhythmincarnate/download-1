#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//argv[1]
int main(int argc, char **argv)
{
	int fd;
	char buf[100] = {};
	
	if (argc < 2)
		return 0;

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		perror("open()");
		return 1;
	}

	//printf("%ld\n", lseek(fd, -5, SEEK_END));
	//文件所占的字节个数
	printf("%ld\n", lseek(fd, 0, SEEK_END));

	//offet == the size of the file

	//1G
	lseek(fd, 1024*1024*1024*1UL, SEEK_CUR);

	write(fd, "hello", 5);

#if 0
	read(fd, buf, 100);
	puts(buf);
#endif

	close(fd);

	return 0;
}

