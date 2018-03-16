#include <stdio.h>

int main(void){
	int i;
	int num;
	int temp = 1;
	num = temp;
	for(i = 2;i<=100;i++){
		
		temp = (i*i) - temp;
		num+=temp;
	}

	printf("%d\n",num);

	return 0;
}