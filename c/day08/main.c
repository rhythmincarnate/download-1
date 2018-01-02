#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//int p[] == int *p
/*
 	"ls -l"
	"ls" "-l"
	char *arr[2] = {"ls", "-l"};
	//arr--->char **
 */
int main(int argc, char *argv[]/* char **argv */)
{
	char *p = "hello world";
	char *str[5] = {"红烧肉", "茄子豆角", "西红柿炒鸡蛋", "水煮肉", "酸菜炖粉条"};
	int num;

	srand(getpid());

	num = rand() % 5;
	printf("%s\n", str[num]);

	printf("%ld\n", sizeof(str));
	printf("%s\n", *(str+2));

#if 0
	printf("%d\n", argc);

	/*
	 	argc 命令行参数个数
		argv 存储命令行所有参数字符串首地址的数组的首地址
	 */
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
#endif

	return 0;
}

