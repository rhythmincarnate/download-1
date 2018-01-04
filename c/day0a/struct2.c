#include <stdio.h>
#include <string.h>

#define NAMESIZE	32
/*
 抽象学生类型
 struct stu_st　学生类型
 */
struct stu_st {
	char name[NAMESIZE];
	int height;
	float score;
	char *tel;
}g_stu2, g_stu3;

struct stu_st g_stu1;
//g_stu1, g_stu2, g_stu3全局变量

/*
 动物
 结构体中不能有函数的定义,但是可以包含函数指针
 */
typedef struct animal_st {
	int age;
	char name[NAMESIZE];
	void (*run)(void);
}animal_t;

//typedef struct animal_st animal_t;

static void test(void);
int main(void)
{
	animal_t dog;
	
	dog.age = 1;
	strcpy(dog.name, "dahuang");
	dog.run = test;
	printf("%s %d\n", dog.name, dog.age);
	(dog.run)();

	strcpy(g_stu2.name, "sunlei");
	g_stu2.tel =  "12321312";
	g_stu2.height = 180;
	g_stu2.score = 89;

	printf("%s %s %d %f\n", g_stu2.name, g_stu2.tel, g_stu2.height, g_stu2.score);

	return 0;
}

static void test(void)
{
	printf("the dog is running\n");
}

