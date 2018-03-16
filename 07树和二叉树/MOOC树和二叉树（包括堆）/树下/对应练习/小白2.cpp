// testlasst.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#define MaxSize 10000

typedef int ElementType;
typedef int SetName;   //Ĭ��ʹ�ø��ڵ���±���Ϊ���ϵ�����
typedef ElementType SetType[MaxSize];

typedef struct TreeNode * Pre;

/*
�洢����Ľ��
*/
struct TreeNode{
	int temp;
	Pre Next;
};
typedef Pre Node;

/*�����������, һ������㣬һ����ʶ����*/
Node increase(Node Root,int flag){

	Node Tail = Root;

	//Tail->Next = NULL;
	//����һ�����Ϊ��ʱ�������������½��Ľ��
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
	//Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1
	for(;S[X]>=0;X=S[X]);
	return X;
}
*/

//ʹ��·��ѹ��
SetName Find(SetType S,ElementType X){
	
	if(S[X] < 0)  //�ҵ����ϵĸ�
		return X;
	else
		return S[X] = Find(S,S[X]);
}

void Union(SetType S,SetName Root1,SetName Root2)
{
	//Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ��ڵ�
	S[Root2] = Root1;
}

//����̨����������һ��
void Input_connection(SetType S){
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d\n",&u,&v);  //����Ҫ���ӵ���̨����
	Root1 = Find(S,u-1);	//��Ϊ��ӳ�䵽����������Ǵ�0��ʼ���������Ǵ�1��ʼ��š�
	Root2 = Find(S,v-1);
	if(Root1 != Root2) Union(S,Root1,Root2);
}

//�����̨�����Ƿ�������һ��
void Check_connection(SetType S,Node Root){
	ElementType u,v;
	SetName Root1,Root2;
	scanf("%d %d\n",&u,&v);  //����Ҫ���ӵ���̨����
	Root1 = Find(S,u-1);	//��Ϊ��ӳ�䵽����������Ǵ�0��ʼ���������Ǵ�1��ʼ��š�
	Root2 = Find(S,v-1);

	if(Root1 == Root2){
		Root = increase(Root,1);
	}
	else
		Root = increase(Root,2);
}

//����м�����������ע��������һ̨����Ҳ��
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
	Initialization(S,n);  //��ʼ������

	//��ʼ�������
	Node results = (Node)malloc(sizeof(struct TreeNode));
	results->Next = NULL;

	do{
		
		scanf("%c",&in); //����ָ��

		//����ָ��
		switch(in){
			case 'I': Input_connection(S); break;
			case 'C': Check_connection(S,results);break;
			case 'S': Check_network(S,n,results);break;
		}

	}while(in != 'S');



	system("pause");
	return 0;
}

