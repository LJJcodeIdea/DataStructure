//用选择排序法将数据9，7，8，1，6，5，3从小到大排序．

#include "stdio.h" 
#define MAX 7

void SelectionSort(int nums[],int len){	
	int minPosition;
	
	for(int i = 0;i<len-1;i++){
		minPosition = i;
		for(int j = i;j<len;j++){
				if(nums[minPosition]>nums[j]){
					minPosition = j;
				}
		}
		
		int temp = nums[i];
		nums[i]  = nums[minPosition];
		nums[minPosition] = temp;
	} 
	
	
	for(int i = 0;i<len;i++){
		printf("%d\n",nums[i]);
	}
}


int main(){
	int nums[MAX] = {9,7,8,1,6,5,3};
	SelectionSort(nums,MAX);
	
	return 0;
}
