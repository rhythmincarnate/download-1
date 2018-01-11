#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <stack.h>

stack_t *init(int size, int container)
{
	stack_t *s = NULL;	

	s = malloc(sizeof(stack_t));
	if (NULL == s)
		return NULL;
	memset(s, '\0', sizeof(stack_t));
	s->size = size;
	s->container = container;	
	s->bottom = s->top = calloc(container, size);
	if (s->bottom == NULL) {
		free(s);
		return NULL;
	}

	return s;
}

int isempty(const stack_t *s)
{
	return s->top == s->bottom;
}

int isfull(const stack_t *s)
{
	int nmemb = 0;

	nmemb = ((char *)s->top - (char *)s->bottom) / s->size;
	return nmemb == s->container;
}

int push(stack_t *s, const void *data)
{
	if (isfull(s))
		return -1;

	memcpy(s->top, data, s->size);
	s->top = (char *)s->top + s->size;

	return 0;
}

int pop(stack_t *s, void *data)
{
	if (isempty(s))
		return -1;

	s->top = (char *)s->top - s->size;
	memcpy(data, s->top, s->size);

	return 0;
}

void destory(stack_t *s)
{
	free(s->bottom);
	free(s);
}

