/*
  答案是不是 7？ 
*/
#include <stdio.h> 
int main(void){
	
	int a;
	int temp = 0;
	
	for(a=28;a<=99;a++){
		
		if(a- ((a%10)*10 + (a/10)) == 27){
			printf("%d\n",a);
			temp++;
		}
		
	}
	
	printf("%d\n",temp);
	
	return 0;
}

