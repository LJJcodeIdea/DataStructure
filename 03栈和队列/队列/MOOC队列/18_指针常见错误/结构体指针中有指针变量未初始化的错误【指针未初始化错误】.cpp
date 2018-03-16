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
	
	PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));  //nweNode 是被分配了动态的内存，该动态内存需要手动释放

	newNode->Data = X;

	newNode->Next = NULL;
	
	printf("%d\n",Q->Rear);		//由结果可知（多次运行的结果都不同），Q->Rear 是一个野指针，随机指向一个内存地址，
	printf("%d\n",(Q->Front == NULL));  
	printf("fuck\n");
	
	if(Q->Rear == NULL)		//Q->Rear 和 Q->Front 没有初始化，都是野指针，随机指向一个内存地址， 所以 Q->Rear == NULL 的结果是 0 【也就是false】
	{
		
		printf("dfjls\n");
	
		Q->Front = newNode;
		Q->Rear = Q->Front;									//Rear始终指向尾结点
	
	}
	else
	{
			printf("Third\n");

		
	}
	printf("sdfsdjfl\n");
	
//	Q->Rear->Next = NULL;
	

}

/*
	出队
*/
ElementType Delete(Queue Q)
{
	Position ProntCell;
	ElementType ProntElm;

	if(Q->Front = NULL)
	{
		printf("这是一个空的队列\n");
		return -1;
	}
	else
	{
		ProntCell = Q->Front;
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
	
	printf("%d ",Q->Front->Next->Data);
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
	Queue newQ = (Queue)malloc(sizeof(struct QNode));		//错误之处，Q->Rear 是已经创建了，但是 Q->Rear 和 Q->Front， 并没有初始化，你用没有初始化的变量。当你使用未初始化的变量进行运算就会出错。
		
	//入队
	Insert(newQ,4);
//	Printf(newQ);
		printf("%d\n",(newQ->Front == NULL));  // 数值为 0 是false，1 是true
		
	//	printf("%d\n",(newQ->Front->Data==NULL));

//		printf("%d\n",newQ->Front->Data);


	return 0;
}
