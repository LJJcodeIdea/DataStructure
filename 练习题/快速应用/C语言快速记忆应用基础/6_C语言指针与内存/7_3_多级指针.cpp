#include <stdio.h>

int main(void)
{
	int i = 10;
	int * p = &i;  // int * ,存放 int 型的地址，
	int ** q = &p;	//int * *,存放 int * 型的地址，
	int *** r = &q;  // ***r == i, **r == p,*r == q

	printf("***r = %d\n",***r);



	return 0 ;
}