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
	��������,����ĳ��ȣ��ڵ������
*/
List LinkedList()
{
	int len = 0;
	printf("����������ĳ��ȣ�\n");
	scanf("%d",&len);
	
	List head,tail;
    head = (List)malloc(sizeof(struct Node)); //�����ͷ�ڵ�
	head->next = NULL;
	tail = head;	//�����β�ڵ�

	printf("���������������\n");
	for(int i = 0;i < len;i++)
	{	
		int temp;
		List newNode = (List)malloc(sizeof(struct Node)); //�����ڵ㣬���ڴ洢��ǰ����
		scanf("%d",&temp);
		newNode->data = temp;

		tail->next = newNode;   //�����ڵ㱻��һ�ڵ��nextָ��
		newNode->next = NULL;
		tail = newNode;			//tailʼ��ָ����������һ���ڵ�

	}

	return head;
}

/*
	��������ĳ���
*/
void LinkLenth(List L)
{
	int lt = 0;
	
	List tempGet = L->next;
	
	while(tempGet)		//tempGet ΪNULLʱ����
	{
		tempGet = tempGet->next;
		lt++;
	}

	printf("����ĳ���Ϊ��%d\n",lt);
}

/*
	���ң�������Ӧ������
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
	����ڵ�
*/
bool Insert(List L,int value,Position p)
{
	
	Position tem,pre;
	
	//�ҵ����봦�Ľڵ��ǰһ���ڵ㣬��pre��ŵ�ַ  //Ĭ����ͷ���
	for(pre=L;pre&&pre->next != p;pre=pre->next);

	if(pre == NULL || p ==NULL)   //Ĭ����β�ڵ�
	{
		printf("����λ������\n");
		return false;
	}
	else
	{
		tem = (List)malloc(sizeof(struct Node));  //��ʼ��������ݵĽڵ�
		tem->data = value;       
		pre->next = tem;                //���봦��ǰһ���ڵ� �� ������ݵĽڵ�����
		tem->next = p;					//������ݵĽڵ�  �������Ľڵ�����	
		return true;
	}
}

/*
	ɾ���ڵ�
*/

bool Delete(List L,Position p)
{
	
	Position pre;

	//��ȡɾ���ڵ��ǰһ���ڵ�  //Ĭ����ͷ���

	for(pre = L;pre&&pre->next != p;pre = pre->next);

	if(pre ==NULL || p ==NULL) //Ĭ����β�ڵ�
	{
		printf("ɾ��λ�ò�������\n");	
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
   ��ӡ����
*/
void Printf(List L)
{
	List p = L->next;

	printf("��������ݣ�\n");
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