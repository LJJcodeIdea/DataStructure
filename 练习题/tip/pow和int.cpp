
#include "stdio.h" 
#include "math.h"

int main(){
	int temp = 2147483647;  //���� int �ļ��޷�Χ�����pow�Ľ�������ˣ��ͻ�ò�����Ҫ�Ľ����int Ҳ�治�ˣ������� long long ��~ 
	int test = 88888;
	printf("%d,%d\n",(int)pow(test,2),temp);
	return 0;
}
