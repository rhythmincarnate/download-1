#include <stdio.h>

#define NAMESIZE	32

/*
	衣服
	定义衣服类型的变量 只能cloth_t xx
	struct a;错误的
 */
typedef struct {
	int color;
	float price;
	char *logo;
}cloth_t;

/*
 抽象学生类型
 struct stu_st　学生类型
 */
struct stu_st {
	char name[NAMESIZE];
	int height;
	float score;
	cloth_t cloth;
};

int main(void)
{
	//学生类型的变量 初始化
	struct stu_st stu1 = {"malongxiang", 175, 99.9, {'r', 100, "hailanzhijia"}};
	//学生类型的指针
	struct stu_st *p;

	p = &stu1;

	//赋值
	stu1.height = 176;
	stu1.cloth.logo = "jack";
	p->cloth.price = 1000.0;

	//遍历
	printf("%s %d %.2f %c %f %s\n", p->name, p->height, p->score, p->cloth.color,\
			p->cloth.price, p->cloth.logo);

	return 0;
}

