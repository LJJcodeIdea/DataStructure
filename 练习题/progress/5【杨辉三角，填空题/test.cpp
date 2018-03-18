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
		第二行：
		1 2 1
		0 1 2 
			p
		第三行
		1 2 1 1   ->   1 2 3 1   -> 1 3 3 1
			  p
			q            q            q
		 
	*/
	//从第二行开始 
	while(p<=row){   //行数等于数组的最大下标，这不就是提示了，最终的数组数值，应该是第row的所有数。 
		a[p] = 1;   //最后一个数始终是1 
		for( q=p-1;q>0;q-- ) a[q] = a[q] + a[q-1]; //填空
		p++;
	}
	
	return a[col]; //col为下标，就是很明显的提示了 
}

int main()
{
	printf("%d\n", f(4,2));
	printf("%d\n", f(6,3));
	printf("%lld\n", f(40,20));	
	return 0;
}

