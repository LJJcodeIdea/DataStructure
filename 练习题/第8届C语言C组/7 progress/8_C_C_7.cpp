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
	��ʾ����Ϊ���ӣ�
	pow(26,2)+1  
	AAA
	Ȼ����ǲ��ϼӵĹ��̣�
	�����ǣ�
	ĩβZ

	 
	while(){
	}
*/

int main() {
	
	/*
		�ðɣ�һ��ʼ�ͷ������ˣ������forѭ�����ó������ݣ������Ͳ��� Z ��  ZZZZZZZ ����Ӧֵ����ʵ�����ǣ�Z  YZ YYZ YYYZ ...����Ӧֵ����������ë�߰���
		 
	*/
	char A = 'A';
	printf("%c\n",64+26);
	printf("%d\n",2054/26); 
	printf("%d\n",26*26);
	for(int i = 1;i<=7;i++){
		printf("%d,%f\n",i,pow(26,i));
	} 
	

	
}
