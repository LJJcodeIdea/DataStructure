#include <stdio.h>
#include <malloc.h>

void f(int * q)
{

	*q = 200;

	//free(q);  //把q所指向的内存释放掉
}

int main(void)
{
	int * p = (int *)malloc(sizeof(int));

	*p = 10;

	printf("%d\n",*p);
	f(p);
	printf("%d\n",*p);

	return 0;
}