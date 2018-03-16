#include <stdio.h>

/*
	如果p是个指针变量，则
		
		  p[i] 永远等价于 *(p+i)
*/

int main(void)
{
	int a[5];

	int b[5] = {1,3};

	printf("%#x\n",&a);		//a 是 int * 类型

	printf("%#x\n",&a[0]);		//一维数组的数组名是一个指针变量，它存放的是一维数组第一个元素的地址

	printf("b[1] = %d，*(b+1) = %d\n",b[1],*(b+1));

	return 0;
}