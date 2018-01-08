#include <stdio.h>

#include <list.h>

static void print1(const void *data)
{
	const int *d = data;
	printf("%d ", *d);
}

static int cmp1(const void *data, const void *key)
{
	const int *d = data;
	const int *k = key;

	return *d - *k;
}

int main(int argc, char **argv)
{
	seqlist_t *l = NULL;
	int id[] = {1,2,3,4,5,6,7,};

	seqlist_init(sizeof(int), &l);

	for (int i = 0; i < sizeof(id) / sizeof(*id); i++) {
		seqlist_insert(l, id+i);	
	}

	seqlist_traval(l, print1);
	printf("\n");

	//测试删除
	int delid = 7;
	if (seqlist_delete(l, &delid, cmp1) < 0) {
		printf("没有你要删除的元素\n");
	}
	seqlist_traval(l, print1);
	printf("\n");

	seqlist_destroy(l);

	return 0;
}

