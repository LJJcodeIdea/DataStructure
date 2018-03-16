//链式存储队列的实现
#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Node * PtrToNode;
/*
	队列结点
*/
struct Node
{
	ElementType Data;
	PtrToNode Next;
		
};
typedef PtrToNode Position;

/*
	头与尾指针
*/
struct QNode
{
	Position Front,Rear;
};
typedef struct QNode *Queue;

/*
	为头与尾指针进行初始化
*/
void initializedQueue(Queue Q)
{
	Q->Front = Q->Rear = NULL;
}


/*
	判断队列是否为空
*/
bool isEmpty(Queue Q)
{
	return (Q->Front== NULL);
}

/*
	入队
*/
void Insert(Queue Q,ElementType X)
{
	
	PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));

	newNode->Data = X;

	newNode->Next = NULL;
	
	if(Q->Rear == NULL)
	{	
		Q->Front = newNode;
		Q->Rear = Q->Front;									//Rear始终指向尾结点
	
	}
	else
	{
		Q->Rear->Next = newNode;
		Q->Rear = newNode;	
	}

	
	Q->Rear->Next = NULL;
	

}

/*
	出队
*/
ElementType Delete(Queue Q)
{
	Position ProntCell;
	ElementType ProntElm;

	if(Q->Front == NULL)
	{
		printf("这是一个空的队列\n");
		return -1;
	}
	else
	{
		ProntCell = Q->Front;
		printf("%d\n",Q->Front->Data);
		ProntElm = ProntCell->Data;
		
		if(Q->Front->Next == Q->Rear)  //只有一个结点
		{
			Q->Front = Q->Rear = NULL; 
		}
		else
		{
			Q->Front = Q->Front->Next;
		}

		free(ProntCell);
	}



	return ProntElm;
}


/*
	打印队列
*/
void Printf(Queue Q)
{
	PtrToNode temp = Q->Front->Next;
	
	printf("%d ",Q->Front->Data);
	while(temp)
	{
		printf("%d ",temp->Data);
		temp = temp->Next;
	}
	printf("\n");
	
}

int main(void)
{
	//队列创建
	Queue newQ = (Queue)malloc(sizeof(struct QNode));

	//队列初始化
	initializedQueue(newQ);
		
	//入队
	Insert(newQ,4);
	Insert(newQ,5);
	Insert(newQ,7);
	Insert(newQ,888888);


	Printf(newQ);

	Delete(newQ);

	Printf(newQ);
	


	return 0;
}
