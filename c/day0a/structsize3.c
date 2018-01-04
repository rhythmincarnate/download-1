#include <stdio.h>

//单字节对齐pack(2的n次方)
#pragma pack(1)

/*
 结构体
	只在同一台主机使用，正常对齐 
	跨主机，单字节对齐(网络编程)
 */

struct computer_st {
	char *logo;	
	short price;
	char ch;
}__attribute__((packed)); /*编译选项__attribute__((packed))使得当前结构体单字节对齐*/

struct house_st {
	float price;
	char *position;
	char ch;
};

int main(void)
{
	struct computer_st cpt;
	struct house_st h;

	printf("%ld\n", sizeof(cpt));
	printf("%ld\n", sizeof(h));

	return 0;
}

