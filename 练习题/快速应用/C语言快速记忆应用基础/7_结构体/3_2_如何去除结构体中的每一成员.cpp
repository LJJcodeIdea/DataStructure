/*
	���ȥ���ṹ������е�ÿһ����Ա
		
		 1���ṹ�������.��Ա��

		 2��ָ�������->��Ա��  �������á�
				ָ�������->��Ա��  �ڼ�����ڲ��ᱻת����  (*ָ�������).��Ա��
				�ķ�ʽִ��

		 ��������ַ�ʽ�ǵȼ۵ġ�
*/


#include <stdio.h>

struct Student
{
	int age;
	float score;
	char sex;
};


int main(void)
{
	struct Student st = {80,44.2,'F'};  //��ʼ��  �����ͬʱ����ֵ
	
	struct Student * pst = &st;

	//��һ�ַ�ʽ
	st.age = 10;

	//�ڶ��ַ�ʽ
	pst->age = 88;  //pst->age �ڼ�����ڲ��ᱻת���� (*bat).age
	
	/*
		pat -> age �ĺ��壺
			pst��ָ����Ǹ��ṹ������е�age�����Ա
	*/
	
	st.score = 66.6f;

	printf("%d,%f\n",st.age,pst->score);


	return 0;
}