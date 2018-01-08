#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//变长结构体
struct stu_st {
	int id;
	char name[0];//变长的存储空间首地址
};

struct node_st {
	int id;
	char *p;
	float f;
};

int main(void)
{
	struct stu_st *p = NULL;
	struct stu_st stu;

	p = malloc(sizeof(struct stu_st)+100);

	strcpy(p->name, "wangqiang");

	printf("%s\n", p->name);
	printf("sizeof(stu):%ld\n", sizeof(stu));

	//求得结构体成员变量的偏移量
	printf("%d\n", (int)(&((struct node_st *)0)->p));


	return 0;
}

