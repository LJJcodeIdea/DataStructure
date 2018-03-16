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

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

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
/* 你的代码将被嵌在这里 */

BinTree Insert(BinTree BST,ElementType X)
{
	if(!BST){
		//若原树为空，生成并返回一个节点的二叉搜索树
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}else	//开始找要插入的元素
		if(X < BST->Data)
			BST->Left = Insert(BST->Left,X);	//递归插入左子树
		else if(X > BST->Data)
			BST->Right = Insert(BST->Right,X);  //递归插入右子树
	
	// else X已经存在，什么都不做
	return BST;
}

//删除二叉树节点的代码
BinTree Delete(BinTree BST,ElementType X)
{
	Position Tmp;
	if(!BST) printf("Not Found\n");	
	else if(X < BST->Data)
		BST->Left = Delete(BST->Left,X);  //左子树递归删除
	else if(X > BST->Data)
		BST->Right = Delete(BST->Right,X);  //右子树递归删除
	else	//找要删除的结点
		if(BST->Left && BST->Right){	//被删除的结点有左右两个子节点
			Tmp = FindMin(BST->Right);	//在右子树中找最小的元素填充删除结点
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Right,BST->Data);
		}else{  //被删除节点有一个或无子节点
			Tmp = BST;
			if(!BST->Left)		//有右孩子或无子节点
				BST = BST->Right;
			else if(!BST->Right)	//有左孩子或无子节点
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
			BST = BST->Right;	//向右子树中移动，继续查找
		else if(X < BST->Data)
			BST = BST->Left;   //向左子树中移动，继续查找
		else
			return BST;  //查找成功，返回节点的找到的节点的地址

	}

	return NULL; //查找失败
}

//查找最小
Position FindMin(BinTree BST)
{
	if(!BST) return NULL; //空的二叉搜索树，返回NULL
	else if(!BST->Left)
		return BST;  //找到最左叶节点并返回
	else
		return FindMin(BST->Left); //沿左分支继续查找

}

//查找最大
Position FindMax(BinTree BST)
{
	if(BST)
		while(BST->Right) BST = BST->Right;  //沿右分支继续查找，查到最右叶节点

	return BST;
}
