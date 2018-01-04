#include <stdio.h>

//枚举类型枚举的是常量值
enum op_en {
	ADD,
	DELETE,
	UPDATE = 5,
	SEARCH, 
};

int main(void)
{
	enum op_en choose;//本质整型

	printf("%ld\n", sizeof(choose));

	scanf("%d", &choose);
	switch(choose) {
		case ADD:
			printf("add choose:%d\n", choose);
			break;
		case DELETE:
			printf("delete choose:%d\n", choose);
			break;
		case UPDATE:
			printf("update choose:%d\n", choose);
			break;
		case SEARCH:
			printf("search choose:%d\n", choose);
			break;
		default:
			break;
	}


	return 0;
}

