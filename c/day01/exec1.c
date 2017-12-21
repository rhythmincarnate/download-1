/*
 	初始化两个整型变量，分别值为10和26
	在不定义新变量的基础上，将两个整型数交换	
	将第一个整型数的第3位置1
   	将第二个整型数的第2位清0	
 */
#include <stdio.h>

int main(void)
{
	int var1 = 10;
	int var2 = 26;

	var1 = var1 ^ var2;	
	var2 = var1 ^ var2;// var1 ^ var2 ^ var2
	var1 = var1 ^ var2;	
	printf("var1:%d, var2:%d\n", var1, var2);

	var1 = var1 + var2;
	var2 = var1 - var2;
	var1 = var1 - var2;
	printf("var1:%d, var2:%d\n", var1, var2);

	var1 = var1 | (1u<<2);//var1 |= (1u<<2);
	var2 = var2 & ~(1u << 1);

	printf("var1:%d, var2:%d\n", var1, var2);

	return 0;
}

