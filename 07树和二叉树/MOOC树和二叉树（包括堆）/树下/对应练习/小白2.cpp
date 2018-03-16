// testlasst.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#define MaxSize 10000

typedef int ElementType;
typedef int SetName;   //默认使用根节点的下标作为集合的名称
typedef ElementType SetType[MaxSize];

typedef struct TreeNode * Pre;

/*
存储结果的结点
*/
struct TreeNode{
	int temp;
	Pre Next;
};
typedef Pre Node;

/*结果集的增长, 一个根结点，一个标识数字*/
Node increase(Node Root,int flag){

	Node Tail = Root;

	//Tail->Next = NULL;
	//但下一个结点为空时，跳出，连上新建的结点
	while(Tail->Next){

		Tail = Tail->Next;
	}

	Node newNode = (Node)malloc(sizeof(struct TreeNode));
	newNode->temp = flag;
	newNode->Next = NULL;
	Tail->Next = newNode;

	return Root;
}

void Initialization(SetType S,ElementType e){
	int i;
	for(i = 0;i<e;i++){
		S[i] = -1;
	}
	
}
/*
SetName Find(SetType S,ElementType X){
	//默认集合元素全部初始化为-1
	for(;S[X]>=0;X=S[X]);
	return X;
}
*/

//使用路径压缩
SetName Find(SetType S,ElementType X){
	
	if(S[X] < 0)  //找到集合的根
		return X;
	else
		return S[X] = Find(S,S[X]);
}

void Union(SetType S,SetName Root1,SetName Root2)
{
	//默认Root1和Root2是不同集合的根节点
	S[Root2] = Root1;
}

//将两台机器连接在一起
void Input_connection(SetType S){
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d\n",&u,&v);  //输入要连接的两台机器
	Root1 = Find(S,u-1);	//因为是映射到数组里，数组是从0开始。而集合是从1开始编号。
	Root2 = Find(S,v-1);
	if(Root1 != Root2) Union(S,Root1,Root2);
}

//检查两台机器是否连接在一起
void Check_connection(SetType S,Node Root){
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d\n",&u,&v);  //输入要连接的两台机器
	Root1 = Find(S,u-1);	//因为是映射到数组里，数组是从0开始。而集合是从1开始编号。
	Root2 = Find(S,v-1);

	if(Root1 == Root2){
		Root = increase(Root,1);
	}
	else
		Root = increase(Root,2);
}

//检查有几个局域网，注：单独的一台电脑也算
void Check_network(SetType S,int n,Node results){
	int i,counter = 0;
	for(i = 0;i<n;i++){
		if(S[i]<0) counter++;
	}

	

	Node tempNode = results->Next;

	while(tempNode){
		if(tempNode->temp == 1){
			printf("yes\n");
		}
		else if(tempNode->temp == 2){
			printf("no\n");
		}
		tempNode = tempNode->Next;
	}

	if(counter == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n",counter);
}



int main()
{
	SetType S;
	int n;
	char in;
	scanf("%d\n",&n);
	Initialization(S,n);  //初始化集合

	//初始化结果集
	Node results = (Node)malloc(sizeof(struct TreeNode));
	results->Next = NULL;

	do{
		
		scanf("%c",&in); //读入指令

		//处理指令
		switch(in){
			case 'I': Input_connection(S); break;
			case 'C': Check_connection(S,results);break;
			case 'S': Check_network(S,n,results);break;
		}

	}while(in != 'S');



	system("pause");
	return 0;
}

