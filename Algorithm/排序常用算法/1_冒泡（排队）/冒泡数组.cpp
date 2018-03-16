//用冒泡排序法将数据9，7，8，1，6，5，3从小到大排序． 
//参考：WIKI 
#include "stdio.h" 
#define MAX 7
int main(){
	
	int nums[MAX] = {9,7,8,1,6,5,3};
	
	for(int i = 0;i<MAX-1;i++){
		for(int j = 0;j<MAX-1;j++){ //优化：在该层循环结束后，最大的数会有序的放到后面 。所以这里每次在无序区进行排序就好。循环条件可为：MAX-1=i
			//相邻的比较				
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
