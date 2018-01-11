#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stack.h>

static char *mid2pre(const char *ptr);
int main(int argc, char **argv)
{
	char *r;
	if (argc < 2)
		return 1;
	r = mid2pre(argv[1]);
	if (r != NULL)
		printf("%s\n", r);

	free(r);

	return 0;
}


static int isRight(char ch);
static int isNumber(char ch);
static int isLeft(char ch);
static int isOperator(char ch);
static int getvalue(char op);

/*
	mid2pre:将中缀表达式转换为前缀表达式 
	@ptr:中缀表达式的首地址
	return value:前缀表达式的首地址 
 */
static char *mid2pre(const char *ptr)
{
	stack_t *ops, *res;
	int i;
	char ch;
	char *pre = NULL;
	//初始化两个栈
	res = init(sizeof(char), strlen(ptr));
	if (res == NULL)
		return NULL;
	ops = init(sizeof(char), strlen(ptr));
	if (NULL == ops) {
		goto ERROR1;	
	}

	//遍历中缀表达式
	i = strlen(ptr)-1;
	while (i >= 0) {
		if (isNumber(ptr[i]))	{
			push(res, ptr+i);
		} else if (isOperator(ptr[i])) {
			while (!isempty(ops)) {
				pop(ops, &ch);
				if (getvalue(ptr[i]) < getvalue(ch)) {
					push(res, &ch);	
				} else {
					push(ops, &ch);	
					break;
				}
			}
			push(ops, ptr+i);
		} else if (isLeft(ptr[i])) {
			while (!isempty(ops)) {
				pop(ops, &ch);	
				if (isRight(ch))
					break;
				push(res, &ch);	
			}
		} else if (isRight(ptr[i])) {
			push(ops, ptr+i);	
		} else {
			goto ERROR2;	
		}
		i--;
	}

	while (!isempty(ops)) {
		pop(ops, &ch);
		push(res, &ch);
	}

	//为前缀表达式开辟存储空间
	pre = malloc(strlen(ptr));
	memset(pre, '\0', strlen(ptr));
	//将结果栈依次出栈直到为空--->存放到前缀表达式所开辟的存储空间中
	i = 0;
	while (!isempty(res)) {
		pop(res, pre+i);	
		i++;
	}
	//i前缀表达式不包含'\0'的字节个数
	if (i+1 < strlen(ptr)) {
		pre = realloc(pre, i+1);
		if (NULL == pre)
			goto ERROR2;
	}

	destory(ops);
	destory(res);

	return pre;	

ERROR2:
	destory(ops);
ERROR1:
	destory(res);
	return NULL;
}

static int isNumber(char ch)
{
	return ch >= '0' && ch <= '9';
}

static int isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static int isLeft(char ch)
{
	return ch == '(';
}

static int isRight(char ch)
{
	return ch == ')';
}

/*
 　'+' '-'  1
 	'*' '/' 2
 */
static int getvalue(char op)
{
	int res = 0;
	
	switch (op) {
		case '+':
		case '-':
			res = 1;
			break;
		case '*':
		case '/':
			res = 2;
			break;
		default:
			break;
	}

	return res;
}





