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
void sort(List L,int len){
	List temp = L->next;
	List before = L;
	int i,j;
	
	for(i = 0;i<len-1;i++){
		for(j = 0;j<len-1-i;j++){
			
			if(temp->data > temp->next->data){
				List temp2 = (List)malloc(sizeof(struct Node));
				
					temp2 = temp->next; //�ݴ� �ڶ����� 
					temp->next = temp->next->next; //��һ����nextָ��������� 
					temp2->next = temp;  //�ڶ���  ָ���һ���� 
					before->next = temp2;  //��һ������ ǰһ���� ָ��ڶ����� 
			}
			before = temp;
			temp = temp->next;
		}
	}
} 

int main(){
	
	int result[MAX] =  {9,7,8,1,6,5,3};
	
	//��������
	List l = initList(result,MAX);
	//ð������
	sort(l,MAX);
	//��ӡ��� 
	List temp = l->next;
	while(temp){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	return 0;
} 
















