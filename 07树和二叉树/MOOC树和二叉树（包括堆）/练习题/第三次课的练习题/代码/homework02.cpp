#include <stdio.h>
#include <malloc.h>

#define MaxTree 10
#define ElementType char
#define Tree int 
#define Null -1

/*
	数组建树的原理

	遍历树， 按数组 或 按树的结构
*/

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree];

/*
	建树，并输入数据。
*/

Tree BuildTree(struct TreeNode T[])
{
	int N,i,j=0,Root = Null;

	char cl,cr;

	scanf("%d\n",&N);

	int * check = (int *)malloc(sizeof(int) * N);

	if(N)
	{
		
		for(i = 0; i<N; i++) 
		{
			check[i] = 0;

			T[i].Element = 10;  //用于在层序遍历时，判断 队列是否为空
		}

		for(i = 0; i<N; i++)
		{
			scanf("%c %c\n",&cl,&cr);

			T[i].Element = i;      // 保存该节点在数组中的下标，在 Delete方法中会用到。

			//对 cl 的处理
			if(cl != '-')
			{
				T[i].Left = cl - '0'; 
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;

			//对 cr 的处理

			if(cr != '-')
			{
				T[i].Right = cr - '0';  
				check[T[i].Right] = 1;	
			}
			else T[i].Right = Null;
	
		}

		for (i = 0; i < N; i++)
		{
			if(!check[i]) break;   //当check[i] 的 值为 0 时，跳出循环；
		}

		Root = i;
	}

	return Root;
}

/*
	为队列添加数据
*/
void Addt(struct TreeNode L[],struct TreeNode node, int * p)
{
	printf("add\n");
	L[*p] = node ;

	*p++;
}


/*
	删除队列中的首位元素，并判断是否为叶子节点.

*/
struct TreeNode Delete(struct TreeNode L[],int R[],int q)
{
	printf("delete\n");
	if( (L[0].Left == Null) && (L[0].Right == Null) )	//判断是否为叶子节点
	{
		R[q] = L[0].Element;		//存放下标到结果集 result

		q++;    
	}

	//删除首位

	for(int i = 0; i < MaxTree-1; i++)
	{
		L[i] = L[i+1];

	}

	//返回现在的首位，也就是被删除元素的下一位
	return L[0];

}

/*
	入队出队，获得 叶子 下标，并返回该结果集
*/

int * Deal(Tree Root,struct TreeNode t[])
{
	int i = 0;

	struct TreeNode List[MaxTree]; //用于存放数据的队列

	struct TreeNode temp;  //

	//判断树是否为空，若为空，则 结束该方法。
	if(t[Root].Element == 10) return 0;

	int q,p;
	q = p = 0;  //用于标记位置

	int * result = (int *)malloc(sizeof(int) * MaxTree + 1);	//结果集
	
	for(i = 0 ; i <= MaxTree; i++ ) result[i] = 10;

	//进行首次入队，放根结点
	temp = t[Root];
	Addt(List,temp,&p);

	while(p != -1)
	{

		printf("while\n");
		temp = Delete(List,result,q);
		printf("%d\n",p);
		p--;
		if(p == -1) break;
		if(temp.Left != Null) Addt(List,t[temp.Left],&p);
		if(temp.Right != Null) Addt(List,t[temp.Right],&p);
	}

	return result;
}


void printfR(int * r)
{
	printf("sjdfljsdflkj\n");
	int i = 0;

	if(r[0] != 10)
	{
		printf("%d",r[0]);
		
		i++;

		while(r[i] != 10)
		{
			printf(" ");

			printf("%d",r[i]);

			i++;
		}
	}
	
	printf("\n");
}

int main()
{
	Tree R1;
	
	struct TreeNode T[MaxTree];

	R1 = BuildTree(T);

	int * result = Deal(R1,T);

	printfR(result);

	return 0;
}