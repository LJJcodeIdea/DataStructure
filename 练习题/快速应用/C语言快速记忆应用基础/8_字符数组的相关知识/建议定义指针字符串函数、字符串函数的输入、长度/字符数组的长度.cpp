#include <stdio.h> 
#include <malloc.h>
#include <string.h>
/*
	�����ʼ״̬ �� Ŀ��״̬  Ԥ�� �������ַ�����  ������ 999�� 
	
	������ٵĴ��� 
	
	 
*/

int main(void){
	char str1[999];
	char str2[999];
	char * str3 = (char *)malloc(sizeof(char)*999);
	int i = 0;
	int len,len2; //Ӳ�ҵĸ��� 
	int num; //��¼��ת�Ĵ��� 
	
	//�����ʼ�� 
	/*for(i = 0;i<999;i++){
		str1[i] = 'n';
		str2[i] = 'n';
	}*/
	
	
	/*
		
		���ȵıȽ� 
		
	*/
	//���룺
	scanf("%s",str1); 
	scanf("%s",str3);
	
	len = sizeof(str1)/sizeof(char);  //�������û��ֱ�������������ַ�������������ֻ�����ʼ�õĳ��� ����ôֻ����forѭ����ĩβ��������ַ���ǣ���ȷ�����ȿ��� 
	len2 = strlen(str3);			//����� ָ�� �ַ� ����ķ������ܹ���Ч�������������ַ����� 
	
	
	printf("���ַ�ʽ�ĳ��ȣ�%d,%d\n",len,len2);

	

}
