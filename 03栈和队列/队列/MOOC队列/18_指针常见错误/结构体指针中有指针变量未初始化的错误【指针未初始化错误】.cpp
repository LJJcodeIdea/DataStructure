//��ʽ�洢���е�ʵ��
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
};
typedef struct QNode *Queue;

/*
	�ж϶����Ƿ�Ϊ��
*/
bool isEmpty(Queue Q)
{
	return (Q->Front== NULL);
}

/*
	���
*/
void Insert(Queue Q,ElementType X)
{
	
	PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));  //nweNode �Ǳ������˶�̬���ڴ棬�ö�̬�ڴ���Ҫ�ֶ��ͷ�

	newNode->Data = X;

	newNode->Next = NULL;
	
	printf("%d\n",Q->Rear);		//�ɽ����֪��������еĽ������ͬ����Q->Rear ��һ��Ұָ�룬���ָ��һ���ڴ��ַ��
	printf("%d\n",(Q->Front == NULL));  
	printf("fuck\n");
	
	if(Q->Rear == NULL)		//Q->Rear �� Q->Front û�г�ʼ��������Ұָ�룬���ָ��һ���ڴ��ַ�� ���� Q->Rear == NULL �Ľ���� 0 ��Ҳ����false��
	{
		
		printf("dfjls\n");
	
		Q->Front = newNode;
		Q->Rear = Q->Front;									//Rearʼ��ָ��β���
	
	}
	else
	{
			printf("Third\n");

		
	}
	printf("sdfsdjfl\n");
	
//	Q->Rear->Next = NULL;
	

}

/*
	����
*/
ElementType Delete(Queue Q)
{
	Position ProntCell;
	ElementType ProntElm;

	if(Q->Front = NULL)
	{
		printf("����һ���յĶ���\n");
		return -1;
	}
	else
	{
		ProntCell = Q->Front;
		ProntElm = ProntCell->Data;
		
		if(Q->Front->Next == Q->Rear)  //ֻ��һ�����
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
	��ӡ����
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
	//���д���
	Queue newQ = (Queue)malloc(sizeof(struct QNode));		//����֮����Q->Rear ���Ѿ������ˣ����� Q->Rear �� Q->Front�� ��û�г�ʼ��������û�г�ʼ���ı���������ʹ��δ��ʼ���ı�����������ͻ����
		
	//���
	Insert(newQ,4);
//	Printf(newQ);
		printf("%d\n",(newQ->Front == NULL));  // ��ֵΪ 0 ��false��1 ��true
		
	//	printf("%d\n",(newQ->Front->Data==NULL));

//		printf("%d\n",newQ->Front->Data);


	return 0;
}
