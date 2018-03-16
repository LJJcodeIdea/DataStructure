#include <stdio.h>
#include <malloc.h>

#define MaxTree 10
#define ElementType char
#define Tree int 
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree]; 


Tree BuildTree(struct TreeNode T[])
{
	int N,i,Root=Null;
	char cl,cr;



	scanf("%d\n",&N);

	int * check = (int *)malloc(sizeof(int) * N);

	if(N)
	{
		
		for(i = 0; i<N; i++) 
		{
			check[i] = 0;
		}

		for(i = 0; i<N; i++)
		{
			scanf("%c %c %c\n",&T[i].Element,&cl,&cr);

			//对 cl 的处理
			if(cl != '-')
			{
				T[i].Left = cl - '0';  //??
				check[T[i].Left] = 1;	//下标为 T(i).Left 的结点，被其他的结点指向，不是根结点。进行标识，标识为 1.
			}
			else T[i].Left = Null;

			//对 cr 的处理

			if(cr != '-')
			{
				T[i].Right = cr - '0';  //??
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

//判断两二叉树是否同构
int Isomorphic(Tree R1,Tree R2)
{
	//两颗树都为空
	if((R1 == Null ) && ( R2 == Null ))
	{
		return 1;
	}
		
	
	//一棵树为空，另一个不为空
	if( ((R1 == Null) && (R2 != Null)) || ( (R1 != Null)&&(R2 == Null) ))
	{
		return 0;
	}
	
	
	//根结点不同
	if ( T1[R1].Element != T2[R2].Element )
	{
		return 0;
	}
	

	//如果两颗树的左子树都是空的，则判断 右子树是否同构
	if( (T1[R1].Left == Null) && (T2[R2].Left == Null))
	{
			return Isomorphic(T1[R1].Right,T2[R2].Right);

	}
		

	//如果根结点的左子树不为空， 且 根结点的左结点 相同
	if( ((T1[R1].Left != Null)&&(T2[R2].Left != Null)) && ( ( T1[T1[R1].Left].Element ) ==  ( T2[T2[R2].Left].Element ) ) )
	{
		return (Isomorphic(T1[R1].Left,T2[R2].Left) && Isomorphic(T1[R1].Right,T2[R2].Right));
	}
	else
	{
		return ( Isomorphic(T1[R1].Left,T2[R2].Right) && Isomorphic(T1[R1].Right,T2[R2].Left) );
	}
}

int main(void)
{
	Tree R1,R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);

	if(Isomorphic(R1,R2))  printf("Yes\n");
	else printf("No\n");

	return 0;
}