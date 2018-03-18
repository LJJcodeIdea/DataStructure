#include "stdio.h" 
#include "malloc.h"
#include "string.h"

//由于长度是不定的，所以用数组指针 
/*
	1、所谓的镜像，我认为有两种情况：
   		总数为  奇数 或 偶数 
   	
	   要判别 
	   
	   ABA
	    
   	
	   	
   	2、找到分割的部分，如果没有，那最小数认为是它本身 
		
		
	3、确认最小数的方法： 
*/

int jishu(int e1,int b2,int e2,char * input01){
	
	char * c1 =  (char *)malloc(sizeof(char)*(e1+1));
	char * c2 =  (char *)malloc(sizeof(char)*(e2-b2+1));
	int len1 = e1+1;
	int len2 = e2-b2+1;
	
	int flag = 0;
	strncpy(c1,input01,e1+1);
	strncpy(c2,input01+b2,e2+1); //input01 加 b2 个 ，是从  第二位开始 加 b2  就是 下标  1+b2 
	printf("%s,%s,%s\n",c1,c2,input01);
	int num = 0;
	for(int i = 0;i<len1;i++){
		for(int j = 0;j<len2;j++){
			if(c1[i] == c2[j]){
				c1[i]=c2[j]='N';
			}
		
		}
	}
	
    for(int i = 0;i<len1;i++){
		if(c1[i]!='N'){
				num++;
	    }
	}
	for(int j = 0;j<len2;j++){
		if(c2[j]!='N'){
				num++;
	    }	
		
	}
	return num;
} 

int oushu(int e1,int b2,int e2,char * input01){

	//去掉头尾的情况 
	if(e1==0){
		return e2+1-b2-1;
	}
	if(b2==e2-1){
		return e2+1-2;
	}
	
	
	char * c1 =  (char *)malloc(sizeof(char)*(e1+1));
	char * c2 =  (char *)malloc(sizeof(char)*(e2-b2+1));
	int len1 = e1+1;
	int len2 = e2-b2+1;
	
	int flag = 0;
	strncpy(c1,input01,e1+1);
	strncpy(c2,input01+b2,e2+1); //input01 加 b2 个 ，是从  第二位开始 加 b2  就是 下标  1+b2 
	printf("%s,%d,%s,%d,%s\n",c1,len1,c2,len2,input01);
	int num = 0;
	for(int i = 0;i<len1;i++){
		for(int j = 0;j<len2;j++){
			if(c1[i] == c2[j]){
				c1[i]=c2[j]='N';
			}
		
		}
	}
	
	 for(int i = 0;i<len1;i++){
		if(c1[i]!='N'){
				num++;
	    }
	}
	for(int j = 0;j<len2;j++){
		if(c2[j]!='N'){
				num++;
	    }	
		
	}
	printf("结果：%d\n",num);
	return num	;
	
}

int main(){
	//用于存放输入的字符数组
	
	char * input = (char *)malloc(sizeof(char)*1000);
	scanf("%s",input);
	int len = (int)strlen(input);
	
	int center = 0;  //标记分割位置 
	int min = 10000;  //记录最小情况数 
	int tempmin = 0;
	
	
	
	
		
		if(len!=1&&len!=0){
			
			//对每一个数进行检测   情况1：是奇数形态
			for(int i = 1;i<len-1;i++){
				
				if(input[i-1] == input[i+1]){
					center = i;
					tempmin = jishu(i-1,i+1,len-1,input);
					if(tempmin<min){
						min = tempmin;
					}
				} 
			} 
			
			if(min == 10000){
				//情况2：偶数形态 
				for(int j = 0;j<len-1;j++){
					
					if(input[j] == input[j+1]){
						center = j;
						tempmin = oushu(j,j+1,len-1,input);
						if(tempmin<min){
							min = tempmin;
						}
					}
				} 						
			}

		}
		
		
		
	

	
	if(len == 1){
		printf("1\n");
		return 0;
	}
	
	if(len == 2){
		if((int)input[0] == (int)input[1]){
			printf("0\n");
		}
		if((int)input[0] != (int)input[1]){
			printf("1\n"); 
		} 
		return 0;
	}
	 
	if(min == 10000){
		min = len;
	}
	printf("%d\n",min); 
	return 0;
}
