#include <stdio.h>

int main(void)
{
	int i = 10;
	int * p = &i;  // int * ,��� int �͵ĵ�ַ��
	int ** q = &p;	//int * *,��� int * �͵ĵ�ַ��
	int *** r = &q;  // ***r == i, **r == p,*r == q

	printf("***r = %d\n",***r);



	return 0 ;
}