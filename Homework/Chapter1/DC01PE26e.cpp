#include "allinclude.h"  //DO NOT edit this line
void hello() 
{ 
	printf("Hello world!\n"); 
}

void runFun(void (*pFun)()) 
{
	pFun();  //函数指针;
}


int main()
{
	runFun(hello);  //hello是实际要调用的函数

	return 0;
}