/*
	
�����⣺�ַ�ͼ��
������ĸ�������һЩ������ͼ�Σ����������һ�����ӣ�
ABCDEFGH
BABCDEFG
CBABCDEF
DCBABCDE
����һ��4��8�е�ͼ�Σ����ҳ����ͼ�εĹ��ɣ������һ��n��m�е�ͼ�Ρ�
�����ʽ
����һ�У�������������n��m���ֱ��ʾ��Ҫ�����ͼ�ε�������������
�����ʽ
���n�У�ÿ��m���ַ���Ϊ���ͼ�Ρ�
��������
4 8
�������
ABCDEFGH
BABCDEFG
CBABCDEF
DCBABCDE
���ݹ�ģ��Լ��
1 <= n, m <= 26

*/
/*
	�������ڴ洢���������ֵı���n,m
	һ����ʼ�ַ����飺�����ʼ������ 
	ע�⵱ ��  1  ���� 72ʱ�� �任Ϊ   
*/
#include <stdio.h> 
int main(){
	int n,m,i,j;
	char lt;
	char result[26];
	result[0] = 'A'; //A  65
	scanf("%d",&n); 
	scanf("%d",&m);
	printf("%c",result[0]);
	for(i = 1;i<m;i++){
		result[i] = result[i-1] + 1;
			printf("%c",result[i]);
	}
	printf("\n");
	lt = result[i-1] + 1;
	for(i = 1;i<n;i++){
		for(j = 0;j<m;j++){
			result[j] = result[j] + 1;
			if(result[j] == lt){
				result[j] = 'A';
				printf("%c",result[j]);
				continue;
			}
			printf("%c",result[j]);
		}
		printf("\n");
	}
	//printf("%c",lt);
	//printf("%d\n",result[0]);	
	return 0;
}
