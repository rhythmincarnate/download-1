#if 0

定义一个学生类型，类型中有以下成员变量
	1.姓名
	2.年龄
	3.身高
再定义一个小学生类型,类型中有以下成员变量
	1.学生类型的变量
	2.语文成绩
	3.数学成绩

定义一个小学生数组,数组中有3个成员
从终端读入每一个小学生的信息，存储到数组中并输出

#endif

#include <stdio.h>

#define NAMEISZE 32

typedef struct stu_st {
	char name[NAMEISZE];
	int age;
	int height;
}stu_t;

typedef struct {
	stu_t stu;	
	int chinese;
	int math;
}child_t;

int main(void)
{
	child_t arr[3] = {};

	printf("请输入名字 年龄 身高 语文成绩　数学成绩\n");			
#if 1
	for (int i = 0; i < 3; i++) {
		scanf("%s %d %d %d %d", arr[i].stu.name, &arr[i].stu.age, \
				&arr[i].stu.height, &arr[i].chinese, &arr[i].math);
	}

	for (int i = 0; i < 3; i++) {
		printf("%s %d %d %d %d\n", arr[i].stu.name, arr[i].stu.age, \
				arr[i].stu.height, arr[i].chinese, arr[i].math);
	}
#endif
#if 0
	int j;
	for (int i = 0; i < 3; i++) {
		printf("input the name: ");
		j = 0;
		while (1) {
			scanf("%c", arr[i].stu.name+j);	
			if ((arr[i].stu.name)[j] == '\n') {
				(arr[i].stu.name)[j] = 0;
				break;
			}
			j++;
		}
		printf("input the age: ");
		scanf("%d", &arr[i].stu.age);
		
		printf("name:%s, age:%d\n", arr[i].stu.name, arr[i].stu.age);
		/*
			将标准输入文件所有的内容清空 ('\n') 
		 */
		while (getchar() != '\n')
			;

	}
#endif

	return 0;
}

