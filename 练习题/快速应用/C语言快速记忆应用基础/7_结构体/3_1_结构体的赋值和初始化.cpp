#include <stdio.h>

/*
	��ֵ�ĵ��������
		
		1�������ͬʱ�������帳��ֵ

		2�����������֮����ֻ�ܵ����ĸ���ֵ
*/

struct Student
{
	int age;
	float score;
	char sex;
};

int main(void)
{
	struct Student st = {34,33.5,'f'};		//����ṹ��ı���ͬʱ���и�ֵ

	struct Student st2;

	st2.age = 10;
	st2.score = 33;
	st2.sex = 's';

	printf("%d %f %c\n ",st.age,st.score,st.sex);
	printf("%d %f %c\n ",st2.age,st2.score,st2.sex);

	return 0;
}