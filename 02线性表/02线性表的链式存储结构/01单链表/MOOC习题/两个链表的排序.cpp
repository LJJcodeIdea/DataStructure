#include <stdio.h>
#include <stdlib.h>
/*
	typedef ���� �궨�壬���ֲ���ͬ��
		
		typedef struct Node * PtrToNode;

		�����PtrToNode ����һ������������ PtrToNode a; �� �൱�� struct Node * a;

        typedef PtrToNode List;

		���磬�� List ����һ��������������ͬ�ϣ���Ϊ List ���� PtrToNode;�� PtrToNode ��ʾ һ�� Node * ���͵Ľṹ��ָ�������

   ������ typedef �ؼ��ֵ���ҪĿ���Ǽ򻯶��塣

*/
typedef int ElementType;
typedef struct Node * PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

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

/* ��Ĵ��뽫��Ƕ������ */
//��ȡ����
List Read()
{
	//ȷ��Ҫ������ٸ�����
	int len = 0;
	
	scanf("%d/n",&len);
	
	List pHead = (List)malloc(sizeof(List));	//�����ͷ���,��ΪpHead ��һ�� struct Node *  ���͵� ָ�룬����Ӧ�÷�һ�� struct Node * ���ͱ����� ��ַ��
	
	List pTail = pHead;							//��������һ���ڵ�

	pTail->Next = NULL;							//���һ���ڵ��ָ��Ϊ��

	for(int i = 0;i < len;i++)					
	{
		int temp = 0;
		
		scanf("%d",&temp);

		List pNew = (List)malloc(sizeof(List));
		
		pNew->Data = temp;       //

		pTail->Next = pNew;     //�����Ľڵ����һ���ڵ�����������

		pNew->Next = NULL;

		pTail = pNew;			//���ڵĽڵ㸳�����һ���ڵ�
		
	}

	return pHead;
}

//����ı���
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

			Tail->Next = New3;  //����һ���ڵ�����

			Tail = New3;		//β�ڵ�ָ�����һ���ڵ�

			pt3 = pt3->Next;

			len2++;
		}

	}

	//�������ڵ����ݽ�������
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
	//    ��������-----ð������
void Sort_List(pNode pHead)
{
    int i,j;        
    int swap;            //��Ž������ݵ���ʱ����
    int len = LengthList(pHead);    //��ȡ������
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
    printf("���������Ϊ��");
    TraverseList(pHead);
    return ;
} 
*/