#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;		

	fd = open("./test", O_RDWR);
	if (fd < 0) {
		perror("open()");
		return 1;
	}
	dup2(fd, 1);

	printf("good afternoon everyone!\n");

	return 0;
}

