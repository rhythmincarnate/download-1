#include <stdio.h>

//位域/位段 unsigned char / unsigned int
struct mode_st {
	unsigned char r:1;//占用一个字节的1位
	unsigned char w:6;
	unsigned char x:3;
};

struct test_st {
	unsigned int f:3;
	unsigned int s:2;
	unsigned int t:8;
	unsigned int l:8;
};

typedef union {
	unsigned int num;
	struct test_st t;
}n_t;

int main(void)
{
	struct mode_st m;
	n_t score;

	m.r = 1;
	m.w = 100;//1100100
	m.x = 3;
	
	printf("%d %d %d\n", m.r, m.w, m.x);

	printf("%ld\n", sizeof(m));

	score.num = 511;//0000 0000 0000 0000 0000 0001 1111 1111

	printf("%d %d %d %d\n", score.t.f, score.t.s, score.t.t, score.t.l);

	return 0;
}

