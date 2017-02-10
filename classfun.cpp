#include "classfun.h"
#include "fun.h"

point::point(int x, int y):xp(x),yp(y){};

int point::callStaticLibAddFun(int x, int y)
{
	int sum = 0;
	sum = add(x, y);
	printf("point::callStaticLibAddFun: sum = %d\n", sum);
	return sum;
}

void point::callStaticLibStrPrintFun(char *s)
{
	printf("point::callStaticLibStrPrintFun: str = %s\n", s);
}

void point::setpoint(int x, int y)
{
	printf("point::setporint: x = %d, y = %d\n", x, y);
	xp = x;
	yp = y;
}

int point::getxpoint()
{
	printf("point::getxpoint: xp = %d\n", xp);
	return xp;
}

int point::getypoint()
{
	printf("point::getypoint: yp = %d\n", yp);
	return yp;
}




