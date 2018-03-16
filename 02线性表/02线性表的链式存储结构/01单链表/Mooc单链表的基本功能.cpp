#include  <stdio.h>
#include <malloc.h>

typedef struct Node * nodeType;

struct Node
{
	int data;

	nodeType next;
};
typedef nodeType Position;
typedef nodeType List;

/*
	创建链表,链表的长度，节点的内容
*/
List LinkedList()
{
	int len = 0;
	printf("请输入链表的长度：\n");
	scanf("%d",&len);
	
	List head,tail;
    head = (List)malloc(sizeof(struct Node)); //链表的头节点
	head->next = NULL;
	tail = head;	//链表的尾节点

	printf("请输入链表的内容\n");
	for(int i = 0;i < len;i++)
	{	
		int temp;
		List newNode = (List)malloc(sizeof(struct Node)); //新增节点，用于存储当前内容
		scanf("%d",&temp);
		newNode->data = temp;

		tail->next = newNode;   //新增节点被上一节点的next指向
		newNode->next = NULL;
		tail = newNode;			//tail始终指向链表的最后一个节点

	}

	return head;
}

/*
	计算链表的长度
*/
void LinkLenth(List L)
{
	int lt = 0;
	
	List tempGet = L->next;
	
	while(tempGet)		//tempGet 为NULL时跳出
	{
		tempGet = tempGet->next;
		lt++;
	}

	printf("链表的长度为：%d\n",lt);
}

/*
	查找，链表，对应的内容
*/
#define ERROR NULL

Position Find(List L,int value)
{
	Position p = L->next;

	while(p && p->data != value)
	{
		p = p->next;
	}

	if(p)
		return p;
	else
		return ERROR;

	
}

/*
	插入节点
*/
bool Insert(List L,int value,Position p)
{
	
	Position tem,pre;
	
	//找到插入处的节点的前一个节点，用pre存放地址  //默认有头结点
	for(pre=L;pre&&pre->next != p;pre=pre->next);

	if(pre == NULL || p ==NULL)   //默认有尾节点
	{
		printf("插入位置有误！\n");
		return false;
	}
	else
	{
		tem = (List)malloc(sizeof(struct Node));  //初始化存放数据的节点
		tem->data = value;       
		pre->next = tem;                //插入处的前一个节点 与 存放数据的节点相连
		tem->next = p;					//存放数据的节点  与插入出的节点相连	
		return true;
	}
}

/*
	删除节点
*/

bool Delete(List L,Position p)
{
	
	Position pre;

	//获取删除节点的前一个节点  //默认有头结点

	for(pre = L;pre&&pre->next != p;pre = pre->next);

	if(pre ==NULL || p ==NULL) //默认有尾节点
	{
		printf("删除位置参数错误\n");	
		return false;
	}
	else
	{
		pre->next = p->next;
		
		free(p);

		return true;
	}

	
}
/*
   打印链表
*/
void Printf(List L)
{
	List p = L->next;

	printf("链表的内容：\n");
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}

	printf("\n");
}

int main(void)
{
	List tempL;
	tempL = LinkedList();
	Printf(tempL);

	List templ2 = Find(tempL,1);
	
	Insert(tempL,777,templ2);

	Delete(tempL,templ2);	

	LinkLenth(tempL);


	Printf(tempL);
	return 0;
}