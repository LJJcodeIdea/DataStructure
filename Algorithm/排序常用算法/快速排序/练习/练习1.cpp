#include <stdio.h> 

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
	if(A[Left] > A[Center]){
		Swap(&A[Left],&A[Center]);
	}
	if(A[Left] > A[Right] ){
		Swap(&A[Left],&A[Right]);
	}
	if(A[])
}

int main(void){


	
	return 0;
} 
