////��ѡ�����򷨽�����9��7��8��1��6��5��3��С��������

#include "stdio.h"

void Selection_Sort(int A[],int N){
	for(int i=0;i<N;i++){

		int MinPosition = i;  //���ڼ�¼��СԪ��λ�� 
		
		//��A[i]��A[N-1] ������СԪ��������λ�ø���MinPosition 
		for(int j=i;j<N;j++){
			if(A[j]<A[MinPosition]){
				MinPosition = j;
			}
		}
		
		//��δ���򲿷ֵ���СԪ�������򲿷ֵ����λ��(����i) 
		int temp = A[i];
		A[i] = A[MinPosition];
		A[MinPosition] = temp;
		
	}
	
	for(int k = 0;k<N;k++){
		printf("%d\n",A[k]);
	}
}

int main(){
	int A[7] = {9,7,8,1,6,5,3};
	Selection_Sort(A,7);
	return 0;
}
