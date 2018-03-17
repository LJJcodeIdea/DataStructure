//参考：WIKI

//选一个数字作为衡量的标尺，比它小的放在它的左边，比它大的放在它的右边 

#include "stdio.h" 

//两数交换 
void swap(int * x,int * y){
	int t = *x;
	*x = *y;
	*y = t;
}

void quick_sort_recursive(int arr[],int start,int end){
	if(start >= end) return;  //确保 进行排序的总的数字有2个 或 2个以上。len>=2;
	
	int mid = arr[end] ;  //将最后一个数作为 基准数 
	int left = start,right = end - 1; // 左、右 " 指针 "	
	
	//left < right， 就是说，当要进行划分的成两部分的时候，要划分的数只有一个，那就不用执行了。 只有的if条件语句会解决的 
	while(left < right){  //并确保在当前组内执行 
		//下面每个while语句都有 left<right 条件，就是判断 左右两边基本划分完，这里的设置，最终弄left和right都指向同一位置 
		while(arr[left] < mid && left<right)  left++;
		while(arr[right] >= mid && left<right) right--;
		
		swap(&arr[left],&arr[right]); //将左边不符合要求的 和 右边不符合要求的 进行交换 
	}	
	
	//下面if语句的作用 
	//作用1：由于上面的条件是限制了，不对总的数字只有2个的进行排序，这里就是解决了，要划分的数只有一个时，进行合理的调换 
	//作用3：处理下面else说到的问题 
	if(arr[left]>=arr[end]){  
		swap(&arr[left],&arr[end]); //作用2：有那么一种可能，要划分的数的总数为奇数，而最终left和right都指向向了中间的数，而这个数实际上没有跟arr[end] 进行比较。还有一种可能，一开始左边的部分就是都比 基准数小，left最终指向right所在的位置，而right并没有和 基准数 进行过比较 
	}
	else //假如都指向中间的那个数 ，是比 基准数小，那么left向右移 。那么现在右移后的left如果比arr[end]大呢？那就在 右边那部分进行划分时，前面的if语句不就解决了~ 
		left++;
	//对分出来的子集，继续进行快速排序	 
	if(left){  //这是防止越界的一个设置了，下面不是有 left-1吗，【没验证。 
		quick_sort_recursive(arr,start,left-1);
	}
	quick_sort_recursive(arr,left+1,end) ;
		
} 

void quick_sort(int arr[], int len){
	quick_sort_recursive(arr,0,len-1);
} 

int main(){
	int num[9] = {3,6,5,9,7,1,8,2,4};
	quick_sort(num,9);
	for(int i = 0;i<9;i++){
		printf("%d\n",num[i]);
	}
	return 0;
}
















