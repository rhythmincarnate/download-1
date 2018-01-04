#include <stdio.h>

//编译器默认按结构体中最大的类型的字节个数对齐
/*
	在64位os   
	gcc 对齐规则
		按结构体中最大字节个数成员对齐	
	gcc 为什么要对齐:
   		方便编译器存取数据	
 */

struct test_st {
	char ch1;
	short ch2;
	char ch3;
	long ch4;
	char ch5;
	char ch7;
	int ch6;
}ts;

int main(void)
{
	printf("%p, %p, %p, %p, %p, %p, %p\n", &ts.ch1, &ts.ch2, &ts.ch3, &ts.ch4, \
			&ts.ch5, &ts.ch7, &ts.ch6);
	
	printf("%ld\n", sizeof(ts));

	return 0;
}

