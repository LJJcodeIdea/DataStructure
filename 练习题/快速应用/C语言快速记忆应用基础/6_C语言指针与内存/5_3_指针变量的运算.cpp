#include <stdio.h>
/*
	指针变量的运算：
		、
		指针变量不能相加，不能相乘，也不能相除

		如果两个指针变量指向的是同一块连续空间中的不同存储单元，

		则这两个指针变量才可以相减
		
*/
int main(void)
{
	int a[3];

	int * p;
	int * q;

	p = &a[0];
	q = &a[2];

	printf("p和q所指向的单元相隔%d个单元\n",(q-p));


	return 0;
}