/*
立方尾不变

有些数字的立方的末尾正好是该数字本身。
比如：1,4,5,6,9,24,25,....

请你计算一下，在10000以内的数字中（指该数字，并非它立方后的数值），符合这个特征的正整数一共有多少个。

请提交该整数，不要填写任何多余的内容。

结果是  36，下面的程序是没问题的，有问题的是 dev-C++ 编辑器。换个编译器的。 （线上 c 语言编译器测试） 
*/

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
		
		Temp = (long long)pow(i,3);
		
		if(i>0&&i<10){
			//printf("i = %d,%d,%lf\n",i,(Temp%10),pow(i,3));
			if(i==Temp%10){
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















