/*
	临场推导，可能还是要1/2min，不如先强行记下，能暂时一个星期快速应用就好。 
*/

/*
	例子：
	以 1234 这个数字为例：
	
	判断一个数的位数，可以将其不断除10，直到为0时，就除到最大的了。 
	实际上每次除10，就是去掉当前数的最低位。 
	1234 / 10  = 123
	123 /10 = 12
	12 /10  =  1
	1 /10  = 0
	
	1234 % 10 = 4	
	1234 / 10 % 10 = 3      //  十位     除 10 取余 
	1234 /10 /10 %10 = 2    //   百位    除 100 取余  
	1234 /10 /10 /10 = 1 
	
*/

#include "stdio.h"
#include "malloc.h"
#include "math.h"
#include "string.h"
typedef int * RType;
typedef int ElementType;

//判断一个数的位数
int checkLen(int num){
	
	int count = 1; //记录位数
	 
	while(num/10!=0){
		num = num /10;
		count++;
	} 
	
	return count;
} 

//返回各个位 
RType getNum(int num){
	
	int len = checkLen(num); //获取位数 
	
	int * result = (int *)malloc(sizeof(int)*len);  //存放各位数 
	
	int temp;
	
	int ri = 0;
	
	result[0] = num%10;  //个位 
	
	if(len>1){   //至少是要 十位 数， 大于 9 
		
		for(int i = 2;i<len;i++){   //获取，从低位到高位 
			temp = num/((int)pow(10,i-1))%10; 
			ri++;
			result[ri] = temp;
		}
		
		ri++;
		result[ri] = num/((int)pow(10,len-1));
		
	}
	
	return result;
} 

int main(){
	int test = 1122334455;
	int * result = getNum(test);
	
	for(int i = 0;i<checkLen(test);i++){
		printf("%d ",result[i]);
	}
	printf("\n");
	
	printf("%d的位数：%d\n",test,checkLen(test));
	return 0;
} 





