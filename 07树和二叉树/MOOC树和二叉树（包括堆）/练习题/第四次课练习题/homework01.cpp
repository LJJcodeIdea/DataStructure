#include <stdio.h>
#include <malloc.h>

//�������ı�ʾ
typedef struct TreeNode * Tree;
struct TreeNode
{
	int v;
	Tree Left,Right;
	int flag;		//�洢�б��Ľ��
};

//��Ž��
typedef struct Node * Pre;
struct Node
{
	int data;
	Pre Next;

};
typedef Pre Thenode;

void putNext(Thenode head,int num)
{
	Thenode Tail = head;
	
	int flag = 1;

	Thenode newNode = (Thenode)malloc(sizeof(struct Node));

	newNode->data =  num;
	newNode->Next = NULL;

	while(flag)
	{
		if(Tail->Next == NULL)
		{
			Tail->Next = newNode;
			flag = 0;
		}
		else
		{
			Tail = Tail->Next;
		}
	}

	//free(Tail);
}

//���
int check(Tree T,int V)
{
	if(T->flag)
	{
		if(V<T->v) return check(T->Left,V);
		else if(V>T->v) return check(T->Right,V);
		else return 0;  //�����Ƚϵ�����ֻ������һ�Σ������бȽϵĳ�������
	}
	else
	{
		if(V==T->v)
		{
			T->flag = 1;
			return 1;
		}
		else return 0; //֮ǰû�������ģ����ֲ���ȣ�����ͬλ��ȴ��ƥ��
	}
}

//�����б�
int Judge(Tree T,int N)
{
	int i,V,flag = 0;  //flag:0����Ŀǰ��һ�£�1,������Ѿ���һ�£���Ϊ�ж�������ȷ�������е�ÿ��Ԫ�ض����������˱Ƚϣ������ᵼ���в�ͬ�ľ������������滹��Ԫ��û���бȽϣ��ֱ�������һ�����е�����

	scanf("%d",&V);	//������бȽϵ����еĵ�һ����

	if(V!=T->v) flag = 1;
	else T->flag = 1;
	for(i = 1;i < N;i++)
	{
		scanf("%d",&V);
		if( (!flag) && (!check(T,V)) ) flag = 1;
	}
	if(flag) return 0;
	else return 1;

}

//���T�����ڵ��flag���
void ResetT(Tree T)
{
//	printf("sdjflsadf\n");
	if(T->Left) ResetT(T->Left);
	if(T->Right) ResetT(T->Right);
	T->flag = 0;
}

//�ͷ�T�Ŀռ�
void FreeTree(Tree T) 
{
	if(T->Left) FreeTree(T->Left);
	if(T->Right) FreeTree(T->Right);
	free(T);
}

//2����ʼ���ڵ�
Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));

	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

//3������ڵ�
Tree Insert(Tree T,int V)
{
	if(!T) T = NewNode(V);
	else
	{
		if(V>T->v)
			T->Right = Insert(T->Right,V);
		else
			T->Left = Insert(T->Left,V);
	}

	return T;
}

//1����������
Tree MakeTree(int N)
{
	Tree T;
	int i,V;

	scanf("%d",&V);  //��ȡ��һ���ڵ�� ����
	T = NewNode(V);	 //�����г�ʼ������������һ���ڵ�����	

	for(i = 1;i < N;i++)  //��������ڵ�
	{
		scanf("%d",&V);
		T = Insert(T,V);
	}
	return T;
}

int main()
{
	int N,L,i;
	Tree T;

	Thenode result = (Thenode)malloc(sizeof(struct Node));
	result->Next = NULL;

	scanf("%d",&N);

	while(N)
	{
		scanf("%d",&L);

		T = MakeTree(N);		//����,�����Աȵ���

		for(i = 0; i < L; i++)
		{
			if(Judge(T,N)) putNext(result,1);		//�Ƚ�
			else putNext(result,0);
		
			
			ResetT(T);		/*���T�еı��flag*/	
		}

		FreeTree(T);
		scanf("%d",&N);
	}

	i = 0;
	Thenode temp = result->Next;
	while(temp)
	{
		
		if(temp->data == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		temp = temp->Next;
	}
	return 0;

}