#include <stdio.h>

struct mode_st {
	char r;
	int w;
	short x;
};

//结构体中包含另一个机构体　不按复合类型对齐，按最大的基本类型对齐
struct file_st {
	char *path;
	struct mode_st mode;
	char *link;
};

int main(void)
{
	struct file_st f;

	printf("%ld\n", sizeof(struct mode_st));
	printf("%p %p %p\n", &f.path, &f.mode, &f.link);
	//printf("%p %p\n", &f.path, &f.mode);
	printf("%ld\n", sizeof(f));

	return 0;
}
