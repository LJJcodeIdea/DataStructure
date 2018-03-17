#include <stdio.h> 
#define MAX 9
/*
  �� 3 6 5 9 7 1 8 2 4 ʹ�ÿ������� 
*/

typedef int ElementType;

/*
	�������� 
*/
void Swap(ElementType * a,ElementType * b){
	ElementType temp = *a;
	*a = *b;
	*b = temp;
	
} 


/*
	ȡ��λ����Ϊ��Ԫ 
*/
ElementType Median3(ElementType A[],int Left,int Right){
	
	int Center = (Left+Right)/2;
	
	printf("Median�и��±�: %d,%d,%d\n",Left,Center,Right);
	if(A[Left] > A[Center]){
		Swap(&A[Left],&A[Center]);
	}
	if(A[Left] > A[Right] ){
		Swap(&A[Left],&A[Right]);
	}
	if(A[Center] > A[Right]){
		Swap(&A[Center],&A[Right]);
	}
	
	//ͨ�������������䣬A[Left] < A[Center] < A[Right],����ֱ�Ӱ� A[Center]�뵹���ڶ�λ������֮���һ��ɸѡ���� Left-1 �� Right-3�ͺ��� 
	printf("Center: %d,Right: %d\n",Center,Right-1);
	Swap(&A[Center],&A[Right-1]);
	printf("Median����ֵ: %d,%d,%d\n",A[Left],A[Center],A[Right]);
	
	return Right-1; 
}

void QuickSort(int Left,int Right,int nums[]){
	
	
	if(Right<=Left) return;
	
	int p = Median3(nums,Left,Right);//��Ԫ   ������һ��Ҫ�ŵ�  if(Right<=Left) return; ���ĺ��棬��Ϊ ��Left==Right==0,��ʱ��  ���� Median3��������  Swap(&A[Center],&A[Right-1]); ��䣬�ᵼ��ֵ��Ϊ0������Խ����Ҹ��ģ� 
	
		
		int i = Left;
		int j = Right-1;
		if(j!=i){     //�Ҳ���ʱ������ �ұ߲����������߲��ֵĿ�������ʱ����ֻ��һ����ʱ������� ����ԭ���� int j = Right - 1,�ᵼ�� j Խ�磨���˲����������ǲ��֣�  
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
	
			Swap(&nums[i],&nums[p]); //����Ԫ�ŵ��м�
	
			printf("��Ԫ��%d������Ԫ���м�: ",nums[i]); 
			len = 0;
			while(len<MAX){
				printf("%d ",nums[len]);
				len++;
			}
			printf("\n");
			
			printf("\n����ߣ�%d,%d,mid�±�: %d\n",Left,i-1,i);
			QuickSort(Left,i-1,nums);   //
			printf("\n�ұߡ���Left: %d,Right: %d,mid�±�: %d\n",i+1,Right,i);
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

















