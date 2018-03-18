#include "stdio.h"

int  main(){
	
	int num[3][3] = {0};
	int check[9] = {0};
	int temp;
	int i,j,k,l=0;
	for(i = 0;i<3;i++){
		
		for(j = 0;j<3;j++){
			
			scanf("%d",&num[i][j]);
			if(num[i][j] != 0){
				check[k] = num[i][j];
				k++;
			}
			
		}
		
	}
	
	

	/*
		l
	*/
	
	
	
	for(i = 0;i<3;i++){
		
		for(j = 0;j<3;j++){
			 
			printf("%d ",num[i][j]);
				
		}
		printf("\n");
	}
	
	return 0;
}
