#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define NAMESIZE 32

struct stu_st {
	int id;
	char name[NAMESIZE];
	struct list_head node;
	int score;
};

int main(void)
{
	struct stu_st *stu = NULL;
	int id[] = {1,2,3,4,5,6,7,8};
	char *name[] = {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "ll"};
	int score[] = {11,22,33,44,55,66,77,88};
	struct list_head *pos = NULL;
	struct stu_st *cur = NULL;

	LIST_HEAD(h);

	for (int i = 0; i < sizeof(id) / sizeof(*id); i++) {
		stu = calloc(1, sizeof(*stu));	
		if (NULL == stu)
			return 1;
		stu->id = id[i];	
		stu->score = score[i];
		strcpy(stu->name, name[i]);
		list_add(&stu->node, &h);
	}

	list_for_each(pos, &h) {
		stu = list_entry(pos, struct stu_st, node);
		printf("%d %s %d\n", stu->id, stu->name, stu->score);	
	}
	

	printf("**************delete******************\n");
	char *delname = "dd";
	list_for_each(pos, &h) {
		stu = list_entry(pos, struct stu_st, node);
		if(!strcmp(stu->name, delname))
		{
			list_del(&(stu->node));
			free(stu);	
			printf("删除成功\n");
			break;
		}
	}

	list_for_each(pos, &h) {
		stu = list_entry(pos, struct stu_st, node);
		printf("%d %s %d\n", stu->id, stu->name, stu->score);	
	}

	int flag = 0;

	list_for_each(pos, &h) {
		if (!flag) {
			pos = pos->next;	
			flag = 1;
		}
		cur = list_entry(pos->prev, struct stu_st, node);
		printf("debug:%d %s\n", cur->id, cur->name);
		free(cur);	
	}
	//最后一个结点
	cur = list_entry(pos->prev, struct stu_st, node);
	printf("debug:%d %s\n", cur->id, cur->name);
	free(cur);	

	return 0;
}

