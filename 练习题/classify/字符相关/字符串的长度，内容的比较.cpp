/*
�����⣺�ַ����Ա�
�����������ɴ�д��ĸ��Сд��ĸ��ɵ��ַ���(���Ƚ���1��10֮��)������֮��Ĺ�ϵ������4�����֮һ��	
1�������ַ������Ȳ��ȡ����� Beijing ��Hebei	
2�������ַ�������������ȣ�������Ӧλ���ϵ��ַ���ȫһ��(���ִ�Сд)������ Beijing �� Beijing	
3�������ַ���������ȣ���Ӧλ���ϵ��ַ����ڲ����ִ�Сд��ǰ���²��ܴﵽ��ȫһ�£�Ҳ����˵���������������2��������beijing��BEIjing	
4�������ַ���������ȣ����Ǽ�ʹ�ǲ����ִ�СдҲ����ʹ�������ַ���һ�¡����� Beijing �� Nanjing	
����ж�����������ַ���֮��Ĺ�ϵ�����������е���һ�࣬������������ı�š�
input:
	�������У�ÿ�ж���һ���ַ���
output:
	����һ�����֣������������ַ����Ĺ�ϵ���
sample input:
	BEIjing
	beiJing
sample output:
	3
*/

#include <stdio.h> 
#include <string.h>
#include <malloc.h>

int main(){
	char * A = (char *)malloc(sizeof(char)*10);
	char * B = (char *)malloc(sizeof(char)*10);
	//����
	scanf("%s",A);
	scanf("%s",B);
	//
	if(strlen(A) != strlen(B)){
		printf("%d\n",1);
	}
	else{
		if(strcmp(A,B) == 0){
			printf("%d\n",2);
		}
		if(strcasecmp(A,B)==0){
			printf("%d\n",3);
		}
		if(strcasecmp(A,B)!=0){
			printf("%d\n",4);
		}
	}
	return 0;
}
