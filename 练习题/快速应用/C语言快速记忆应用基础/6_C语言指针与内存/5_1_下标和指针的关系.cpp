#include <stdio.h>

/*
	���p�Ǹ�ָ���������
		
		  p[i] ��Զ�ȼ��� *(p+i)
*/

int main(void)
{
	int a[5];

	int b[5] = {1,3};

	printf("%#x\n",&a);		//a �� int * ����

	printf("%#x\n",&a[0]);		//һά�������������һ��ָ�����������ŵ���һά�����һ��Ԫ�صĵ�ַ

	printf("b[1] = %d��*(b+1) = %d\n",b[1],*(b+1));

	return 0;
}