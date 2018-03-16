////用选择排序法将数据9，7，8，1，6，5，3从小到大排序．

#include "stdio.h"

void Selection_Sort(int A[],int N){
	for(int i=0;i<N;i++){

		int MinPosition = i;  //用于记录最小元的位置 
		
		//从A[i]到A[N-1] 中找最小元，并将其位置赋给MinPosition 
		for(int j=i;j<N;j++){
			if(A[j]<A[MinPosition]){
				MinPosition = j;
			}
		}
		
		//将未排序部分的最小元换到有序部分的最后位置(就是i) 
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
