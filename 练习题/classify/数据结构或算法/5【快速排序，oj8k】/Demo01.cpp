#include <stdio.h> 

void swap(int a[],int i,int j){
	int t = a[j];
	a[j] = a[i];
	a[i] = t;
}

int partition(int a[],int p,int r){
	int i = p;     //左指针 
	int j = r + 1;  //右指针 
	int x = a[p];   //用 开头的元素 作为 pivot
	
	while(1){
		while(i<r && a[++i]<x);
		while(a[--j]>x);
		if(i>=j) break;  //当前左、右子集筛选，并处理得符合要求完 
		swap(a,i,j);   
	} 
	
	swap(a,p,j);  //将 主元 放到中间 
	
	return j;
}

void quicksort(int a[],int p,int r){
	if(p<r){  //保证，个数不少于两个 
		int q = partition(a,p,r); 
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
} 

int main()
{
	int i;
	int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
	int N = 12;
	
	quicksort(a, 0, N-1);
	
	for(i=0; i<N; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}

