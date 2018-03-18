//用直接插入排序法将数据9，7，8，1，6，5，3从小到大排序．

#include <stdio.h> 

void Insertion_Sort(int num[],int N){
	
	int temp;
	
	for(int i  = 1;i<N;i++){
		temp = num[i];  //temp就相当于用于临时存储的变量 
		for(int j = i;j>0&&num[j-1]>temp;j--){  //j>0,限制了j等于0时，不会执行  该语句  num[j-1]>temp 
			num[j] = num[j-1];
			num[j-1] = temp;
		}	
	}
	
	for(int k = 0;k<N;k++){
		printf("  %d",num[k]);
	}
	printf("\n");
	
}

int main(){
	
	int num[7] = {9,7,8,1,6,5,3};
	
	Insertion_Sort(num,7);
		
	return 0;
}
