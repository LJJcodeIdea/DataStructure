//用直接插入排序法将数据9，7，8，1，6，5，3从小到大排序．

#include "stdio.h"
#define MAX 7

void Insert_Sort(int nums[],int len){
	
	for(int i = 1;i<len;i++){
		int temp  =  nums[i];
		for(int j = i;j>=0;j--){
			if(nums[j-1]>temp){
				nums[j] = nums[j-1];
				nums[j-1] = temp;
			}
		}
	}
	
	int len2 = len-1; 
	while(len2>=0){
		printf("%d\n",nums[len2]);
		len2--;
	}
}

int main(){
	int test[MAX] = {9,7,8,1,6,5,3};
	Insert_Sort(test,MAX);
	return 0;
}
