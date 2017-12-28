#include <stdio.h>

int main(void)
{
	//将字符串的每一个字符赋值给字符数组的每一个成员
	char str[] = "hello world";
	//将字符串的首地址赋值给指针变量p
	char *p = "good afternoon";
	const char *q;//常量指针 *q只读
	char const *m;//常量指针 *m只读
	char *const n = str;//指针常量	n只读

	str[0] = 'H';
	//*p = 'G';
	p = str;
	*p = 'G';
	printf("%s\n", str);

	q = str;
	//*q = 'M';
	str[0] = 'M';
	printf("%s\n", str);

	q++;
	printf("%s\n", q);

	m = q;
	//*m = 'E';

	//指针常量
	//n = q;	
	*n = 'N';
	printf("%s\n", str);

	return 0;
}

