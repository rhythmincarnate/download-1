#include <stdio.h>
#include <stdlib.h>

static int op_int(int n1, int n2, char ch);
int main(int argc, char **argv)
{

	if (argc < 4)
		return 1;
	printf("%s %s %s = %d\n", argv[1], argv[2], argv[3], \
			op_int(atoi(argv[1]), atoi(argv[3]), *argv[2]));

	return 0;
}

/*
	四则运算 
 */
static int op_int(int n1, int n2, char ch)
{
	int res = 0;

	switch (ch) {
		case '+':
			res = n1 + n2;	
			break;
		case '-':
			res = n1 - n2;
			break;
		case 'x':
			res = n1 * n2;
			break;
		case '/':
			res = n1 / n2;
			break;
		default:
			break;
	}	

	return res;
}



