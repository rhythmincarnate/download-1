#include <stdio.h>

#define NAMESIZE	32
/*
 抽象学生类型
 struct stu_st　学生类型
 */
struct stu_st {
	char name[NAMESIZE];
	int height;
	float score;
};

int main(void)
{
	//学生类型的变量 初始化
	struct stu_st stu1 = {"malongxiang", 175, 99.9};

	//赋值
	stu1.height = 176;

	//遍历
	printf("%s %d %.2f\n", stu1.name, stu1.height, stu1.score);

	return 0;
}

