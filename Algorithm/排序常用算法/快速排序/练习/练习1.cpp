#include <stdio.h> 

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
