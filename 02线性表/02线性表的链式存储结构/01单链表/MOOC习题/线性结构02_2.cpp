

// test.cpp : 定义控制台应用程序的入口点。
//




#include "stdlib.h"
#include <stdio.h>
#include <malloc.h>

/*
	存放系数和指数的结点
*/

typedef int ElementType;
typedef struct Node * Ptr;
struct Node
{
	ElementType Ratio;    //系数
	ElementType Exponent;	//指数
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
	初始化
*/
void initOrigin(TWO t)
{
	t->Head = (Ptr)malloc(sizeof(struct Node));
	t->Tail = (Ptr)malloc(sizeof(struct Node));
}

/*
	对数据进行输入
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
		//将系数和指数都存储到新建的结点
		Ptr newNode = (Ptr)malloc(sizeof(struct Node));
		
		scanf("%d",&temp1);
		scanf("%d",&temp2);
		
		newNode->Ratio = temp1;
		newNode->Exponent = temp2;
		//将新节点与头结点连上
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
	printf("第一条的长度：%d\n",i);

	tempRow = T->Tail->Next;
	i = 0;
	while(tempRow)
	{
		i++;
		tempRow = tempRow->Next;
	}
	printf("第二条的长度：%d\n",i);
	free(tempRow);
}



void ScanfInfo(TWO T)
{
	int num = 0;


	for(int i = 0;i < 2;i++)
	{
		//接收个数
		printf("输入个数\n");
		scanf("%d",&num);

		//接收每一项
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
	相乘操作
*/
Row multiplied(TWO T)
{
	
	//存储运算后的所有
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
	验证链表的长度
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
	对结果进行排序，按照指数升序
	
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
		
		
			//printf("是空？！   %d\n",pre->Exponent);
			//printf("%d %d\n",pre->Exponent,pre->Next->Exponent);
			if(pre->Exponent > pre->Next->Exponent )
			{
				tempRow->Exponent = pre->Exponent;
				tempRow->Ratio = pre->Ratio;
			    pre->Exponent = pre->Next->Exponent;
				pre->Ratio = pre->Next->Ratio ;
				pre->Next->Exponent = tempRow->Exponent;
				pre->Next->Ratio = tempRow->Ratio;
				

/*				tempRow = pre->Next;			//个临时节点 指向 比当前节点的小的
				pre->Next = pre->Next->Next;	//当前的Next指向下下个节点，不指向之前的节点。现在当前节点的Next指向下下个节点，同时，当前节点之前Next指向的节点的Next跟当前节点的Next的指向是一样的
				tempRow->Next = pre;			//当前节点之前Next指向的节点的Next指向当前节点，换位完成
			
				if(row->Next == tempRow->Next)  //确保头节点始终指向第一个数据节点
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
	free(tempRow);					//释放空间

  
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
		//创建
	TWO T = (TWO)malloc(sizeof(struct Origin));

	//初始化
	initOrigin(T);

	//输入操作
	ScanfInfo(T);

	//查看是否输入成功
	Length(T);
		printf("before\n");
	//进行乘法操作后的链表
	Ptr result = multiplied(T);
	PrintfList(result);
	printf("after\n");

	
	
	
	
	//进行排序
	sort(result);



	//进行输出
	PrintfList(result);


	return 0;
}


