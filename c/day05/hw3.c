#include <stdio.h>

#define	NUM	41

int main(void)
{
	int arr[NUM] = {}; /*0 alive   1 quit*/
	int quitcnt = 0;
	int cnt = 0;

	for (int i = 0; quitcnt < NUM-1; i = (i+1) % NUM) {
		if (!arr[i]) {
			//alive	
			cnt ++;
			if (cnt == 3) {
				arr[i] = 1;
				printf("%d被killed\n", i+1);
				quitcnt ++;
				cnt = 0;
			}
		}
	}

	for (int i = 0; i < NUM; i++) {
		if (!arr[i]) {
			printf("胜利的是:%d\n", i+1);	
			break;
		}
	}

	return 0;
}

