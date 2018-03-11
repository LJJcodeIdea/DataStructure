#include "stdio.h" 

int findMax(int result){
	int max = result; //存放最大的数，初始为输入的数	
	
	while(result!=1){
	//	printf("%d\n",result);
		if(result*1.0/2==result/2){
			result=result/2;
		}
		else{
			result=result*3+1;
		}	
		
		if(result>max){
			max = result;
		}	
	}
	
	return max;
}

int main(){
	
	int result;
	scanf("%d",&result); 
	int max = result;
	int tempMax;
	for(int i = result;i>0;i--){
		
		tempMax = findMax(i);
		if(max<tempMax){
			max = tempMax;
		}
	}
	
	printf("%d\n",max);
	
	return 0;
}
