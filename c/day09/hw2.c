#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int change_char(char *ch);
static int change_str(char *p);
static int mygets(char **ptr);
int main(void)
{
	char *buf = NULL;

	mygets(&buf);
	puts(buf);

	change_str(buf);
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

/*
	大小写转换 
ch:待转换的变量的地址
return value:
	0　　成功
	-1 　失败
 */
static int change_char(char *ch)
{
	if ((*ch) >= 'a' && (*ch) <= 'z')		
		*ch = *ch - ('a'-'A');
	else if ((*ch) >= 'A' && (*ch) <= 'Z')
		*ch = *ch + ('a'-'A');
	else
		return -1;

	return 0;
}

/*
 将字符串大写转小写　小写转大写
 */
static int change_str(char *p)
{
	while (*p) {
		change_char(p);
		p++;
	}

	return 0;
}




