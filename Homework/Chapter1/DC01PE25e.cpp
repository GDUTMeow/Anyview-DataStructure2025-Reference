#include "allinclude.h"  //DO NOT edit this line
void A() {
	printf("X\n");
}
void B() {
	printf("Y\n");
}


int main()
{
	void (*funcp)(); //定义函数指针

	funcp = A;
	(*funcp)(); // 实际上调用了A( );

	funcp = B;
	(*funcp)(); // 实际上调用了B( );

	return 0;
}