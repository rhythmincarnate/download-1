#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getchar(3) / putchar(3) / gets(3) / puts(3)
// n = getchar() ====>scanf("%c", &n);
// putchar(n) ====> printf("%c", n);
// gets(buf) ====> scanf("%s", buf);
// puts(buf) ====> printf("%s\n", buf);

static int mygets(char **ptr);
int main(void)
{
	char ch;
	char *buf = NULL;

	ch = getchar();
	putchar(ch);

	//gets(buf); Never use it

	mygets(&buf);
	puts(buf);

	free(buf);
	buf = NULL;

	return 0;
}

//定义一个函数，功能是从终端读入一行字符串(字符串不管多长都要读)
//static char *mygets(void)
static int mygets(char **ptr)
{
	char *p;
	int len = 0;//空间的字节个数
	int cnt = 0;//读入的字节个数

	p = NULL;
	while (1) {
		if (cnt == len) {//字符串
			len += 10;
			p = realloc(p, len);//增大	
			if (NULL == p)
				return -1;
			//新开辟的地址空间初始化
			memset(p+cnt, '\0', len-cnt);
		}

		p[cnt] = getchar();
		if (p[cnt] == '\n') {
			p[cnt] = '\0';	
			break;
		}
		cnt ++;
	}
	if (cnt+1 < len) {
		p = realloc(p, cnt+1);//减少
		//if error
	}

	*ptr = p;

	return 0;
}


