#ifndef __LIST_H
#define __LIST_H

//单循环链表

typedef enum {
	FRONT,
	TAIL
}insertway_t;

//抽象数据类型
struct node_st {
	void *data;
	struct node_st *next;
};

typedef struct {
	struct node_st head;
	int size;
}listhead_t;

typedef int (*cmp_t)(const void *data, const void *key); 
typedef void (*print_t)(const void *data);

//接口函数
listhead_t *listhead_init(int size);

int list_insert(listhead_t *h, const void *data, insertway_t way);

int list_delete(listhead_t *h, const void *key, cmp_t cmp);

void *list_search(const listhead_t *h, const void *key, cmp_t cmp);

int list_update(const listhead_t *h, const void *key, cmp_t cmp, const void *newdata);

void list_traval(const listhead_t *h, print_t pri);

void list_destroy(listhead_t *h);

#endif

