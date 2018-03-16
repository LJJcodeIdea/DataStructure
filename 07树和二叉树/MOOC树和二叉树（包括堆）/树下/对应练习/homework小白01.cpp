#include <stdio.h>
#include <malloc.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN],size;

//堆的初始化
void Create()
{
	size = 0;
	H[0] = MINH; //设置 哨兵
}

//插入操作
int Insert(int X)
{
	/*将 X 插入H*/

	if(size==1000) return 0;

	int i;
	
	/*
		这里是从最后一个节点的父节点 开始 跟 X 进行比较，
		一开始的i就是 堆的最后一个节点的下标，i/2 就是
		当前节点的父节点的下标。

		当碰到一个比 X小 的节点，就跳出循环，插入到当前节点的子节点中，下标为i。

		当一开始的最后一个节点的父节点比 X 大，就会 将当前节点 移动到其字节点的位置，
		然后继续跟下一父节点比较
	*/
	for(i=++size;H[i/2]>X;i/=2)
		H[i] = H[i/2];

	H[i]=X;
	return 1;
}

int main()
{
	int n,m,x,i,j;

	scanf("%d %d/n",&n,&m);

	Create();  //初始化堆；

	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		Insert(x);
	}
	
	for(i=0;i<m;i++)
	{
		scanf("%d",&j);
		printf("%d",H[j]);
		while(j>1)
		{
			j/=2;
			printf(" %d",H[j]);
		}
		printf("\n");
	}

	return 0;
}