#include <stdio.h> 
#define MAX 9
/*
  对 3 6 5 9 7 1 8 2 4 使用快速排序 
*/

typedef int ElementType;

/*
	交换函数 
*/
void Swap(ElementType * a,ElementType * b){
	ElementType temp = *a;
	*a = *b;
	*b = temp;
	
} 


/*
	取中位数作为主元 
*/
ElementType Median3(ElementType A[],int Left,int Right){
	
	int Center = (Left+Right)/2;
	
	printf("Median中各下标: %d,%d,%d\n",Left,Center,Right);
	if(A[Left] > A[Center]){
		Swap(&A[Left],&A[Center]);
	}
	if(A[Left] > A[Right] ){
		Swap(&A[Left],&A[Right]);
	}
	if(A[Center] > A[Right]){
		Swap(&A[Center],&A[Right]);
	}
	
	//通过上面的三条语句，A[Left] < A[Center] < A[Right],这里直接把 A[Center]与倒数第二位互换。之后第一轮筛选考虑 Left-1 到 Right-3就好了 
	printf("Center: %d,Right: %d\n",Center,Right-1);
	Swap(&A[Center],&A[Right-1]);
	printf("Median各个值: %d,%d,%d\n",A[Left],A[Center],A[Right]);
	
	return Right-1; 
}

void QuickSort(int Left,int Right,int nums[]){
	
	
	if(Right<=Left) return;
	
	int p = Median3(nums,Left,Right);//主元   这个语句一定要放到  if(Right<=Left) return; 语句的后面，因为 当Left==Right==0,的时候，  由于 Median3函数里有  Swap(&A[Center],&A[Right-1]); 语句，会导致值变为0（就是越界后乱给的） 
	
		
		int i = Left;
		int j = Right-1;
		if(j!=i){     //我测试时，发现 右边部分里进行左边部分的快速排序时，当只有一个数时，会出错。 具体原因是 int j = Right - 1,会导致 j 越界（到了不属于它的那部分）  
			printf("p = %d,i = %d,j = %d\n",p,i,j);
			int len = 0;
			while(len<MAX){
				printf("%d\n",nums[len]);
				len++;
			}
	
	
			
			while(1){
				while(nums[++i]<nums[p]);
				while(nums[--j]>nums[p]);
				printf("i = %d,j = %d\n",i,j);
				if(i>j)  break;
				
				Swap(&nums[i],&nums[j]);
			}
	
			Swap(&nums[i],&nums[p]); //将主元放到中间
	
			printf("主元：%d，放主元到中间: ",nums[i]); 
			len = 0;
			while(len<MAX){
				printf("%d ",nums[len]);
				len++;
			}
			printf("\n");
			
			printf("\n【左边：%d,%d,mid下标: %d\n",Left,i-1,i);
			QuickSort(Left,i-1,nums);   //
			printf("\n右边】：Left: %d,Right: %d,mid下标: %d\n",i+1,Right,i);
			QuickSort(i+1,Right,nums);
		}
		 

}

int main(){
	
	int result[MAX] = {3,6,5,9,7,1,8,2,4};
	QuickSort(0,MAX-1,result);
	
	int len = 0;
	while(len<MAX){
		printf("%d\n",result[len]);
		len++;
	}
	return 0;
} 

















