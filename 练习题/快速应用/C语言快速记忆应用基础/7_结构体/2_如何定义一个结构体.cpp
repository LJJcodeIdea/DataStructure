#include <stdio.h>

//����ṹ��ĵ�һ�ַ�ʽ��
struct Student
{
	int age;
	float score;
	char sex;
};

//�ڶ��ַ�ʽ
struct Student2
{
	int age;
	float score;
	char sex;
}str2={23,90,'t'};    //�����ͬʱ�����������,str2�����ƺ����������︳ֵ



int main(void)
{
	//�нṹ������ƣ����Ƶ��÷�~
	struct Student st  = {12,99,'m'};
	printf("%d\n",str2.age);

	//�ڶ���ṹ���ͬʱ������Ľṹ�������str2���÷���
	struct Student2 st23 = str2;
	printf("%d\n",st23.age);


	
		//�����ַ�ʽ
		struct
		{
			int age;
			float score;
			char sex; 
		}st3;

	return 0;	 
}