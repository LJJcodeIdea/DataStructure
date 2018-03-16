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

			//�� cl �Ĵ���
			if(cl != '-')
			{
				T[i].Left = cl - '0';  //??
				check[T[i].Left] = 1;	//�±�Ϊ T(i).Left �Ľ�㣬�������Ľ��ָ�򣬲��Ǹ���㡣���б�ʶ����ʶΪ 1.
			}
			else T[i].Left = Null;

			//�� cr �Ĵ���

			if(cr != '-')
			{
				T[i].Right = cr - '0';  //??
				check[T[i].Right] = 1;	
			}
			else T[i].Right = Null;
		}

		for (i = 0; i < N; i++)
		{
			if(!check[i]) break;   //��check[i] �� ֵΪ 0 ʱ������ѭ����
		}

		Root = i;
	}
	
	return Root;
}

//�ж����������Ƿ�ͬ��
int Isomorphic(Tree R1,Tree R2)
{
	//��������Ϊ��
	if((R1 == Null ) && ( R2 == Null ))
	{
		return 1;
	}
		
	
	//һ����Ϊ�գ���һ����Ϊ��
	if( ((R1 == Null) && (R2 != Null)) || ( (R1 != Null)&&(R2 == Null) ))
	{
		return 0;
	}
	
	
	//����㲻ͬ
	if ( T1[R1].Element != T2[R2].Element )
	{
		return 0;
	}
	

	//��������������������ǿյģ����ж� �������Ƿ�ͬ��
	if( (T1[R1].Left == Null) && (T2[R2].Left == Null))
	{
			return Isomorphic(T1[R1].Right,T2[R2].Right);

	}
		

	//�����������������Ϊ�գ� �� ���������� ��ͬ
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