#include <stdio.h>

#include <string.h>

struct Student
{
	int age;
	char sex;
	char name[100];
};
void InputStudent(struct Student * pstu);
void OutputStudent(struct Student ss);
int main(void)
{
	struct Student st;

	InputStudent(&st); //�Խṹ��������룬���뷢��st�ĵ�ַ

	OutputStudent(st);	//�Խṹ�������������Է���st�ĵ�ַҲ����ֱ�ӷ���st������
		
	return 0;
}

void InputStudent(struct Student * pstu)
{
	(*pstu).age = 10;

	strcpy(pstu->name,"����");		//����д�� pstu.name = "����"

	pstu->sex = 'F';
}

void OutputStudent(struct Student ss)
{
	printf("%d %s %c \n",ss.age,ss.name,ss.sex);
}