#include "stdio.h"
#include "math.h"
#include "string.h"
/*
	A  1 
	Z  26
	
	AA 27
	AZ 52
	
	BA 53
	BZ 78
	
	...
	ZA
	ZZ
	
	AAA
	AAZ
	
	1���ҿ��ǵ�����������м�����ĸ ��7�ֿ��ܣ���ʼ��A AA AAA AAAA AAAAA  AAAAAA AAAAAAA�� 
	2�� Ȼ������������ĩβ��ʼ�����֣�ֱ����ͬΪֹ��ͬʱ��ĸҪ������Ӧ�ı任 
*/

int main() {
	char A = 'A';
	printf("%c\n",64+26);
	printf("%d\n",2054/26); 
	printf("%d\n",26*26);
	for(int i = 1;i<=7;i++){
		printf("%d,%f\n",i,pow(26,i));
	} 
	
	int in;
	int count; 
	int i;
	scanf("%d",&in); 
	
	if(in <= pow(26,1)){
		
	}
	else if(in <= pow(26,2)){
		
	}
	else if(in <= pow(26,3)){
		char result3[3] = {'Z','Z','Z'};
		count = pow(26,3);
		i = 2;
		printf("%d\n",in);
		while(reult){
			count = count -1;
			result3[i] -= 1;
			printf("%d\n",count);
			if(count==in){
				break;
			}
			if(result3[i]=='Z'){
				i--;
				result3[i] = 'A'; 
			}
		}
		for(i=0;i<=3;i++){
			printf("%c",result3[i]);
		}
	}
	else if(in <= pow(26,4)){
		
	}
	else if(in <= pow(26,5)){
		
	}
	else if(in <= pow(26,6)){
		
	}
	else{
		
	}
	
}
