#include "stdlib.h"

#include <stdio.h>
#include <malloc.h>

#define HEIGHT(P) ( (P==NULL)?0:(P->height) )
#define MAX(a,b) ( (a)>(b) ? (a) : (b) )

//�ڵ� ����

typedef struct TreeNode * Node;
struct TreeNode
{
	int data;
	int height;
	Node Left,Right;

};
typedef Node Tree;

int number = 0;
int fff = 0;
//2�������в���Ԫ��,
void Insert(Tree T,Node newNode)
{
	if( (newNode->data < T->data) && (T->Left == NULL) ) T->Left = newNode;
	else if( (newNode->data < T->data) && (T->Left != NULL) ) Insert(T->Left,newNode);	
	else if( (newNode->data > T->data) && (T->Right == NULL)) T->Right = newNode;
	else Insert(T->Right,newNode);

	T->height = MAX(HEIGHT(T->Left),HEIGHT(T->Right)) + 1;
//	fff =  MAX(HEIGHT(T->Left),HEIGHT(T->Right));
//	printf("%d\n",fff);


}

/*
	��ת����

*/

static Tree left_left_rotation(Tree k2)
{
    Tree  k1;

    k1 = k2->Left;
    k2->Left = k1->Right;
    k1->Right = k2;

    k2->height = MAX( HEIGHT(k2->Left), HEIGHT(k2->Right)) + 1;
    k1->height = MAX( HEIGHT(k1->Left), k2->height) + 1;

    return k1;
}

static Tree right_right_rotation(Tree k1)
{
    Tree k2;

    k2 = k1->Right;
    k1->Right = k2->Left;
    k2->Left = k1;

    k1->height = MAX( HEIGHT(k1->Left), HEIGHT(k1->Right)) + 1;
    k2->height = MAX( HEIGHT(k2->Right), k1->height) + 1;

    return k2;
}

static Tree left_right_rotation(Tree k3)
{
    k3->Left = right_right_rotation(k3->Left);

    return left_left_rotation(k3);
}

static Tree right_left_rotation(Tree k1)
{
    k1->Right = left_left_rotation(k1->Right);

    return right_right_rotation(k1);
}

Tree Check(Tree T)
{
	//if(T->Left == NULL && T->Right == NULL) return T; 

	

		if(T->Left != NULL) Check(T->Left);


    	if (HEIGHT(T->Left) - HEIGHT(T->Right) == 2)
        {
            if (T->Left->Left->data < T->Left->data)
                T = left_left_rotation(T);
            else
                T = left_right_rotation(T);
        }
		if (HEIGHT(T->Right) - HEIGHT(T->Left) == 2)
        {
            if (T->Right->Right->data > T->Right->data)
                T = right_right_rotation(T);
            else
                T = right_left_rotation(T);
        }	


		if(T->Right != NULL) Check(T->Right);
		

		

		return T;
}



//1�����ݵ����벢������
Tree newTree(Tree T)
{
	int i,N,temp;

	scanf("%d\n",&N);	//ȷ�������ж��ٸ��ڵ�
	
	//������������
	if(N>0)
	{
		scanf("%d",&temp);
	
		T = (Tree)malloc(sizeof(struct TreeNode)); //��ʼ�������
		T->data = temp;
		T->height = 1;
		T->Left = T->Right = NULL;
	}
	else T = NULL;   

	int t = 0;
	for(i = 1;i < N;i++) //ֻ��һ���ڵ�ʱ��N==1���ǲ���ִ�����ѭ���ġ�
	{
		scanf("%d",&temp);
		Node newNode = (Node)malloc(sizeof(struct TreeNode));	//Ҫ����Ľ��
		newNode->data = temp;							//��ֵ
		newNode->height = 1;
		newNode->Left = newNode->Right = NULL;
	    Insert(T,newNode);								//�����в�����
		T=Check(T);  //�жϲ����������Ƿ�ΪAVL����������Ƿ���ת��ΪAVL�������ĸ����
	
	}




	return T;	//���ص���AVL���ĸ����

}

//���ԣ�����
void PrintfNum(Tree T)
{

	if(T->Left != NULL) PrintfNum(T->Left);
    //if(T->Left == NULL) printf("%d\n",T->data);
	printf("%d/////%d\n",T->data,T->height);
	if(T->Right != NULL) PrintfNum(T->Right);
	//if(T->Right == NULL) printf("%d\n",T->data);
}

int main()
{
	Tree T;
	T = newTree(T);	//������

	Tree temp = T;
	
//	PrintfNum(T);

	printf("%d\n",temp->data);
	system("pause");
	return 0;
}

