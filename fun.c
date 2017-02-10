#include "fun.h"

int add(int x, int y)
{
	int sum = x + y;
	printf("libcfun.a-add: x + y = %d\n", sum);
	return sum;
}

void strprint(char *s)
{
	printf("libcfun.a-strprint: the string is %s\n", s);
}


