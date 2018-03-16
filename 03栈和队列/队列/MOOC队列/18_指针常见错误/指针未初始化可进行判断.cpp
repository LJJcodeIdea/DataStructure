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

	ElementType Dataq;
};
typedef struct QNode *Queue;


void test(Queue Q)
{
	PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));

	newNode->Data = 100;

	//test
	
//	printf("%d\n",(Q->Front->Next == NULL));		//这句会出错的原因是，Q->Front 并没有初始化，是一个野指针（随机指向一个内存地址），所以此时该内存地址内 并没有 Next 这个变量

	print("%d\n",(Q->Front == NULL));         //尽管Q->Front并没有初始化，但它还是乱指向了一个地址，所以Q->Front是存放了一个地址值，这里的判断是可以正常运行。所以结果是 0 【依旧是false】

	if(0)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	Q->Front = newNode;

	Q->Dataq = 45;

}

int main()
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));

	test(Q);
	printf("%d\n",Q->Front->Data);
	printf("%d\n",Q->Dataq);
	return 0;
}