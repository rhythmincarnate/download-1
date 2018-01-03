#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void handler1(int s)
{
	printf("瞅你咋地?\n");	
}

static void handler2(int s)
{
	printf("大哥！不看了\n");
}

int main(void)
{
	int cnt = 0;
	//为信号注册行为	2--->ctrl+c
	signal(2, handler1);

	while (1) {
		printf("cnt:%d\n", cnt);
		printf("看什么看\n");	
		sleep(1);	
		cnt ++;
		if (cnt == 10)
			signal(2, handler2);
	}

	return 0;
}

