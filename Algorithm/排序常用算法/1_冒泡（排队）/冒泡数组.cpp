//��ð�����򷨽�����9��7��8��1��6��5��3��С�������� 
//�ο���WIKI 
#include "stdio.h" 
#define MAX 7
int main(){
	
	int nums[MAX] = {9,7,8,1,6,5,3};
	
	for(int i = 0;i<MAX-1;i++){
		for(int j = 0;j<MAX-1;j++){ //�Ż����ڸò�ѭ��������������������ķŵ����� ����������ÿ������������������ͺá�ѭ��������Ϊ��MAX-1=i
			//���ڵıȽ�				
			if(nums[j+1]<nums[j]){
				int temp = nums[j+1];
				nums[j+1] = nums[j];
				nums[j] = temp;
			} 
			
		}
	}
	
	for(int j = 0;j<MAX;j++){
		printf("%d\n",nums[j]);
	}
	return 0;
}
