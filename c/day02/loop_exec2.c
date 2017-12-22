#include <stdio.h>

int main(void)
{
#if 0
	//5
	/*
		1  4  10  22     
	 */
	int sum = 1;
	int day;

	for (day = 9; day > 0; day --) {
		sum = (sum + 1)*2;	
	}
	printf("sum:%d\n", sum);
#endif
#if 0
	int year, month, day;
	int sumdays = 0;

	printf("请输入一个日期: ");
	scanf("%d/%d/%d", &year, &month, &day);

	switch (month-1) {
		case 11:
			sumdays += 30;
		case 10:
			sumdays += 31;
		case 9:
			sumdays += 30;
		case 8:
			sumdays += 31;
		case 7:
			sumdays += 31;
		case 6:
			sumdays += 30;
		case 5:
			sumdays += 31;
		case 4:
			sumdays += 30;
		case 3:
			sumdays += 31;
		case 2:
			sumdays = sumdays +  (((year % 4 == 0 && year % 100 != 0) || \
					   (year % 400 == 0)) ? 29 : 28);
		case 1:
			sumdays += 31;
			break;
		default:
			break;
	}

	sumdays += day;

	printf("%d\n", sumdays);
#endif

#if 0
	char ch;	
	int cnt1, cnt2, cnt3;

	cnt3 = cnt2 = cnt1 = 0;
	while (1) {
		scanf("%c", &ch);	
		if (ch == '\n')	
			break;
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			cnt1 ++;
		else if (ch >= '0' && ch <= '9') 
			cnt2 ++;
		else 
			cnt3 ++;
	}

	printf("%d %d %d\n", cnt1, cnt2, cnt3);
#endif
	char ch1, ch2;

	scanf("%c %c", &ch1, &ch2);
	printf("ch1:%c, ch2:%c\n", ch1, ch2);

	return 0;
}

