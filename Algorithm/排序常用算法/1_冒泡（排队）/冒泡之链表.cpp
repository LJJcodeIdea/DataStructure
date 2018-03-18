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
<<<<<<< HEAD
void sort(List L,int len){
	
	int i,j;
	
	for(i = 0;i<len-1;i++){
		List temp = L->next;  //开始比较的节点 
	List before = L;     //开始比较节点的上一个节点 
		for(j = 0;j<len-1-i;j++){
			
			if(temp->data > temp->next->data){
				printf("%d,%d\n",temp->data,temp->next->data); 
				List temp2 = (List)malloc(sizeof(struct Node));
=======
void sort(List L){
	int len = ListLen(L);
	List first;
	List before;
	int i,j;
	
	for(i = 0;i<len-1;i++){
		//每次比较前，要确保开始时，first是第一个节点，而before是头结点 
		first = L->next;
		before = L; 
		for(j = 0;j<len-1-i;j++){
			if(first->data > first->next->data){
>>>>>>> 462c3ff65c2fc0ebbd29df66799f00063399fcca
				
					before->next = first->next;  // 
					first->next = first->next->next;
					before->next->next = first;
					
			}
			before = before->next; //befroe 变为下一节点 
			first = before->next;  //first 是 berfore 的下一个结点 
		} 
	}
} 

int main(){
	
	int result[MAX] =  {9,7,8,1,6,5,3};
	
	//创建链表
	List l = initList(result,MAX);

	//冒泡排序
	sort(l);
	//打印结果 
<<<<<<< HEAD
		
	List temp = l->next;
	while(temp){
		printf("%d\n",temp->data);
		temp = temp->next;
=======
	List tempe = l->next;
	while(tempe){
		printf("%d\n",tempe->data);
		tempe = tempe->next;
>>>>>>> 462c3ff65c2fc0ebbd29df66799f00063399fcca
	}
	return 0;
} 
















