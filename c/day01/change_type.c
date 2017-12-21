#include <stdio.h>

//char-->short--->int-->long-->float--->double
//signed--->unsigned

int main(void)
{
	unsigned int var = 0x12345678;	
	unsigned char ch;
	unsigned short sh;
	int num = -20;
	unsigned int un = 6;

	//隐式强转
	ch = var;//(unsigned char)var
	printf("ch:%#x\n", ch);

	sh = var;
	printf("sh:%#x\n", sh);

	ch = 0x12;
	var = ch;
	printf("var:%#x\n", var);

	//signed和unsigned进行运算 signed强转成unsigned
	num > un ? printf("wh\"a\\t?\n") : printf("i think so\n");
	/*
	 int 	%d
	 unsigned int %u
	 long	%ld
	 char	%c
	 0x		%#x
	 */

	return 0;
}

