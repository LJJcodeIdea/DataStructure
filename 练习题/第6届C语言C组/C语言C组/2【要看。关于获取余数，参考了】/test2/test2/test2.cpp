// test2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "stdio.h"
#include "math.h"

int main(){
	
	int temp = 1123123;

	printf("%d\n",(temp%100));
	/*
	//看来是无法输出这么大的数了 
	printf("%ld",pow(10000,3));
	*/ 
	
	long long Temp; //用于存储 立方后的数字 
	int i,s;
	int count = 0; //存储多少个符合要求的 
	
	for(i=1;i<10000;i++){
		
		Temp = (long double)pow(i,3);
		
		if(i>0&&i<10){
			printf("i = %d,%d,%lf\n",i,(Temp%10),pow(i,3));
			if(i==s%10){
				printf("%d,%d\n",i,Temp%10);
				count++;
			}
		}
		
		if(i>=10&&i<100){
			if(i==Temp%100){
				printf("%d,%d\n",i,Temp%100);
				count++;
			}
		}
		
		if(i>=100&&i<1000){
			if(i==Temp%1000){
				printf("%d,%d\n",i,Temp%1000);
				count++;
			}
		}
		
		if(i>=1000&&i<10000){
			if(i==Temp%10000){
				printf("%d,%d\n",i,Temp%10000);
				count++;
			}
		}
		

	}
	
	printf("结果：%d\n",count);
	return 0;
}




