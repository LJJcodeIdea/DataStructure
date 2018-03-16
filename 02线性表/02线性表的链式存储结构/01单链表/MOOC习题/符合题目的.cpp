


// test.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
	�Դ��ڵ����⣺
		ͬ����ϲ�ʱ�е��������������
*/



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
	temp1 = row->Next;
	
	float i = 0;
	float f = (float)len(row);
	while(temp1&&temp1->Next)
	{
	
		if(temp1->Exponent == temp1->Next->Exponent )
		{
			i++;
		}

		temp1=temp1->Next;
	}
	
	if(i == f/2)
	{
		row->Exponent = 0;
		row->Ratio = 0;
		row->Next = NULL;
	}

	return row;
}
/*
	��Ӳ���
*/
Row Sum(TWO T)
{
	//�洢���������н��
	Row row = (Row)malloc(sizeof(struct Node));
	Row tempRow = row;
	row->Next = NULL;

	Row temp1 = T->Head->Next;
	Row temp2 = T->Tail->Next;

	Row * del = NULL;

//1��temp1 �� temp2 �� ��  2��temp1 �� temp2 ��
	

	while(temp1&&temp2)
	{
		while(temp1&&temp2)
		{
			Ptr newNode = (Ptr)malloc(sizeof(struct Node));
			
			//ָ���ıȽϣ����������
			if(temp1->Exponent == temp2->Exponent)
			{	
				newNode->Ratio = temp1->Ratio + temp2->Ratio ;
				newNode->Exponent = temp1->Exponent;
			
				if(newNode->Ratio != 0)
				{
					tempRow->Next = newNode;
					tempRow = newNode;
					tempRow->Next = NULL;	
				}
				
				temp1 = temp1->Next;
				temp2 = temp2->Next;
			}
			else if(temp1->Exponent > temp2->Exponent)
			{
				newNode->Exponent  = temp2->Exponent;
				newNode->Ratio = temp2->Ratio;
				tempRow->Next = newNode;
				tempRow = newNode;
				tempRow->Next = NULL;

				temp2 = temp2->Next;
			}
			else
			{
				newNode->Exponent  = temp1->Exponent;
				newNode->Ratio = temp1->Ratio;
				tempRow->Next = newNode;
				tempRow = newNode;
				tempRow->Next = NULL;

				temp1 = temp1->Next;
			}
			
		
		}
	}


	//�� temp2 �����꣬temp1 ����ʣ��
	if(temp1 != NULL)
	{
		while(temp1)
		{
			Ptr newNode = (Ptr)malloc(sizeof(struct Node));
			newNode->Exponent  = temp1->Exponent;
			newNode->Ratio = temp1->Ratio;
			tempRow->Next = newNode;
			tempRow = newNode;
			tempRow->Next = NULL;

			temp1 = temp1->Next;
		}

	}

	//�� temp1 �����꣬temp2 ����ʣ��
	if(temp2 != NULL)
	{
		while(temp2)		
		{
			Ptr newNode = (Ptr)malloc(sizeof(struct Node));
			newNode->Exponent  = temp2->Exponent;
			newNode->Ratio = temp2->Ratio;
			tempRow->Next = newNode;
			tempRow = newNode;
			tempRow->Next = NULL;

			temp2 = temp2->Next;
		}
	}

//	free(tempRow);   ��������˼

	//������������ӵĽ��Ϊ0

	if(row->Next == NULL)
	{
		row->Exponent = 0;
		row->Ratio = 0;
	}
	return row;
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
	
			if(pre->Exponent < pre->Next->Exponent )
			{
				tempRow->Exponent = pre->Exponent;
				tempRow->Ratio = pre->Ratio;
			    pre->Exponent = pre->Next->Exponent;
				pre->Ratio = pre->Next->Ratio ;
				pre->Next->Exponent = tempRow->Exponent;
				pre->Next->Ratio = tempRow->Ratio;
		
			}
			pre2 = pre2->Next;
			pre = pre->Next;
		}
	    pre = pre2 = row->Next;
		i--;
	}
	
	//�ϲ�ͬ���������� ��� �� ��� �����󣬻���ͬ����
	pre = row->Next;
	Ptr pre0 = row;
	while(pre&&pre->Next)
	{
		if(pre->Exponent == pre->Next->Exponent)  //��Ϊ��˳�����У�ֱ���ж���������ָ��
		{
			pre->Ratio = pre->Ratio + pre->Next->Ratio;

			//�ж�ͬ������Ӻ��Ƿ�Ϊ��
			if(pre->Ratio != 0)  
			{
			   pre->Next = pre->Next->Next;
			}
			else if(pre->Ratio == 0 && row->Next == pre) //Ϊ��ʱ���ڵ�һλ�Ĵ���
			{
				row->Next = pre->Next->Next;
				pre = row;
			}
			else
			{
				if(pre0->Next->Next->Next != NULL)		//Ϊ�㣬�ڽӽ�ĩβ������ֹĩβԽ��Ĵ���
				{
					pre0 = pre0->Next->Next->Next;
					pre = pre0;
				}
				else
				{
					pre0->Next =NULL;
					pre = pre0;
				}
			
			}
		
		}


		pre = pre->Next;
	
		
	}
	

	free(tempRow);					//�ͷſռ�

	
}


void PrintfList(Row row)
{
	

	if(row->Next != NULL)
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
	}
	else
	{
		printf("%d %d\n",row->Ratio,row->Exponent);
	
	}

	
}

int main(void)
{
	//����
	TWO T = (TWO)malloc(sizeof(struct Origin));

	//��ʼ��
	initOrigin(T);

	//�������
	ScanfInfo(T);

	//���г˷������������
	Ptr result = multiplied(T);

	//��������
	sort(result);

	//�������
	PrintfList(result);

	Ptr result2 = Sum(T);
	sort(result2);
	PrintfList(result2);

	


	return 0;
}
