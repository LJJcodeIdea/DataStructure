/*
 x开始的年龄数，
 一共236颗蜡烛，
 
 x = 26
 
 枚举法。 
*/
#include <stdio.h> 
int main(void) {
		
	int i = 0;
	int j;
	int temp = 0;
	
	for(i = 0;i<=99;i++){
		temp = 0;
		for(j = i;j<=99;j++){
			temp += j;
			if(temp==236){
				printf("%d\n",i);
				i = 99;
			}
		}
	}
	
	temp = 0;
	for(i = 26;i<=33;i++){
		
		temp += i;
		
	}
	
	printf("%d\n",temp);
	
	return 0;
}
