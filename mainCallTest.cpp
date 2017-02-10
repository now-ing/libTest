#include <stdio.h>
#include "classfun.h"

int main()
{
	int param1 = 10;
	int param2 = 6;
	point pObj(3, 8);
	printf(">>>main_1\n");
	pObj.callStaticLibAddFun(param1, param2);	
	printf(">>>main_2\n");
	pObj.getxpoint();
	printf(">>>main_3\n");
	return 0;
}



