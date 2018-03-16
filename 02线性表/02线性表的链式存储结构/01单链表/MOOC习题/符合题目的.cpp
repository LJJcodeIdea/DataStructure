


// test.cpp : 定义控制台应用程序的入口点。
//
/*
	仍存在的问题：
		同类项合并时有抵消，会出现问题
*/



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
	相加操作
*/
Row Sum(TWO T)
{
	//存储运算后的所有结果
	Row row = (Row)malloc(sizeof(struct Node));
	Row tempRow = row;
	row->Next = NULL;

	Row temp1 = T->Head->Next;
	Row temp2 = T->Tail->Next;

	Row * del = NULL;

//1、temp1 比 temp2 多 。  2、temp1 比 temp2 少
	

	while(temp1&&temp2)
	{
		while(temp1&&temp2)
		{
			Ptr newNode = (Ptr)malloc(sizeof(struct Node));
			
			//指数的比较，有三种情况
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


	//若 temp2 处理完，temp1 还有剩余
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

	//若 temp1 处理完，temp2 还有剩余
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

//	free(tempRow);   这里有意思

	//假如所有项相加的结果为0

	if(row->Next == NULL)
	{
		row->Exponent = 0;
		row->Ratio = 0;
	}
	return row;
}


/*
	对结果进行排序，按照指数降序
	
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
	
	//合并同类项，假如进行 相乘 或 相加 操作后，还有同类项
	pre = row->Next;
	Ptr pre0 = row;
	while(pre&&pre->Next)
	{
		if(pre->Exponent == pre->Next->Exponent)  //因为按顺序排列，直接判断相邻两个指数
		{
			pre->Ratio = pre->Ratio + pre->Next->Ratio;

			//判断同类项相加后是否为零
			if(pre->Ratio != 0)  
			{
			   pre->Next = pre->Next->Next;
			}
			else if(pre->Ratio == 0 && row->Next == pre) //为零时，在第一位的处理
			{
				row->Next = pre->Next->Next;
				pre = row;
			}
			else
			{
				if(pre0->Next->Next->Next != NULL)		//为零，在接近末尾处，防止末尾越界的处理
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
	

	free(tempRow);					//释放空间

	
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
	//创建
	TWO T = (TWO)malloc(sizeof(struct Origin));

	//初始化
	initOrigin(T);

	//输入操作
	ScanfInfo(T);

	//进行乘法操作后的链表
	Ptr result = multiplied(T);

	//进行排序
	sort(result);

	//进行输出
	PrintfList(result);

	Ptr result2 = Sum(T);
	sort(result2);
	PrintfList(result2);

	


	return 0;
}
