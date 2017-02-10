#ifndef __CLASSFUN_H__
#define __CLASSFUN_H__

#include <stdio.h>

class point
{
public:
	point(int x, int y);	
	void setpoint(int x, int y);
	int getxpoint();
	int getypoint();
	int callStaticLibAddFun(int x, int y);
	void callStaticLibStrPrintFun(char *s);
private:
	int xp;
	int yp;
};


#endif
