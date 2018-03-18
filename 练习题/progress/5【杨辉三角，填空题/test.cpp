#include "stdio.h"

long long f(int row, int col){
	if(row<2) return 1;
	if(col==0) return 1;
	if(col==row) return 1;
	
	long long a[1024];
	a[0]=1;
	a[1]=1;	
	int p = 2;
	int q;
	

	/*
		�ڶ��У�
		1 2 1
		0 1 2 
			p
		������
		1 2 1 1   ->   1 2 3 1   -> 1 3 3 1
			  p
			q            q            q
		 
	*/
	//�ӵڶ��п�ʼ 
	while(p<=row){   //�����������������±꣬�ⲻ������ʾ�ˣ����յ�������ֵ��Ӧ���ǵ�row���������� 
		a[p] = 1;   //���һ����ʼ����1 
		for( q=p-1;q>0;q-- ) a[q] = a[q] + a[q-1]; //���
		p++;
	}
	
	return a[col]; //colΪ�±꣬���Ǻ����Ե���ʾ�� 
}

int main()
{
	printf("%d\n", f(4,2));
	printf("%d\n", f(6,3));
	printf("%lld\n", f(40,20));	
	return 0;
}

