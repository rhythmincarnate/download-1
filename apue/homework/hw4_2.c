#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int mycat(int fd);
int main(int argc, char **argv)
{
	int sfd;
	int newfd;
	
	if (argc != 2 && argc != 4)
		return 1;

	sfd = open(argv[1], O_RDONLY);
	if (sfd < 0) {
		perror("open()");
		goto ERROR1;
	}
	if (argc == 4 && !strcmp(argv[2], ">")) {
		newfd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);	
		if (newfd < 0) {
			perror("open()");
			goto ERROR2;
		}
		dup2(newfd, 1);	
		close(newfd);
	}

	mycat(sfd);

	close(sfd);

	return 0;
ERROR2:
	close(sfd);
ERROR1:
	return 1;
}

int mycat(int fd)
{
	char buf[100] = {};
	int cnt;

	while (1) {
		cnt = read(fd, buf, 100);	
		if (cnt < 0) {
			perror("read()");
			return -1;
		}
		if (cnt == 0)
			break;
		write(1, buf, cnt);
	}
	return 0;
}




