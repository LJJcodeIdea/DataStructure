#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Node * PtrToNode;
/*
	���н��
*/
struct Node
{
	ElementType Data;
	PtrToNode Next;
		
};
typedef PtrToNode Position;

/*
	ͷ��βָ��
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
	
//	printf("%d\n",(Q->Front->Next == NULL));		//��������ԭ���ǣ�Q->Front ��û�г�ʼ������һ��Ұָ�루���ָ��һ���ڴ��ַ�������Դ�ʱ���ڴ��ַ�� ��û�� Next �������

	print("%d\n",(Q->Front == NULL));         //����Q->Front��û�г�ʼ��������������ָ����һ����ַ������Q->Front�Ǵ����һ����ֵַ��������ж��ǿ����������С����Խ���� 0 ��������false��

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