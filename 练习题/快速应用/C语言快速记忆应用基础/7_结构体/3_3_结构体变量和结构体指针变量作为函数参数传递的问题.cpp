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

	InputStudent(&st); //对结构体变量输入，必须发送st的地址

	OutputStudent(st);	//对结构体变量输出，可以发送st的地址也可以直接发送st的内容
		
	return 0;
}

void InputStudent(struct Student * pstu)
{
	(*pstu).age = 10;

	strcpy(pstu->name,"张三");		//不能写成 pstu.name = "张三"

	pstu->sex = 'F';
}

void OutputStudent(struct Student ss)
{
	printf("%d %s %c \n",ss.age,ss.name,ss.sex);
}