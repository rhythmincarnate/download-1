#include <stdio.h>
#include <stdlib.h>

static int myatoi(const char *p);
int main(void)
{
	printf("%d\n", myatoi("7934"));
	printf("%d\n", myatoi("-7934"));
	printf("%d\n", myatoi("-1234"));
	printf("%d\n", myatoi("-12abc34"));
	printf("%d\n", myatoi("a-12abc34"));

	return 0;
}

static int myatoi(const char *p)
{
	int num = 0;
	int f = 1;

	if (*p == '-') {
		f = -1;	
		p++;
	}

	//"123a"
	while (*p) {
		if (!(*p >= '0' && *p <= '9'))
			break;
		num = num * 10 + (*p - '0');
		p++;
	}

	return f*num;
}

