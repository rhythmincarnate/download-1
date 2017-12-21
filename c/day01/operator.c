#include <stdio.h>

#if 0
man operator
	1.使用	2.优先级
	
	算术运算符
		+ - * / %(模) 
		4 % 3 ----> 1
	赋值运算符
		= += -= *= /= %=	
	位运算符
		& | ^ ~ << >> 
		课后小练习
			将任意整型数的第3为置1
			将任意整型数的第3位清0	
	逻辑运算
		0假 1真
		&& || !
		exp1 && exp2
		exp1假 exp2不会判断
		exp1 || exp2
		exp1真 exp2不会判断
		小练习
			写一个表达式，判断出ch不属于字母
			!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	自增自减运算符
		++ --
		a ++; ++a;	
	条件运算符
		? :
		== != > < >= <=
		2<= x <= 10;不可以
		x >= 2 && x <= 10;

	逗号运算符
		,
	强转运算符
		(type)
		int var = 100;
		char ch = 1;
			var = (int)ch;
	sizeof()计算变量/类型所占用的字节个数

	[] 
		a[b] ----> *(a+b)

#endif

int main(void)
{
	int a = 10;
	int b = 20;
	int c, d; //int c, int d;错误的 int c; int d;
	char ch;

	c = a + b;//表达式
	printf("a:%d, b:%d, c:%d\n", a, b, c);
	//赋值可以连续
	a = b = c;
	printf("a:%d, b:%d, c:%d\n", a, b, c);
	//
	a += 10;
	// a = a + 10;
	printf("a:%d\n", a);

	//异或
	a = 10;
	b = 20;

	a = a ^ b;
	b = a ^ b;//(a ^ b) ^ b == a ^ (b ^ b) == a
	a = a ^ b;//a ^ (a ^ b) == (a ^ a) ^ b == b

	printf("a:%d, b:%d\n", a, b);

	//自增自减
	a = 1, b = 2;
	c = a++; //c = a; a = a + 1;
	d = ++b;//b = b+1; d = b;
	printf("a:%d, b:%d, c:%d, d:%d\n", a, b, c, d);
	//a 2  b 3 c 1 d 3
	c = a++ +b;//贪婪规则
	printf("a:%d, b:%d, c:%d, d:%d\n", a, b, c, d);

	//? :	
	a = 10, b = 20;

	c = a > b ? a++ : --b;
	printf("a:%d, b:%d, c:%d, d:%d\n", a, b, c, d);

	ch = ' ';
	!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) ? \
			 printf("不是字母\n") : printf("是字母\n");

	//,
	a = 1, b = 2, c = 3;
	d = (a++, b++, c++, a+b);//从左至右表达式依次执行，最后结果是最后一个表达式的值
	printf("a:%d, b:%d, c:%d, d:%d\n", a, b, c, d);

	//sizeof()
	printf("sizeof(a):%ld sizeof(int):%ld, sizeof a :%ld\n",\
		  sizeof(a), sizeof(int), sizeof a);

	//[]
	a = 0x12345678;
	printf("%x\n",((char *)&a)[1]);//目前不要纠结

	return 0;
}

