#include <stdio.h>

/*
	赋值的的两种情况
		
		1、定义的同时可以整体赋初值

		2、如果定义完之后，则只能单个的赋初值
*/

struct Student
{
	int age;
	float score;
	char sex;
};

int main(void)
{
	struct Student st = {34,33.5,'f'};		//定义结构体的变量同时进行赋值

	struct Student st2;

	st2.age = 10;
	st2.score = 33;
	st2.sex = 's';

	printf("%d %f %c\n ",st.age,st.score,st.sex);
	printf("%d %f %c\n ",st2.age,st2.score,st2.sex);

	return 0;
}