#include <stdio.h>
/*
switch (变量/变量表达式) {
	case 常量值:
	case 常量值:
		break;
	default:	
		break;
} 
 
 */
int main(void)
{
	int score;
	int ch;

#if 0
	for (;;) {
		printf("请输入你的成绩\n");
		scanf("%d", &score);
		if (score >= 0 && score <= 100)
			break;
	}
#endif

	do {
		printf("请输入你的成绩\n");
		scanf("%d", &score);
	} while (!(score >= 0 && score <= 100));

	ch = score / 10;
	switch (ch) {
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;	
	}

	return 0;
}

