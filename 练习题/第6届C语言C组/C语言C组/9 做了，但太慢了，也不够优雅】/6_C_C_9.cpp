/*
	�ܽ᣺
	1����������ַ�����ʵ�ʳ��ȣ����黹�Ƕ���һ��ָ�롣ʹ��strlen()���ʵ�ʵ����ݳ��ȡ���sizeof()��õ����ַ�������󳤶ȼӽ�����~�������	 
	2���������ַ�����������ʹ�ø�ʽ��%s������ʹ��forѭ������Ƚϱ���һ�㡣�����������Ķ����� 
*/

#include "stdio.h" 
#include "string.h"
#include "malloc.h"
int main(){
	
	
	/*
	  �ȳ������ϰ벿�֡� 
	*/
	//  0<m<n  3<n<1000    n������ 
	int m,n;  //nָ����һ���ж����� 
	scanf("%d %d",&m,&n); 
	//�ϰ벿�� ռ������ 
	int topPart = n/2;
    //ÿ�еĿ�ȣ� 
	int singleLen = m+n-1;

	//����һ�е�ģ�� 
	char * Line = (char *)malloc(sizeof(char)*singleLen);
		//printf("%d,%d\n",singleLen,sizeof(Line));
	//��߲��ֵĵ�һ���ǵ�λ��
	int x = 0;
	
	int i,j,k;
	int t = 0; 
	for(i=0;i<n;i++){
		x = i; 
		if(i<=topPart){
			for(j=0;j<singleLen;j++){
				//�Ȱ�һ���ж������ո�
				 Line[j] = '.';
			}
			//��Ӧλ�ý������ 
			for(k=1;k<=m;k++){
				Line[x+t] = '*';
				Line[singleLen-x-t-1] = '*';
				//printf(" %d",(singleLen-x-t-1));
				t++;
			}
			t = 0;
			//����û���ø�ʽ�� %s �ķ�ʽ�������Ϊ���ܻ��������Ķ��� 
			for(k=0;k<singleLen;k++){
				printf("%c",Line[k]);
			}			 
			printf("\n");
		}	
		
		if(i >= topPart+1){
			for(j=0;j<singleLen;j++){
				//�Ȱ�һ���ж������ո�
				 Line[j] = '.';
			}
			//��Ӧλ�ý������ 
			for(k=1;k<=m;k++){
				Line[x+t] = '*';
				Line[singleLen-x-t-1] = '*';
				t++;
			}
			t = 0;
			for(k=0;k<singleLen;k++){
				printf("%c",Line[k]);
			}			 
			printf("\n");
		} 
		
	} 
	
	
	/*
	char string[] = "****................****";   
	char * string2 = "****................****";
	int len = sizeof(string);  //��������������� �������ģ� 
	int len2 = (int)strlen(string2);   //����� ʵ�����ݣ�����������ȽϺ� 
	printf("���ȣ�%d,%d\n",len,len2); 
	*/
	return 0;
}
