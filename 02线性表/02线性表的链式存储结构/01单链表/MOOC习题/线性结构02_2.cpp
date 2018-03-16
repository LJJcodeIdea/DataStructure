

// test.cpp : �������̨Ӧ�ó������ڵ㡣
//




#include "stdlib.h"
#include <stdio.h>
#include <malloc.h>

/*
	���ϵ����ָ���Ľ��
*/

typedef int ElementType;
typedef struct Node * Ptr;
struct Node
{
	ElementType Ratio;    //ϵ��
	ElementType Exponent;	//ָ��
	Ptr Next;
};
typedef Ptr Row;

struct Origin
{
	Row Head;
	Row Tail;
};
typedef struct Origin * TWO;

/*
	��ʼ��
*/
void initOrigin(TWO t)
{
	t->Head = (Ptr)malloc(sizeof(struct Node));
	t->Tail = (Ptr)malloc(sizeof(struct Node));
}

/*
	�����ݽ�������
*/
void ScanfOp(Row row,int num)
{

	int temp1 = 0;
	int temp2 = 0;
	Ptr tempRow = (Ptr)malloc(sizeof(struct Node));
	tempRow = row;
	tempRow->Next = NULL;
	for(int i = 0;i<num;i++)
	{
		//��ϵ����ָ�����洢���½��Ľ��
		Ptr newNode = (Ptr)malloc(sizeof(struct Node));
		
		scanf("%d",&temp1);
		scanf("%d",&temp2);
		
		newNode->Ratio = temp1;
		newNode->Exponent = temp2;
		//���½ڵ���ͷ�������
		tempRow->Next = newNode;
		tempRow = newNode;
		tempRow->Next = NULL;
	}
//	free(tempRow);
}

void Length(TWO T)
{
	Ptr tempRow = T->Head->Next;
	int i = 0;
	while(tempRow)
	{
		i++;
		tempRow = tempRow->Next;
	}
	printf("��һ���ĳ��ȣ�%d\n",i);

	tempRow = T->Tail->Next;
	i = 0;
	while(tempRow)
	{
		i++;
		tempRow = tempRow->Next;
	}
	printf("�ڶ����ĳ��ȣ�%d\n",i);
	free(tempRow);
}



void ScanfInfo(TWO T)
{
	int num = 0;


	for(int i = 0;i < 2;i++)
	{
		//���ո���
		printf("�������\n");
		scanf("%d",&num);

		//����ÿһ��
		if(i == 0)
		{
			ScanfOp(T->Head,num);
		}
		else
		{
			ScanfOp(T->Tail,num);
		}

	}

}

/*
	��˲���
*/
Row multiplied(TWO T)
{
	
	//�洢����������
	Row row = (Row)malloc(sizeof(struct Node));
	Row tempRow = row;
	row->Next = NULL;
	
	Row temp1 = T->Head->Next;
	Row temp2 = T->Tail->Next;
	//
	int i= 0; 
	while(temp1)
	{
		
		while(temp2)
		{
		   Ptr newNode = (Ptr)malloc(sizeof(struct Node));
		   newNode->Ratio = temp1->Ratio * temp2->Ratio;
		   newNode->Exponent = temp1->Exponent + temp2->Exponent;
		   tempRow->Next = newNode;
		   tempRow = newNode;
		   tempRow->Next = NULL;
		   temp2 = temp2->Next;
	
		}
	
	
		  temp1 = temp1->Next;
		
		
		temp2 = T->Tail->Next;

	}

	//free(tempRow);
	return row;
}
/*
	��֤����ĳ���
*/
int len(Row row)
{
	Row L = row->Next;
	int l = 0;
	while(L != NULL)
	{
		l++;
		
		L = L->Next; 
	}
	
	return l;
}
/*
	�Խ���������򣬰���ָ������
	
*/
void sort(Row row)
{
	Row tempRow = (Row)malloc(sizeof(struct Node));
	Row pre,pre2;
	pre = row->Next;
	pre2 = row->Next;
	int i = len(row);
	while(i>0)
	{
		while(pre2&&pre->Next)
		{
		
		
			//printf("�ǿգ���   %d\n",pre->Exponent);
			//printf("%d %d\n",pre->Exponent,pre->Next->Exponent);
			if(pre->Exponent > pre->Next->Exponent )
			{
				tempRow->Exponent = pre->Exponent;
				tempRow->Ratio = pre->Ratio;
			    pre->Exponent = pre->Next->Exponent;
				pre->Ratio = pre->Next->Ratio ;
				pre->Next->Exponent = tempRow->Exponent;
				pre->Next->Ratio = tempRow->Ratio;
				

/*				tempRow = pre->Next;			//����ʱ�ڵ� ָ�� �ȵ�ǰ�ڵ��С��
				pre->Next = pre->Next->Next;	//��ǰ��Nextָ�����¸��ڵ㣬��ָ��֮ǰ�Ľڵ㡣���ڵ�ǰ�ڵ��Nextָ�����¸��ڵ㣬ͬʱ����ǰ�ڵ�֮ǰNextָ��Ľڵ��Next����ǰ�ڵ��Next��ָ����һ����
				tempRow->Next = pre;			//��ǰ�ڵ�֮ǰNextָ��Ľڵ��Nextָ��ǰ�ڵ㣬��λ���
			
				if(row->Next == tempRow->Next)  //ȷ��ͷ�ڵ�ʼ��ָ���һ�����ݽڵ�
				{
					row->Next = tempRow;
				}
				
*/			

			}
			pre2 = pre2->Next;
				pre = pre->Next;
		}
		pre2 = row->Next;
		i--;
	}
	free(tempRow);					//�ͷſռ�

  
}
void PrintfList(Row row)
{
	


	Row tempRow = row->Next;

	printf("%d %d",tempRow->Ratio,tempRow->Exponent);

	tempRow = tempRow->Next;
	
	while(tempRow)
	{
		printf(" ");
		printf("%d %d",tempRow->Ratio,tempRow->Exponent);
		tempRow = tempRow->Next;
	}
	printf("\n");
	free(tempRow);

	printf("PrintfList\n");
}

int main(void)
{
		//����
	TWO T = (TWO)malloc(sizeof(struct Origin));

	//��ʼ��
	initOrigin(T);

	//�������
	ScanfInfo(T);

	//�鿴�Ƿ�����ɹ�
	Length(T);
		printf("before\n");
	//���г˷������������
	Ptr result = multiplied(T);
	PrintfList(result);
	printf("after\n");

	
	
	
	
	//��������
	sort(result);



	//�������
	PrintfList(result);


	return 0;
}


