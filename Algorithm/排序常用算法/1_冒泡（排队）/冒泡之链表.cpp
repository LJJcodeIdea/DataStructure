//��ð�����򷨽�����9��7��8��1��6��5��3��С��������

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

//��������ͷβ��������ݣ� 
PtrToNode initList(ElementType nums[],int len){    //���ݣ������� 
	
	//1�������ͷ��β��βʼ��ָ�����һ��Ԫ��
	List head = (List) malloc(sizeof(struct Node)); 
	head->next = NULL;
	List tail = head;
	
	//2�������������
	for(int i = 0;i<len;i++){
		
		PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
		
		newNode->data = nums[i];
		newNode->next = NULL;
		
		tail->next = newNode;
		tail = newNode;
	}
	
	return head;
} 


//��������ĳ���
int ListLen(List L){
	int len = 0;
	
	List temp = L->next;
	
	while(temp){ //temp��ΪNULL 
		len++;
		temp = temp->next;
	}
	
	return len;
} 

//ð������
<<<<<<< HEAD
void sort(List L,int len){
	
	int i,j;
	
	for(i = 0;i<len-1;i++){
		List temp = L->next;  //��ʼ�ȽϵĽڵ� 
	List before = L;     //��ʼ�ȽϽڵ����һ���ڵ� 
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
		//ÿ�αȽ�ǰ��Ҫȷ����ʼʱ��first�ǵ�һ���ڵ㣬��before��ͷ��� 
		first = L->next;
		before = L; 
		for(j = 0;j<len-1-i;j++){
			if(first->data > first->next->data){
>>>>>>> 462c3ff65c2fc0ebbd29df66799f00063399fcca
				
					before->next = first->next;  // 
					first->next = first->next->next;
					before->next->next = first;
					
			}
			before = before->next; //befroe ��Ϊ��һ�ڵ� 
			first = before->next;  //first �� berfore ����һ����� 
		} 
	}
} 

int main(){
	
	int result[MAX] =  {9,7,8,1,6,5,3};
	
	//��������
	List l = initList(result,MAX);

	//ð������
	sort(l);
	//��ӡ��� 
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
















