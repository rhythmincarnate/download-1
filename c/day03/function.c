#include <stdio.h>

/*
	函数:
		作用:
			代码简单化：减少功能相同的代码的重复
			功能化,模块化
   		定义
		声明
		调用		
	变量
   		局部变量
		全局变量
		静态变量	
		只读变量
	特殊的函数
		变参
		递归
	宏
 */

/*
 函数的声明
 	函数名
	函数的参数列表的类型
	返回值类型
 */
int sumn(int);

int main(void)
{
	int num = 100;
	int res;
	/*
	 	函数的调用
			xxx = 函数名(传递参数值)
			函数的传参是值传递的过程
			函数的返回值也是值返回
	 */	
#if 0
	res = sumn(num); //number = num
	printf("%d的前n项和为%d\n", num, res);
#endif
	printf("%d的前n项和为%d\n", num, sumn(num));
	//printf(const char *str, int a, int b);b = sumn(num)

	return 0;
}

/*
	定义:
		函数名	
		参数列表
			输入/输出(指针)
		返回值类型
			输出
			如果函数的返回值类型省略，默认是int类型
			指明函数是没有返回值 void
	功能:求得给定整型输的前n项和 
	sumn:function
	number:待计算的整型数
	return value:
			前n项和
 */
//sumn(int number)
int sumn(int number)
{
	//函数体
	int res = 0;

	for (; number > 0; number --)
		res += number;

	return res;//返回的是变量res的值，不是变量本身
}


