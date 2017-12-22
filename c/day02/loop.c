#if 0
for(@1循环变量的初始化; @2循环条件; @3循环变量的改变) {
	@4循环体;
}
@1-->@2-->真--->@4--->@3--->@2---
		  |						|
	      ----------------------
while (循环条件) {
	循环体;
}

do {
	循环体;
}while (循环条件);
至少执行一次，多用于数值合法性校验(冗错)

break;
continue;

goto 
#endif

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	//int i;
	int cnt = 0;

#if 0
	//for语句中定义的变量,作用域只在for内
	for (int i = 0; i < 10; i++) {
		printf("*");	
	}
	printf("\n");

	//for死循环
	for (; 1;) {
		printf("*");
		fflush(NULL);//刷新输出缓存区
		sleep(1);//延时1s
		cnt ++;
		if (cnt >= 50)
			break;
	}
#endif
#if 0
	int i;//值是随机的

	i = 0;
	while (i < 10) {
		printf("*");
		i ++;
	}
	printf("\n");

	//while死循环
	while (1) {
		printf("*");
		fflush(NULL);//刷新输出缓存区
		sleep(1);//延时1s
	}
#endif

	int number;

	scanf("%d", &number);

	//将1到number之间所有<=100的数值中的偶数输出
	for (int i = 1; i <= number; i++) {
		if (i > 100)
			break;//跳出循环
		if (i % 2)
			continue;//结束本次循环,进入下一次循环
		printf("%d ", i);	
	}	
	printf("\n");

	return 0;
}

