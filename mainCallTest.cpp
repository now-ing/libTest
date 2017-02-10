#include <stdio.h>
#include "classfun.h"
#include "fun.h"

int main()
{
	int param1 = 10;
	int param2 = 6;
	char mystr[] = "hello, static lib";
	point pObj(3, 8);
	printf(">>>main_1\n");
	pObj.callStaticLibAddFun(param1, param2);	
	printf(">>>main_2\n");
	pObj.getxpoint();
	printf(">>>main_3\n");
	add(param1, param2);
	printf(">>>main_4\n");
	strprint(mystr);
	printf(">>>main_5\n");

	return 0;
}



