#include <stdio.h>

#if 0
//表达式非0即真
if (表达式) {
	执行体;
}

if () {

} else {

}

if () {

} else if () {

} else if () {

} else {

}

#endif

int main(void)
{
	int num = 108;	

	//为变量读入一个整型值
	//"读入格式"
	printf("请输入一个整型数: ");
	scanf("%d", &num);

#if 0
	if (!(num % 2)) {
		printf("hello world\n");	
	} else {
		printf("num:%d\n", num);
	}
#endif

	if (!(num % 2) && num > 100) {
		printf("hello\n");
	} else if (!(num % 2) && num <= 100) {
		printf("world\n");
	} else if (num % 2 && num > 100) {
		printf("good\n");
	} else {
		printf("morning\n");
	}

	return 0;
}

