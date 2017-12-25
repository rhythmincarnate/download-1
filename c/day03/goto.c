#include <stdio.h>

int main(void)
{
	int num1, num2;	
	int res = 0;
	int i;

	scanf("%d %d", &num1, &num2);

	/*num1的前n项和*/
	i = 1;
LOOP:
	res += i;
	if (i < num1) {
		i++;
		goto LOOP;//不推荐
	}

	printf("res:%d\n", res);

	if (num1 > num2) {
		num1 = num1 + num2;
		num2 = num1 - num2;
		num1 = num1 - num2;
	}

	res = 0;
	for (int i = num1; i <= num2; i++) {
		if (i < 0)	
			continue;
		res += i;
		if (res > 100)
			//break;
			goto END;
			/*
			 1.当循环嵌套的时候，在里层的循环想跳出最外层的循环,goto
			 break不可以，break只能终止最近的循环
			 2.goto多用于错误处理
			 不建议用goto循环
			 */
	}

	return 0;
END:
	printf("res:%d\n", res);
}

