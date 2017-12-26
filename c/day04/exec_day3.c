#include <stdio.h>

/*
 回文整型数
 num:待判断的整型数
 return value:
 	0	no
	1	yes
 */

static int is_symmetry(int num)
{
	//12345	
	int tmp = 0, save;

	if (num < 0)
		num = -num;

	save = num;
	
	while (num) {
		tmp = tmp*10 + num % 10;	
		num /= 10;
	}

	return tmp == save;
}
static int powerofnum(int m, int n);
static int is_primer(int number);
static int febonacci(int n);
int sumofnum(void);

int main(void)
{
#if 0
	int num;
	
	scanf("%d", &num);
	if (is_symmetry(num)) {
		printf("%d是一个回文整型数\n", num);
	} else { 
		printf("%d不是一个回文整型数\n", num);
	}
	if (is_primer(num)) {
		printf("%d是一个素数\n", num);
	} else {
		printf("%d不是一个素数\n", num);
	}

#endif
#if 0
	int num1, num2;

	scanf("%d%d", &num1, &num2);
	printf("%d的%d次方为%d\n", num1, num2, powerofnum(num1, num2));
#endif

	for (int i = 1; i <= 20; i++) {
		printf("%d ", febonacci(i));	
	}
	printf("\n");

	printf("%d\n", sumofnum());

	return 0;
}

/*
	powerofnum:求得m的n次方
	return value:
   		m的n次方的结果	
 */
static int powerofnum(int m, int n)
{
	int res = 1;

	for (int i = 0; i < n; i++) {
		res = m*res;	
	}

	return res;
}

/*
is_primer:判断给定的整型数是否为素数
number:待判断的整型数 
return value:
	0	no
	1	yes
 */
static int is_primer(int number)
{
	int flag = 1;

	for (int i = 2; i <= number/2; i++) {
		if (!(number % i)) {
			flag = 0;
			break;
		}
	}

	return flag;
}

/*
febonacci:求得斐波那契数列的第n项
n:待求得的第n项
return value:
	结果值	
 */

static int febonacci(int n)
{
	int pre1, pre2;
	int res;

	if (n == 1 || n == 2)
		return 1;
	else if (n < 1)
		return -1;

	pre1 = pre2 = 1;
	for (int i = 3; i <= n; i++) {
		res = pre1 + pre2;	
		pre2 = pre1;	
		pre1 = res;
	}

	return res;
}

/*
	计算有多少种有1,2,3,4组成的不重复的三位数 
 */
int sumofnum(void)
{
	int sum = 0;

	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			for (int k = 1; k < 5; k++) {
				if (i != j && i != k && j != k)		
					sum ++;
			}	
		}	
	}

	return sum;
}


