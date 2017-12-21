//#include <stdio.h>
#include "stdio.h"//允许，先找默认路径
/*
gcc编译步骤:
	1.预处理
		gcc -E 
		#include <stdio.h>将"stdio.h"文件展开
		多行注释
		#if 0
		#endif
	2.编译
		gcc -S
		将c翻译成汇编
	3.汇编
		gcc -c
		执行汇编指令--->elf
	4.链接
		链接库，最终生成可执行文件

#开头的--->预处理
#include 包含头文件
什么是头文件?
	头文件相当于说明书
	类型的定义　函数的声明
#include "xxx.h"
 */

//main有且仅有一个
/*
 	main是整个工程的入口函数
	main主要一下两种形式
		int main(void)
		{
		
		}
		int main(int argc, char **argv)
		{
		
		}
 */
/*
 编程规范
 	Tab缩进(推荐４字节)
	函数内函数体相对于函数缩进
	双目运算符 a = b;
	if () {
		xxxx;
	}
 */
int main(void)
{
#if 1
	printf("hello world \rg\bood\n");	
	printf("hello\tworld\n");
	/*
	 	字符	'' 	ascii (128个) man ascii
			'a' ' ' '\n'
		字符串	""一定已'\0'结束的

		'\n'转义字符 表示换行
		'\t'		制表符(Tab)
		'\b'		退格符(Backspace)
		'\r'		回车

	 */

#endif
	//while (1);
	return 0;
	/*
	关键字 
		c标准保留的名字 
			return--->函数的返回值
			void--->空类型
			类型　语句　
	标识符
		变量名，函数名，类型名
		由字母，数字，下划线组成,字母或下划线开头
		区分大小写	a A
		"顾名思义"
	 */
}

