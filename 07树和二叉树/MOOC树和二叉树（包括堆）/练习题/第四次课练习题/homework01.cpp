#include <stdio.h>
#include <malloc.h>

//搜索树的表示
typedef struct TreeNode * Tree;
struct TreeNode
{
	int v;
	Tree Left,Right;
	int flag;		//存储判别后的结果
};

//存放结果
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

//标记
int check(Tree T,int V)
{
	if(T->flag)
	{
		if(V<T->v) return check(T->Left,V);
		else if(V>T->v) return check(T->Right,V);
		else return 0;  //用来比较的序列只出现了一次，而进行比较的出现两次
	}
	else
	{
		if(V==T->v)
		{
			T->flag = 1;
			return 1;
		}
		else return 0; //之前没遇见过的，而又不相等，就是同位置却不匹配
	}
}

//进行判别
int Judge(Tree T,int N)
{
	int i,V,flag = 0;  //flag:0代表目前还一致，1,代表标已经不一致，作为判断条件，确保序列中的每个元素都与树进行了比较，而不会导致有不同的就跳出，而后面还有元素没进行比较，又被当成下一个序列的问题

	scanf("%d",&V);	//输入进行比较的序列的第一个数

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

//清除T各个节点的flag标记
void ResetT(Tree T)
{
//	printf("sdjflsadf\n");
	if(T->Left) ResetT(T->Left);
	if(T->Right) ResetT(T->Right);
	T->flag = 0;
}

//释放T的空间
void FreeTree(Tree T) 
{
	if(T->Left) FreeTree(T->Left);
	if(T->Right) FreeTree(T->Right);
	free(T);
}

//2、初始化节点
Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));

	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

//3、插入节点
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

//1、建搜索树
Tree MakeTree(int N)
{
	Tree T;
	int i,V;

	scanf("%d",&V);  //读取第一个节点的 内容
	T = NewNode(V);	 //树进行初始化，并赋给第一个节点内容	

	for(i = 1;i < N;i++)  //继续插入节点
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

		T = MakeTree(N);		//建树,用来对比的树

		for(i = 0; i < L; i++)
		{
			if(Judge(T,N)) putNext(result,1);		//比较
			else putNext(result,0);
		
			
			ResetT(T);		/*清除T中的标记flag*/	
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