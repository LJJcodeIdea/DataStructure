#include <stdio.h>
#include <malloc.h>

int main(void)
{
	//int  a[5];  //���int ռ4���ֽڵĻ����������ܹ�����20���ֽڣ�ÿ�ĸ��ֽڶ���������һ��int������ʹ��

	int len;

	int i;

	int * pArr; 

	printf("��������Ҫ��ŵ�Ԫ�صĸ���");

	scanf("%d",&len);

	/* ��̬��һά���飬������int pArr[len] ,��һά����ĳ����� len*/

	pArr = (int *)malloc(4 * len); //����һ��20���ֽڣ���һ�� int վ4���ֽڣ�pArr ָ��ͷ�ĸ��ֽڣ�pArr + 1 ָ��������� �ĸ��ֽڣ��������ơ�����double *�������double������ 8���ֽڣ���pArrָ��ͷ8���ֽ�
								
									// ��ô pArr[0]  �� *pArr��ǰ�ᣬpArr��ָ��û�и��ġ�  ���൱�� һ������ �� ��һ�� Ԫ�ء�

	for(i = 0;i < len;++i)
	{
		scanf("%d",&pArr[i]);
	}


	for( i= 0;i<len;++i)
	{
			printf("%d\t",pArr[i]);
	}
	
	free(pArr);  //�ͷŵ���̬���������

	return 0;
}