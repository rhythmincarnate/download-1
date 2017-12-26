#include <stdio.h>

/*
#开头的都是预处理指令
	末尾都没有;
	习惯大写
	在同一行
 */

//宏定义--->gcc预处理阶段　替换
#define NUM 10

//宏函数--->参数一定要加括号 效率高，只适合简单的算法
#define MAX2NUM(m, n)	(m) > (n) ? (m) : (n)

#define SQUARE(m)		(m)*(m)

//typeof(m)取得变量m的类型
#define SWAP2NUM(m, n)	\
	do {\
		typeof(m) tmp;\
		tmp = m;\
		m = n;	\
		n =	tmp;\
	}while(0)

#define SECONDYEAR	365*24*60*60UL

int main(void)
{
#if 0

#endif

#ifndef HELLO
#define HELLO
	printf("hello world\n");
#endif

#ifndef HELLO
	printf("good morning\n");
#endif

	int n1, n2;
	int max;

	for (int i = 0; i < NUM; i++) {
		printf("%d ", i);	
	}
	printf("\n");

	n1 = 10;
	n2 = 50;

	max = MAX2NUM(n1+=10, n2-100);
	printf("max:%d\n", max);

	n1 = 5;
	printf("%d\n", SQUARE(n1+2));

	printf("n1:%d, n2:%d\n", n1, n2);
	SWAP2NUM(n1, n2);
	printf("n1:%d, n2:%d\n", n1, n2);

	printf("line:[%d]function:[%s]file:[%s]date:[%s]\n", __LINE__, __FUNCTION__, __FILE__, __DATE__);	

	return 0;
}

