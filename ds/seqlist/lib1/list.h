#ifndef __LIST_H
#define __LIST_H
/*预处理指令　防止重复编译
.h文件在.c文件中是可以重复包含,当重复包含的时候，如果有了预处理指令后，\
	此.h文件只会展开一次，相当于包含一次
.h文件中主要内容:
	函数的声明
	类型的定义(只能定义一次)
	宏的定义
*/
//抽象数据类型---->顺序表(数组--->存储任意类型---->成员个数动态)
typedef struct {
	void *arr;//存储数组的首地址
	int nmemb;//数组中的成员个数
	int size;//数组每个成员的字节个数
}seqlist_t;

//比较函数　0	相等	
typedef int (*cmp_t)(const void *data, const void *key);
//打印函数
typedef void (*print_t)(const void *data);

/*
   基本功能
   		增　删	改	查
*/
//实例化表结构seqlist_t
//seqlist_t *seqlist_init(int size);
int seqlist_init(int size, seqlist_t **l);

/*
	insert	
l:表结构地址
data:待插入元素的地址
return value:
	0	成功
	-1	失败
*/
int seqlist_insert(seqlist_t *l, const void *data);

/*
	search 
l:表结构地址
key:查找关键字地址
cmp:比较函数地址
 */
void *seqlist_search(const seqlist_t *l, const void *key, cmp_t cmp);

/*
 	delete
l:表结构地址 
key:删除关键字地址
cmp:函数指针，存储比较函数地址
 */
int seqlist_delete(seqlist_t *l, const void *key, cmp_t cmp);

/*
 	traval
l:表结构地址
pri:打印函数的地址
 */
void seqlist_traval(const seqlist_t *l, print_t pri);

/*
 	destroy
 */
void seqlist_destroy(seqlist_t *l);

#endif

