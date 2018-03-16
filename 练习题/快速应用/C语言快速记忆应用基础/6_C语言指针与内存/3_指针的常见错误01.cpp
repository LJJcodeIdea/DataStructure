#include <stdio.h>
int main(void)
{
	int * p;
	int i = 5; 

	/*
		应该先 给 p，存入一个整型变量的地址。
		然或才能对 *p 进行操作。
	*/
	*p = 9;


	return 0;
}