#include "stdio.h" 
#include "malloc.h"
#include "string.h"

//���ڳ����ǲ����ģ�����������ָ�� 
/*
	1����ν�ľ�������Ϊ�����������
   		����Ϊ  ���� �� ż�� 
   	
	   Ҫ�б� 
	   
	   ABA
	    
   	
	   	
   	2���ҵ��ָ�Ĳ��֣����û�У�����С����Ϊ�������� 
		
		
	3��ȷ����С���ķ����� 
*/

int jishu(int e1,int b2,int e2,char * input01){
	
	char * c1 =  (char *)malloc(sizeof(char)*(e1+1));
	char * c2 =  (char *)malloc(sizeof(char)*(e2-b2+1));
	int len1 = e1+1;
	int len2 = e2-b2+1;
	
	int flag = 0;
	strncpy(c1,input01,e1+1);
	strncpy(c2,input01+b2,e2+1); //input01 �� b2 �� ���Ǵ�  �ڶ�λ��ʼ �� b2  ���� �±�  1+b2 
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

	//ȥ��ͷβ����� 
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
	strncpy(c2,input01+b2,e2+1); //input01 �� b2 �� ���Ǵ�  �ڶ�λ��ʼ �� b2  ���� �±�  1+b2 
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
	printf("�����%d\n",num);
	return num	;
	
}

int main(){
	//���ڴ��������ַ�����
	
	char * input = (char *)malloc(sizeof(char)*1000);
	scanf("%s",input);
	int len = (int)strlen(input);
	
	int center = 0;  //��Ƿָ�λ�� 
	int min = 10000;  //��¼��С����� 
	int tempmin = 0;
	
	
	
	
		
		if(len!=1&&len!=0){
			
			//��ÿһ�������м��   ���1����������̬
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
				//���2��ż����̬ 
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
