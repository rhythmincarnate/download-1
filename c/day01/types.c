#include <stdio.h>
#include <stdint.h>/*定义的类型*/
/*
	c基本类型:
		bool
   		char 
		short int long (long long)	
		float double (long double)
		void

		signed / unsigned
	计算机按位存储	
		"人"按字节
		1byte = 8bit
 
 */
int main(void)
{
	/*
	 	变量的定义
			type name;
		声明不分配地址空间(多文件)
		同一个变量可以声明多次，但只能定义一次
		变量的初始化
			定义的同时赋初始值
	 */
	short a;//signed short a;
	char b;
	int number = 0;//初始化
	uint32_t var;
	int16_t var2;

	printf("sizeof(a):%ld, sizeof(b):%ld\n", sizeof(a), sizeof(b));
	printf("sizeof(int):%ld\n", sizeof(int));
	printf("sizeof(long):%ld\n", sizeof(long));
	printf("sizeof(long long):%ld\n", sizeof(long long));
	printf("sizeof(float):%ld\n", sizeof(float));
	printf("sizeof(double):%ld\n", sizeof(double));
	printf("sizeof(long double):%ld\n", sizeof(long double));

	return 0;
}

