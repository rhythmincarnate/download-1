#include <stdio.h>

/*
   为什么传参
   为什么不能改变实参
	
	局部变量
		在函数体内定义的变量
		作用域:
			从定义开始到函数结束
		生存周期:
			从定义开始到函数结束
	全局变量
		作用域
			从定义开始到整个工程(多文件)
		生存周期
			从定义开始到进程结束
		全局变量的使用忠告:
			1.能不用就不用(多线程)	
			2.如果一定要用,用static修饰

	修饰变量的关键字
		auto	默认
		static 静态变量
		const  主要修饰指针 只读变量
		volatile 易失变量　防止编译优化
		register 寄存器变量
 */

int glob;//未初始化的全局自动变量，存bss段，值为0
int glob2 = 100;//已初始化的全局自动变量,存data段

static int glob3;
/*
	限制的作用域 
	static 所修饰的全局变量只能在本文件中使用
 */

//声明
static void swap2num(int a, int b);
/*
 	static修饰函数，限制了函数调用的作用域
	本函数只能在本文件中调用
 */
int test(void);
int main(void)
{
	//volatile
	volatile int i = 1;
	int j = 2;
	printf("%d %d %d\n", i++, ++i, i--);//函数的传参顺序是至右向左
	//printf(const char *p, int a, int b, int c);

	printf("j:%d\n", j, j++, j++);
	

#if 0
	//const
	const int var2 = 1;//var2只读变量,变量名只读

	//var2 = 2;
	printf("var2:%d\n", var2);
#endif
#if 0
	//num1 num2局部变量
	auto int num1 = 100;//已初始化的局部自动变量-->stack
	int num2 = 200;
	int var;//未初始化的局部自动变量--->stack　值为随机值

	printf("num1:%d, num2:%d\n", num1, num2);
	swap2num(num1, num2);//实参
	printf("after swap2num\n");
	printf("num1:%d, num2:%d\n", num1, num2);
#endif
#if 1
	//static
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
#endif

	return 0;
}

/*
	交换两个整型数 
 */
static void swap2num(int a, int b)//形参
{
	int t;

	t = a;
	a = b;
	b = t;
	printf("a:%d, b:%d\n", a, b);
}

int test(void)
{
	static int n = 1, m;
	//n是局部静态变量,只初始化一次,生存周期，从定义开始到进程结束\
	　存储在内存的data段
	//static int m;
	//m是未初始化的局部静态变量，只定义一次，生存周期，从定义开始到进程结束\
		存储在内存的bss段 初值为0
	n ++;
	m++;
	printf("m:%d\n", m);
	return n;
}

