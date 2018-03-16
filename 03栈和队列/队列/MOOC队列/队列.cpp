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
	Ϊͷ��βָ����г�ʼ��
*/
void initializedQueue(Queue Q)
{
	Q->Front = Q->Rear = NULL;
}


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
	
	PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));

	newNode->Data = X;

	newNode->Next = NULL;
	
	if(Q->Rear == NULL)
	{	
		Q->Front = newNode;
		Q->Rear = Q->Front;									//Rearʼ��ָ��β���
	
	}
	else
	{
		Q->Rear->Next = newNode;
		Q->Rear = newNode;	
	}

	
	Q->Rear->Next = NULL;
	

}

/*
	����
*/
ElementType Delete(Queue Q)
{
	Position ProntCell;
	ElementType ProntElm;

	if(Q->Front == NULL)
	{
		printf("����һ���յĶ���\n");
		return -1;
	}
	else
	{
		ProntCell = Q->Front;
		printf("%d\n",Q->Front->Data);
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
	//���д���
	Queue newQ = (Queue)malloc(sizeof(struct QNode));

	//���г�ʼ��
	initializedQueue(newQ);
		
	//���
	Insert(newQ,4);
	Insert(newQ,5);
	Insert(newQ,7);
	Insert(newQ,888888);


	Printf(newQ);

	Delete(newQ);

	Printf(newQ);
	


	return 0;
}
