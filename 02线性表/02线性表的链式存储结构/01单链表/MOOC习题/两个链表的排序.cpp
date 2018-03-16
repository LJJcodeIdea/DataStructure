#include <stdio.h>
#include <stdlib.h>
/*
	typedef 类似 宏定义，但又不相同。
		
		typedef struct Node * PtrToNode;

		如果用PtrToNode 定义一个变量，例： PtrToNode a; 则 相当于 struct Node * a;

        typedef PtrToNode List;

		假如，用 List 定义一个变量，则意义同上，因为 List 代表 PtrToNode;而 PtrToNode 表示 一个 Node * 类型的结构体指针变量。

   这里用 typedef 关键字的主要目的是简化定义。

*/
typedef int ElementType;
typedef struct Node * PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
//读取函数
List Read()
{
	//确认要输入多少个函数
	int len = 0;
	
	scanf("%d/n",&len);
	
	List pHead = (List)malloc(sizeof(List));	//链表的头结点,因为pHead 是一个 struct Node *  类型的 指针，所以应该放一个 struct Node * 类型变量的 地址。
	
	List pTail = pHead;							//链表的最后一个节点

	pTail->Next = NULL;							//最后一个节点的指针为空

	for(int i = 0;i < len;i++)					
	{
		int temp = 0;
		
		scanf("%d",&temp);

		List pNew = (List)malloc(sizeof(List));
		
		pNew->Data = temp;       //

		pTail->Next = pNew;     //新增的节点跟上一个节点连接起来了

		pNew->Next = NULL;

		pTail = pNew;			//现在的节点赋给最后一个节点
		
	}

	return pHead;
}

//链表的遍历
void Print(List L)
{
	if(L->Next != NULL)
	{
		List pt2 =L->Next;
		while(pt2 != NULL)
		{
			printf("%d ",pt2->Data);

			pt2 = pt2->Next;
		}
		printf("\n");
	}
	else
	{
		printf("NULL\n");
	}
}

List Merge( List L1, List L2 )
{
	List Head = (List)malloc(sizeof(List));

	Head->Next = NULL;

	List Tail = Head;

	int len2 = 0;

	 List pt3;

	for(int u = 0;u<2;u++)
	{
		if(u==0)
		{
	       pt3 = L1->Next;
		}
		else
		{
		   pt3 = L2->Next;
		}

		while(pt3 != NULL)
		{
			List New3 = (List)malloc(sizeof(List));

			New3->Data = pt3->Data;

			New3->Next = NULL;

			Tail->Next = New3;  //与上一个节点相连

			Tail = New3;		//尾节点指向最后一个节点

			pt3 = pt3->Next;

			len2++;
		}

	}

	//对链表内的内容进行排序
	int k,l;
	int swap;
	List m,n;
	
	for(k = 0,m = Head->Next;k < len2 - 1;k++,m = m->Next)
	{
		for(l = k + 1,n = m->Next;l < len2;l++,n = n->Next)
		{
			if(m->Data > n->Data)
			{
				swap = m->Data;
				m->Data = n->Data;
				n->Data = swap;
			}
		}
	}

	L1->Next = NULL;
	L2->Next = NULL;

	return Head;
}

/*
	//    链表排序-----冒泡排序
void Sort_List(pNode pHead)
{
    int i,j;        
    int swap;            //存放交换数据的临时变量
    int len = LengthList(pHead);    //获取链表长度
    pNode m,n;        
    
    for (i = 0,m = pHead->pNext; i < len - 1; i++,m = m->pNext)
    {
        for (j = i + 1,n = m->pNext;j < len; j++,n = n->pNext)
        {
            if (m->member < n->member)                    
            {
                swap = m->member;
                m->member = n->member;
                n->member = swap;
            }
        }
    }
    printf("排序完后结果为：");
    TraverseList(pHead);
    return ;
} 
*/