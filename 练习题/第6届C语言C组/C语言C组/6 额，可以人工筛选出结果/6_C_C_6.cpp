/*
	思路，先大致确定以下范围 
	
	一个数 ，
	
	numlen 获取该数的平方、立方 有 几位，
	
	根据 numlen 获取 到各位，并进行判断
	（注意去重判断） 
	 
		
	1234 / 10  = 123
	123 /10 = 12
	12 /10  =  1
	1 /10  = 0
	
	1234 % 10 = 4	
	1234 / 10 % 10 = 3      //  十位     除 10 取余 
	1234 /10 /10 %10 = 2    //   百位    除 100 取余  
	1234 /10 /10 /10 = 1
	
	12  % 10 = 2
	12 /10 = 
	
*/

/*
	要确定； 当使用 double x = pow() 进行 int 强制转换时， x 超出什么范围，就会失去准确性
	
	应当熟练掌握：
	 
	快速判断一个数有多少位的方法
	
	获取一个数的每一位
	
	做题技巧：
	并不一定要设计一个通用的程序来获取答案。
	在数量不多的（尝试下就知道，数量不多了） 情况下，应当考虑 将所有结果列出来，人功筛选也是可以的。 
*/


#include "stdio.h"
#include "math.h"
#include "malloc.h"
#define max 10


 //判断一个数是几位的 
int checkLen(int num){
	int count = 0;
	while(num/10!=0){
		num = num/10;
		count++;
	}
	count++;
	
	return count;
} 

//获取一个数每一位,最终 会获取到 temp 结果集 
void getNum(int num,int numLen,int * temp){
	
	void judgeNum(int num,int * temp);
	judgeNum((num%10),temp);
	
	if(numLen>1){   //
		for(int i = 2;i<numLen;i++){  // 默认i是取 num 的第几位数。 
		printf("test: %d,%d\n",(int)(pow(10,i-1)),num);
			judgeNum( (num/(int)(pow(10,i-1)))%10 , temp ); 
		}
	
		judgeNum((num/(int)pow(10,numLen-1)),temp);  //最后一位 
		 
	} 
	
	
} 

//判断符合要求的个数 
void judgeNum(int num,int * temp){
	//	printf("oj9k,%d\n",num);
	for(int i = 0;i<max;i++){  //sizeof(temp)  == 8, max == 10
	//	printf(",%d\n",i);
		if(i == num&&temp[i]==13){  //确保  平方 和 立方后，不会有记录相同的数字 
			temp[i] = i;
		
		}
	}
	
}


int main(){
	
	//printf("%d,%d\n",pow(),pow());
	/*
	printf("%d\n",checkLen(1));
	printf("%f,%f\n",pow(19,2),pow(19,3));
	printf("%f,%f\n",pow(29,2),pow(29,3));
	printf("%f,%f\n",pow(39,2),pow(39,3));
	*/
	int * result = (int *)malloc(sizeof(int)*max);
	int flag = 1;
	
	

	int tempResult;
	for(int i = 0;i<100;i++){
		//对结果集填充，标记数字 
		for(int j = 0;j<max;j++){
			result[j] = 13;
		}
		printf("%d\n",i);
		for(int i2 = 2;i2<=3;i2++){
			int tempNum;
			if(i2 == 2){
				 tempNum = i*i;
			}
			else{
				 tempNum = i*i*i;	
			}
			
			//printf("i2=%d,%d",i2,tempNum);
			getNum(tempNum,checkLen(tempNum),result); //判断i 
		
			for(int k = 0;k<max;k++){
				if(result[k] == 13){
					flag = 0;
				}
			} 
			printf("\n");
			
			if(flag == 1){
			
				tempResult = i;
				break;
			}
			flag = 1; 
		}
		
	}
		printf("答案：%d,%d,%d\n",tempResult,(tempResult*tempResult),(tempResult*tempResult*tempResult));
	return 0;
}
