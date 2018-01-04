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
	//struct stu_st s;结构体类型不完整
	struct stu_st *s;//允许
};

int main(void)
{
	//学生类型的变量 初始化
	struct stu_st stu2 = {"sunming", 189, 100, NULL};
	struct stu_st stu1 = {"malongxiang", 175, 99.9, &stu2};

	//赋值
	stu1.height = 176;

	//遍历
	printf("%s %d %.2f %s %d %f\n", stu1.name, stu1.height, stu1.score, \
			(stu1.s)->name, (stu1.s)->height, (stu1.s)->score);

	return 0;
}

