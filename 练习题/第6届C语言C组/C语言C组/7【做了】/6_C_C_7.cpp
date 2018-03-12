#include "stdio.h" 

int main(){
	
	int num = 0;
	
	for(int i = 1;i<49;i++){  //姑且 认为  i 就是 要提交的答案， 
		
		for(int j = i+2;j<49;j++){  //j就是 另一 乘法要靠前的， j ！= i, j != i+1,j != i-1 
			
			
			//	printf("%d,%d\n",i,j);
				num = 0;
				for(int k = 1;k<=49;k++){  //k
				
					if(k == i-1){
						num = num + i*(i+1) + k;
						k = k+2;
					} 
					else if(k == j-1){
						num = num + j*(j+1) + k;
						k = k+2;
					}
					else{
						num = num + k;
					}
					
					if(k==49&&num == 2015){
						printf("%d,%d,%d,%d\n",num,i,j,k);
					}
					
				}	
			
			
			
		} 
		num = num + i;
		
	}
	
	printf("%d\n",num);
	
	return 0;
}
