#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int num;//待猜测
	int guess;

	/*
		随机数 
		rand(3);
		srand(3);
		time(2);
		time(NULL)返回的就是时间戳(当前时间距离1970-1-1 00:00:00经过的秒数)
		getpid();
	 */	
	//srand(time(NULL));
	srand(getpid());
	num = rand() % 10;
	//printf("num:%d\n", num);
		
	while (1) {
		printf("猜一下这个数值是?\n");	
		scanf("%d", &guess);
		if (guess > num)
			printf("不好意思，大了?\n");
		else if (guess < num) {
			printf("很遗憾！又有点小了\n");
		} else {
			printf("厉害了！！\n");	
			break;
		}
	}

	return 0;
}

