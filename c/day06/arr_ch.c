#include <stdio.h>
#include <string.h>

/*
 字符串
	"" "hello"---->常量
	字符串中所有的字符地址连续，并一定是'\0'结束
 字符数组--->可以存放字符串
 	char arr[100] = {};
	初始化
	赋值
		strcpy(3);
	遍历
 
字符串常用函数
man string
	strlen(3);	
	strcpy(3);
	strncpy(3);
	strcat(3);
	strncat(3);
	strcmp(3);
	strncmp(3);
	strchr(3);
	strstr(3);

 */

int main(void)
{
	//初始化
	char str1[] = "hello world";//12元素
	char str2[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};//11元素
	char str3[] = {"hello world"};
	char str4[10] = {};
	char str5[20] = "hello";
	
	str1[0] = 'H';

	//赋值
	//strcpy(str4, "hello\0world");
	for (int i = 0; i < strlen(str5) && i < 9; i++) {
		str4[i] = str5[i];
	}

	//strlen()计算的是字符串的字节个数 sizeof()参数为数组名，计算的是数组所占的字节个数
	printf("strlen(str5):%ld, sizeof(str5):%ld\n", strlen(str5), sizeof(str5));


	//遍历 字符数组存放的是字符串
	printf("%s\n", str4);
	//字符串作为函数的参数，表示字符串的首地址 
	strncpy(str4, "hello world", 9);
	printf("%s\n", str4);

	//字符串的拼接
	strcpy(str4, "h");
	printf("str4:%s\n", str4);
	//保证目的地址对应的存储空间至少strlen(dest)+n+1
	//str4--->"h\0hel\0lo"
	strncat(str4, str1, 8);
	printf("str4:%s\n", str4);

	//字符串的比较
	strcpy(str1, "hello");
	strcpy(str2, "hell");
	printf("%d\n", strcmp(str1, str2));

	return 0;
}

