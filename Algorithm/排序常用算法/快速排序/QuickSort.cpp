//�ο���WIKI

//ѡһ��������Ϊ�����ı�ߣ�����С�ķ���������ߣ�������ķ��������ұ� 

#include "stdio.h" 

//�������� 
void swap(int * x,int * y){
	int t = *x;
	*x = *y;
	*y = t;
}

void quick_sort_recursive(int arr[],int start,int end){
	if(start >= end) return;  //ȷ�� ����������ܵ�������2�� �� 2�����ϡ�len>=2;
	
	int mid = arr[end] ;  //�����һ������Ϊ ��׼�� 
	int left = start,right = end - 1; // ���� " ָ�� "	
	
	//left < right�� ����˵����Ҫ���л��ֵĳ������ֵ�ʱ��Ҫ���ֵ���ֻ��һ�����ǾͲ���ִ���ˡ� ֻ�е�if������������ 
	while(left < right){  //��ȷ���ڵ�ǰ����ִ�� 
		//����ÿ��while��䶼�� left<right �����������ж� �������߻��������꣬��������ã�����Ūleft��right��ָ��ͬһλ�� 
		while(arr[left] < mid && left<right)  left++;
		while(arr[right] >= mid && left<right) right--;
		
		swap(&arr[left],&arr[right]); //����߲�����Ҫ��� �� �ұ߲�����Ҫ��� ���н��� 
	}	
	
	//����if�������� 
	//����1����������������������ˣ������ܵ�����ֻ��2���Ľ�������������ǽ���ˣ�Ҫ���ֵ���ֻ��һ��ʱ�����к���ĵ��� 
	//����3����������else˵�������� 
	if(arr[left]>=arr[end]){  
		swap(&arr[left],&arr[end]); //����2������ôһ�ֿ��ܣ�Ҫ���ֵ���������Ϊ������������left��right��ָ�������м�������������ʵ����û�и�arr[end] ���бȽϡ�����һ�ֿ��ܣ�һ��ʼ��ߵĲ��־��Ƕ��� ��׼��С��left����ָ��right���ڵ�λ�ã���right��û�к� ��׼�� ���й��Ƚ� 
	}
	else //���綼ָ���м���Ǹ��� ���Ǳ� ��׼��С����ôleft������ ����ô�������ƺ��left�����arr[end]���أ��Ǿ��� �ұ��ǲ��ֽ��л���ʱ��ǰ���if��䲻�ͽ����~ 
		left++;
	//�Էֳ������Ӽ����������п�������	 
	if(left){  //���Ƿ�ֹԽ���һ�������ˣ����治���� left-1�𣬡�û��֤�� 
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
















