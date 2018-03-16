#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */
void InorderTraversal( BinTree BT );  /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */

BinTree Insert(BinTree BST,ElementType X)
{
	if(!BST){
		//��ԭ��Ϊ�գ����ɲ�����һ���ڵ�Ķ���������
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}else	//��ʼ��Ҫ�����Ԫ��
		if(X < BST->Data)
			BST->Left = Insert(BST->Left,X);	//�ݹ����������
		else if(X > BST->Data)
			BST->Right = Insert(BST->Right,X);  //�ݹ����������
	
	// else X�Ѿ����ڣ�ʲô������
	return BST;
}

//ɾ���������ڵ�Ĵ���
BinTree Delete(BinTree BST,ElementType X)
{
	Position Tmp;
	if(!BST) printf("Not Found\n");	
	else if(X < BST->Data)
		BST->Left = Delete(BST->Left,X);  //�������ݹ�ɾ��
	else if(X > BST->Data)
		BST->Right = Delete(BST->Right,X);  //�������ݹ�ɾ��
	else	//��Ҫɾ���Ľ��
		if(BST->Left && BST->Right){	//��ɾ���Ľ�������������ӽڵ�
			Tmp = FindMin(BST->Right);	//��������������С��Ԫ�����ɾ�����
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Right,BST->Data);
		}else{  //��ɾ���ڵ���һ�������ӽڵ�
			Tmp = BST;
			if(!BST->Left)		//���Һ��ӻ����ӽڵ�
				BST = BST->Right;
			else if(!BST->Right)	//�����ӻ����ӽڵ�
				BST = BST->Left;
			free(Tmp);
		}

	return BST;

}

Position Find(BinTree BST,ElementType X)
{
	while(BST)
	{
		if(X > BST->Data)
			BST = BST->Right;	//�����������ƶ�����������
		else if(X < BST->Data)
			BST = BST->Left;   //�����������ƶ�����������
		else
			return BST;  //���ҳɹ������ؽڵ���ҵ��Ľڵ�ĵ�ַ

	}

	return NULL; //����ʧ��
}

//������С
Position FindMin(BinTree BST)
{
	if(!BST) return NULL; //�յĶ���������������NULL
	else if(!BST->Left)
		return BST;  //�ҵ�����Ҷ�ڵ㲢����
	else
		return FindMin(BST->Left); //�����֧��������

}

//�������
Position FindMax(BinTree BST)
{
	if(BST)
		while(BST->Right) BST = BST->Right;  //���ҷ�֧�������ң��鵽����Ҷ�ڵ�

	return BST;
}
