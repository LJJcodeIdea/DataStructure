#include <stdio.h>

//定义结构体的第一种方式：
struct Student
{
	int age;
	float score;
	char sex;
};

//第二种方式
struct Student2
{
	int age;
	float score;
	char sex;
}str2={23,90,'t'};    //定义的同时，定义变量名,str2变量似乎这能在这里赋值



int main(void)
{
	//有结构体的名称，名称的用法~
	struct Student st  = {12,99,'m'};
	printf("%d\n",str2.age);

	//在定义结构体的同时，定义的结构体变量（str2的用法）
	struct Student2 st23 = str2;
	printf("%d\n",st23.age);


	
		//第三种方式
		struct
		{
			int age;
			float score;
			char sex; 
		}st3;

	return 0;	 
}