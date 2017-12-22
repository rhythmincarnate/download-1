#include <stdio.h>

int main(void)
{
	int x = 1, y = 0, a = 0, b = 0;

	switch (x) {
		case 1:
			switch (y) {
				case 0:a++;b++;break;
				case 1:a--; b--;break;
			}
		case 2:
			a++; b++;break;
		case 3:
			a++; b++;break;
		default:
			break;
	}

	printf("a:%d, b:%d\n", a, b);

	return 0;
}

