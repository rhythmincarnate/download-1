#if 0
1.读入两个整型数，先输出较大的，再输出较小的
2.读入一个年份，判断是否为闰年
3.读入一个0~100之间的成绩,判断其所属等级
	90~100	A
	80~89	B
	70~79	C
	60~69	D
	0~59	E
#endif 

#include <stdio.h>

int main(void)
{
#if 0
	int num1, num2;	

	printf("请输入两个整型数\n");
	scanf("%d %d", &num1, &num2);

	if (num1 > num2) {
		printf("%d %d\n", num1, num2);
	} else {
		printf("%d %d\n", num2, num1);
	}
#endif
#if 0	
	int year;	

	printf("输入一个年份: ");
	scanf("%d", &year);

	if ((!(year % 4) && year % 100) || (year % 400 == 0))
		printf("%d年是闰年\n", year);
	else 
		printf("%d年是平年\n", year);
#endif
	int score;

	printf("请输入你的成绩\n");
	scanf("%d", &score);

	if (score >= 90 && score <= 100) {
		printf("A\n");
	} else if (score >= 80 && score < 90) {
		printf("B\n");
	} else if (score >= 70 && score <= 79) {
		printf("C\n");
	} else if (score >= 60 && score <= 69) {
		printf("D\n");	
	} else {
		printf("E\n");
	}

	return 0;
}

