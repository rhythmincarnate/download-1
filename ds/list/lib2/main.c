#include <stdio.h>
#include <string.h>

#include <list.h>

#define NAMESIZE	32

struct stu_st {
	int id;
	char name[NAMESIZE];
};

static void print_stu(const void *data);
static int name_cmp(const void *data, const void *key);
static int id_cmp(const void *data, const void *key);
int main(void)
{
	listhead_t *l;	
	struct stu_st stu;
	int id[] = {5,7,9,8,1,3,4,2,6};
	char *name[] = {"sunpeng", "sunweiyuan", "malongxiang", "wangsicheng", \
		"hekaifang", "houyuxuan", "renhao", "sunyuzhu", "zhangbin"};
	char *n = "houyuxuan";
	struct stu_st *find;
	int delid = 5;

	l = listhead_init(sizeof(struct stu_st));
	if (NULL == l) {
		return 1;
	}

	for (int i = 0; i < sizeof(id) / sizeof(*id); i++) {
		stu.id = id[i];
		strcpy(stu.name, name[i]);
		list_insert(l, &stu, TAIL);	
	}

	list_traval(l, print_stu);

	//search	
	find = list_search(l, n, name_cmp);
	if (NULL != find) {
		printf("find it:%d %s\n", find->id, find->name);
		printf("**********update************\n");
		stu.id = 10;
		strcpy(stu.name, "zhouxinlei");
		list_update(l, n, name_cmp, &stu);
		list_traval(l, print_stu);
	}

	printf("************delete*************\n");
	list_delete(l, &delid, id_cmp);	
	list_traval(l, print_stu);

	list_destroy(l);

	return 0;
}

static void print_stu(const void *data)
{
	const struct stu_st *d = data;

	printf("%d %s\n", d->id, d->name);
}

static int name_cmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const char *k = key;

	return strcmp(d->name, k);
}

static int id_cmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const int *k = key;

	return d->id - *k;
}


