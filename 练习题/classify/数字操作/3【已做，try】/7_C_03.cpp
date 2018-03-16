#include <stdio.h>
#include <math.h>
int main(void){
	
	int temp;
	int i = 123;
	temp = i;
	
	do{
		if(10<=i && i<=99){
			i = (int)pow((i/10),2) + (int)pow((i%10),2);
		}
		else if(i<10){
			i = (int)pow(i,2);
		}
		else if(i<=999 && i>=100){
			i = (int)pow((i/100),2) + (int)pow((i/100%10),2) +  (int)pow((i%10),2);
		}
		printf("%d\n",i);
	}
	while(i != temp && i != 1);

	return 0;
}