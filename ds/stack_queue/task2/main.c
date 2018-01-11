#include <stdio.h>

#include <stack.h>
#include <squeue.h>

static int bingo(squeue_t **q);
int main(void)
{
	stack_t *one_m, *five_m, *one_h;
	squeue_t *ball;
	int b, pb;
	int day = 0;
	int ret;
	
	one_m = init(sizeof(int), 4);
	if (NULL == one_m)
		return 1;
	//if error
	five_m = init(sizeof(int), 11);
	one_h = init(sizeof(int), 11);

	squeue_init(&ball, 28, sizeof(int));

	for (int i = 1; i < 28; i++) {
		squeue_enq(ball, &i);			
	}

	while (1) {
		squeue_deq(ball, &b);			
		if(!isfull(one_m)) {
			push(one_m, &b);
		}else {
			while (!isempty(one_m))	{
				pop(one_m, &pb);
				squeue_enq(ball, &pb);
			}
			//5分钟的是否满了	
			if (!isfull(five_m)) {
				push(five_m, &b);
			} else {
				while (!isempty(five_m)) {
					pop(five_m, &pb);
					squeue_enq(ball, &pb);
				}
				//1小时的栈是否满了
				if (!isfull(one_h)) {
					push(one_h, &b);
				} else {
					while (!isempty(one_h)) {
						pop(one_h, &pb);
						squeue_enq(ball, &pb);
					}
					//将最后一个球入队　一天
					squeue_enq(ball, &b);
					day ++;
					printf("%d\n", day);
					//判断球是否是1~27
					if ((ret = bingo(&ball)) == 1)
						break;
				}
			}
		}
	}
	
	printf("day:%d\n", day);
	while (!squeue_isempty(ball)) {
		squeue_deq(ball, &b);
		printf("%d ", b);
	}
	printf("\n");

	return 0;
}
	

static int bingo(squeue_t **q)
{
	squeue_t *tmp, *del;
	int num, ano_num;
	int flag = 1;

	squeue_init(&tmp, 28, sizeof(int));

	squeue_deq(*q, &num);
	printf("%d ", num);
	squeue_enq(tmp, &num);
	while (1) {
		if (!squeue_isempty(*q))	{
			squeue_deq(*q, &ano_num);
			printf("%d ", ano_num);
			squeue_enq(tmp, &ano_num);
		} else {
			break;	
		}
		if (num > ano_num) {
			while (!squeue_isempty(*q)) {
				squeue_deq(*q, &num);	
				printf("%d ", num);
				squeue_enq(tmp, &num);
			}
				
			flag = 0;
			break;
		}
		num = ano_num;
	}
	printf("\n");

	del = *q;
	*q = tmp;	

	squeue_destroy(del);

	return flag;	
}

