#include <stdio.h>
#include <malloc.h>

typedef struct Node * Pre;
struct Node 
{
	int data;
	Pre Next;
};
typedef  Pre Thenode;

void test(Pre Tail)			// �ӽ���ɿ�����Tail��temp��head����ָ��ͬһ��ռ䡣
{
	Thenode temp = Tail;

	free(temp);
}

int main()
{
	Thenode head = (Thenode)malloc(sizeof(struct Node));

	head->data = 10;

	test(head);

	printf("%d\n",head->data);

	return 0;
}
