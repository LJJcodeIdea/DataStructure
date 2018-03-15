/*
	�ٳ��Ƶ������ܻ���Ҫ1/2min��������ǿ�м��£�����ʱһ�����ڿ���Ӧ�þͺá� 
*/

/*
	���ӣ�
	�� 1234 �������Ϊ����
	
	�ж�һ������λ�������Խ��䲻�ϳ�10��ֱ��Ϊ0ʱ���ͳ��������ˡ� 
	ʵ����ÿ�γ�10������ȥ����ǰ�������λ�� 
	1234 / 10  = 123
	123 /10 = 12
	12 /10  =  1
	1 /10  = 0
	
	1234 % 10 = 4	
	1234 / 10 % 10 = 3      //  ʮλ     �� 10 ȡ�� 
	1234 /10 /10 %10 = 2    //   ��λ    �� 100 ȡ��  
	1234 /10 /10 /10 = 1 
	
*/

#include "stdio.h"
#include "malloc.h"
#include "math.h"
#include "string.h"
typedef int * RType;
typedef int ElementType;

//�ж�һ������λ��
int checkLen(int num){
	
	int count = 1; //��¼λ��
	 
	while(num/10!=0){
		num = num /10;
		count++;
	} 
	
	return count;
} 

//���ظ���λ 
RType getNum(int num){
	
	int len = checkLen(num); //��ȡλ�� 
	
	int * result = (int *)malloc(sizeof(int)*len);  //��Ÿ�λ�� 
	
	int temp;
	
	int ri = 0;
	
	result[0] = num%10;  //��λ 
	
	if(len>1){   //������Ҫ ʮλ ���� ���� 9 
		
		for(int i = 2;i<len;i++){   //��ȡ���ӵ�λ����λ 
			temp = num/((int)pow(10,i-1))%10; 
			ri++;
			result[ri] = temp;
		}
		
		ri++;
		result[ri] = num/((int)pow(10,len-1));
		
	}
	
	return result;
} 

int main(){
	int test = 1122334455;
	int * result = getNum(test);
	
	for(int i = 0;i<checkLen(test);i++){
		printf("%d ",result[i]);
	}
	printf("\n");
	
	printf("%d��λ����%d\n",test,checkLen(test));
	return 0;
} 





