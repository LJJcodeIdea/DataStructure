#include  <stdio.h> 
#include <malloc.h>

/*
	A   1
	
	B   2
	
	Z   26
	
	AA  27
	
	AZ  52   --> 52/26==2  预期 是要得到 1 
	
	BA  53    
	
	BZ  78    --->  78/26 == 3
	
	ZZ  702 
	
	BZZ  2054
	
	
	希望类比进制解决这道题，但毕竟不完全是。
	在遇到Z的情况时，前一位会受到影响。
	想了很久，这是什么导致的还是不懂。 
	还是先把结果做出。
	
	开始时，在通过除26除去一个末位，的前一位进行判定，如果是Z，就标记一下 flag = 1；
	在总位数为2时，还好，但在位数为3，比如BZZ时就会出错，比如说取出B，由于前面有两个Z  2054/26 == 79 [79%26!=0]  79/26 ==3   
	
	嗯，消除了影响 但 ZZZ 时，位数会判断错误。
	
	恐怕是思路有问题。 
	
*/
int main(){
	
	//输入：
	int in;
	scanf("%d",&in); 
	
	//获取位数：
	int count = 1;
	int tempIn = in;

	while(tempIn>26){
		count++;

		tempIn /=  26;
	}
	printf("%d\n",count);

	
	//存放结果
	char * result = (char *)malloc(sizeof(char)*count);
	int tempD; 
	int i,j;	//用于循环 
	int flag = 0; //标记是否要消除影响 
	//取出各个位数
	for(i=1;i<=count;i++){
		//先取出末位
		if(i==1){
			result[i-1] = in%26;
		}
		else{
			j = i;
			tempD = in;
			while(j!=1){
				printf("j = %d\n",j);
				if(j>2&&tempD%2==0){   //消除影响 
					tempD = tempD/26-1;
					printf("tempD   %d,%d\n",tempD,j); 
					j--;
					continue;
				}
				if(tempD%26==0&&j==2){
					flag=1;
				}
				
				tempD /= 26;
				j--;
				if(i == 3){
					printf("The temp %d,%d,%d\n",tempD,flag,j);
				}
				 
			}
			printf("%d,%d\n",tempD,tempD%26);
			result[i-1] = tempD%26;
		
			if(flag==1){
				result[i-1] -= 1;
			} 
		
			flag = 0;
		} 
		 
	} 
	

	
	for(i=count-1;i>=0;i--){
		
		if(result[i]==0){
			printf("值：%d\n",result[i]);
			printf("Z\n");
		}
		else{
			printf("值：%d\n",result[i]);
			printf("%c\n",result[i]+64);
		}
	
	}
	
	return 0;
}


