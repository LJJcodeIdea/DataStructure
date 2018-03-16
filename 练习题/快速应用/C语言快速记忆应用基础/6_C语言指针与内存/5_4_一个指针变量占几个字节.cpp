#include <stdio.h>

/*
	sizeof(数据类型/变量名)
		功能： 返回值就是改数据类型所占的字节数

  一个变量的地址使用该变量首字节的地址来表示。
*/

int main(void)
{
	char ch ='A';

	int i = 88;

	double x = 33.5;

	char * p = &ch; //例： p 存放的是 ch 的1个字节中的第一个字节

	int * q = &i;	//例： p 存放的是 i 的四个字节中的第一个字节

	double * f = &x;

	printf("%d %d %d \n",sizeof(p),sizeof(q),sizeof(f));

	return 0;
}

/*
 为什么指针变量只存放放了一个字节，但它的字节长度都是4：
 指针不同于一般变量，存的是变量的地址，在同一架构下地址长度都是相同的（cpu的最大寻址内存空间），
 所以不同类型的指针长度都一样你输出的4 4 4，说明指针长度为4字节可以记录的地址范围是0x00000000~0xFFFFFFFF，
 这个范围才是指针变量的值比如说一个char 1字节，可以存在0x0，也可以位于0xFFFFFFFF而和char占用1字节还是100字节无关，
 指针的范围只和机器字和系统有关比如你的32位系统，指针长度为4，在64位操作系统下那么就都是8了。
*/