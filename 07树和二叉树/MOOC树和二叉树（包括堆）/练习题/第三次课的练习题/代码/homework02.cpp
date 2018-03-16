#include <stdio.h>
#include <malloc.h>

#define MaxTree 10
#define ElementType char
#define Tree int 
#define Null -1

/*
	���齨����ԭ��

	�������� ������ �� �����Ľṹ
*/

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree];

/*
	���������������ݡ�
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

			T[i].Element = 10;  //�����ڲ������ʱ���ж� �����Ƿ�Ϊ��
		}

		for(i = 0; i<N; i++)
		{
			scanf("%c %c\n",&cl,&cr);

			T[i].Element = i;      // ����ýڵ��������е��±꣬�� Delete�����л��õ���

			//�� cl �Ĵ���
			if(cl != '-')
			{
				T[i].Left = cl - '0'; 
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;

			//�� cr �Ĵ���

			if(cr != '-')
			{
				T[i].Right = cr - '0';  
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

/*
	Ϊ�����������
*/
void Addt(struct TreeNode L[],struct TreeNode node, int * p)
{
	printf("add\n");
	L[*p] = node ;

	*p++;
}


/*
	ɾ�������е���λԪ�أ����ж��Ƿ�ΪҶ�ӽڵ�.

*/
struct TreeNode Delete(struct TreeNode L[],int R[],int q)
{
	printf("delete\n");
	if( (L[0].Left == Null) && (L[0].Right == Null) )	//�ж��Ƿ�ΪҶ�ӽڵ�
	{
		R[q] = L[0].Element;		//����±굽����� result

		q++;    
	}

	//ɾ����λ

	for(int i = 0; i < MaxTree-1; i++)
	{
		L[i] = L[i+1];

	}

	//�������ڵ���λ��Ҳ���Ǳ�ɾ��Ԫ�ص���һλ
	return L[0];

}

/*
	��ӳ��ӣ���� Ҷ�� �±꣬�����ظý����
*/

int * Deal(Tree Root,struct TreeNode t[])
{
	int i = 0;

	struct TreeNode List[MaxTree]; //���ڴ�����ݵĶ���

	struct TreeNode temp;  //

	//�ж����Ƿ�Ϊ�գ���Ϊ�գ��� �����÷�����
	if(t[Root].Element == 10) return 0;

	int q,p;
	q = p = 0;  //���ڱ��λ��

	int * result = (int *)malloc(sizeof(int) * MaxTree + 1);	//�����
	
	for(i = 0 ; i <= MaxTree; i++ ) result[i] = 10;

	//�����״���ӣ��Ÿ����
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