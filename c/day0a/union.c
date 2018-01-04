#include <stdio.h>

/*
   字节序
	大端:
		高字节存低地址，低字节存高地址
   	小端:	
		高字节存高地址，低字节存低地址
 
 */

union num_un{
	char ch;
	int num;
};

int main(void)
{
	union num_un u;

	u.num = 0x12345678;

	printf("%#x\n", u.ch);

	u.ch = 0x88;
	printf("%#x\n", u.num);

	printf("%p %p\n", &u.ch, &u.num);
	printf("%ld\n", sizeof(u));


	return 0;
}

