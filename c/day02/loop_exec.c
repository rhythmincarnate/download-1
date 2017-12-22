#if 0
循环练习
	1.读入一个整型数，求得其前n项和
		例如n = 5, 计算1+2+3...+5

	2.读入两个整型数,求得两个数之间的所有数的和
		例如num1= 100 num2 = 105 计算100+101+102+103+104+105

	3.让顾客输入会员卡号的后四位，如果会员卡号后四位的和超过20,则奖励50元购物券

	4.任意输入一个三位数，判断其是否为水仙花数(数的每一位的立方和是本身)
	例如153=1+125+27

	5.猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个，第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。

	6.读入一个日期(年/月/日),计算出这一天是这一年中的第几天

	7.从标准输入读入一行字符(到'\n'为止)，统计其字母的个数('a'~'z' 'A'~'Z'),
	数字字符的个数('0'~'9'),剩下的都为其他，其他字符的个数

	8.从标准输入读入一个整型数,判断其是否是质数.
#endif

#include <stdio.h>

int main(void)
{
#if 0
	//1
	int number, sum = 0;

	printf("input a number\n");
	scanf("%d", &number);

	for (int i = 1; i <= number; i++) {
		sum = i + sum;//sum += i;	
	}
	printf("%d的前ｎ项和为%d\n", number, sum);
#endif

#if 0
	int num1, num2;
	int sum = 0;

	printf("input two numbers:\n");			
	scanf("%d%d", &num1, &num2);

	//确保num1存储的是两个数中较小的
	if (num1 > num2) {
		num1 = num1 ^ num2;
		num2 = num1 ^ num2;
		num1 = num1 ^ num2;
	}

	for (; num1 <= num2; num1 ++) {
		sum += num1;
	}

	printf("%d\n", sum);
#endif

#if 0
	int card, save;
	int n = 0;

	do {
		//确保card一定是一个四位数
		printf("请输入您的会员卡号的后四位: ");
		scanf("%d", &card);
		save = card;
		n = 0;
		while (card > 0) {
			n ++;
			card /= 10;
		}
	} while (n != 4);

	//save每一位的和是否大于50	
	/*
	 	%10--->得到最低位
		/10--->舍掉最低位
	 */		

	n = 0;	
	while (save > 0) {
		n += save % 10;			
		save /= 10;
	}
	if (n > 20) {
		printf("恭喜您！获得５０元代金券\n");
	}
#endif

	int number, s;
	int n = 0;
	int res = 0;

	do {
		printf("请输入一个三位数: ");
		scanf("%d", &number);
		s = number;
		n = 0;
		while (s > 0) {
			n ++;
			s /= 10;
		}
	} while (n != 3);

	s = number;
	for (; number > 0; number /= 10) {
		n = number % 10;	
		res += n * n * n;
	}
	
	if (res == s) {
		printf("%d 是一个水仙花数\n", s);
	} else {
		printf("%d 不是一个水仙花数\n", s);
	}

	return 0;
}


