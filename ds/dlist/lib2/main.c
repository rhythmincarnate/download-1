#include <stdio.h>
#include <unistd.h>

#include <dlist.h>

static void pri_char(const void *data)
{
	const char *d = data;
	printf("%c ", *d);	
}

static int ch_cmp(const void *data, const void *key)
{
	const char *d = data;
	const char *k = key;

	return *d - *k;
}

int main(void)
{
	char str[] = "good morning";
	dlisthead_t *l = NULL;
	char ch;

	dlisthead_init(sizeof(char), &l);

	for (int i = 0; str[i]; i++) {
		dlist_insert(l, str+i, INSERT_TAIL);	
	}

	dlist_traval(l, pri_char);
	printf("\n");

	printf("*******delete********\n");
	ch = 'o';
	while (dlist_delete(l, &ch, ch_cmp) == 0) {
		printf("删除成功\n");
		dlist_traval(l, pri_char);
		printf("\n");
		sleep(1);
	}

	dlist_destroy(l);

	return 0;
}

