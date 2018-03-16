//用冒泡排序法将数据9，7，8，1，6，5，3从小到大排序．

#include "stdio.h" 
#include "malloc.h"
#define MAX 7
typedef int ElementType;
typedef struct Node * PtrToNode;

struct Node{
	ElementType data;
	PtrToNode next;
};
typedef PtrToNode List;

//创建链表（头尾不存放内容） 
PtrToNode initList(ElementType nums[],int len){    //内容，链表长度 
	
	//1、链表的头、尾，尾始终指向最后一个元素
	List head = (List) malloc(sizeof(struct Node)); 
	head->next = NULL;
	List tail = head;
	
	//2、向链表插入结点
	for(int i = 0;i<len;i++){
		
		PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
		
		newNode->data = nums[i];
		newNode->next = NULL;
		
		tail->next = newNode;
		tail = newNode;
	}
	
	return head;
} 


//返回链表的长度
int ListLen(List L){
	int len = 0;
	
	List temp = L->next;
	
	while(temp){ //temp不为NULL 
		len++;
		temp = temp->next;
	}
	
	return len;
} 

//冒泡排序：
void sort(List L,int len){
	List temp = L->next;
	List before = L;
	int i,j;
	
	for(i = 0;i<len-1;i++){
		for(j = 0;j<len-1-i;j++){
			
			if(temp->data > temp->next->data){
				List temp2 = (List)malloc(sizeof(struct Node));
				
					temp2 = temp->next; //暂存 第二个数 
					temp->next = temp->next->next; //第一个数next指向第三个数 
					temp2->next = temp;  //第二个  指向第一个数 
					before->next = temp2;  //第一个数的 前一个数 指向第二个数 
			}
			before = temp;
			temp = temp->next;
		}
	}
} 

int main(){
	
	int result[MAX] =  {9,7,8,1,6,5,3};
	
	//创建链表
	List l = initList(result,MAX);
	//冒泡排序
	sort(l,MAX);
	//打印结果 
	List temp = l->next;
	while(temp){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	return 0;
} 
















