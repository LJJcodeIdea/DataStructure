/*
����β����

��Щ���ֵ�������ĩβ�����Ǹ����ֱ���
���磺1,4,5,6,9,24,25,....

�������һ�£���10000���ڵ������У�ָ�����֣����������������ֵ�����������������������һ���ж��ٸ���

���ύ����������Ҫ��д�κζ�������ݡ�

�����  36������ĳ�����û����ģ���������� dev-C++ �༭���������������ġ� ������ c ���Ա��������ԣ� 
*/

#include "stdio.h"
#include "math.h"

int main(){
	
	int temp = 1123123;

	printf("%d\n",(temp%100));
	/*
	//�������޷������ô������� 
	printf("%ld",pow(10000,3));
	*/ 
	
	long long Temp; //���ڴ洢 ����������� 
	int i,s;
	int count = 0; //�洢���ٸ�����Ҫ��� 
	
	for(i=1;i<10000;i++){
		
		Temp = (long long)pow(i,3);
		
		if(i>0&&i<10){
			//printf("i = %d,%d,%lf\n",i,(Temp%10),pow(i,3));
			if(i==Temp%10){
				printf("%d,%d\n",i,Temp%10);
				count++;
			}
		}
		
		if(i>=10&&i<100){
			if(i==Temp%100){
				printf("%d,%d\n",i,Temp%100);
				count++;
			}
		}
		
		if(i>=100&&i<1000){
			if(i==Temp%1000){
				printf("%d,%d\n",i,Temp%1000);
				count++;
			}
		}
		
		if(i>=1000&&i<10000){
			if(i==Temp%10000){
				printf("%d,%d\n",i,Temp%10000);
				count++;
			}
		}
		

	}
	
	printf("�����%d\n",count);
	return 0;
}















