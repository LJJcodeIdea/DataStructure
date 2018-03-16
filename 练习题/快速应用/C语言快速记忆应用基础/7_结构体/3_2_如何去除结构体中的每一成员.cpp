/*
	如何去除结构体变量中的每一个成员
		
		 1、结构体变量名.成员名

		 2、指针变量名->成员名  【更常用】
				指针变量名->成员名  在计算机内部会被转换成  (*指针变量名).成员名
				的方式执行

		 上面的两种方式是等价的。
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
	struct Student st = {80,44.2,'F'};  //初始化  定义的同时赋初值
	
	struct Student * pst = &st;

	//第一种方式
	st.age = 10;

	//第二种方式
	pst->age = 88;  //pst->age 在计算机内部会被转化成 (*bat).age
	
	/*
		pat -> age 的含义：
			pst所指向的那个结构体变量中的age这个成员
	*/
	
	st.score = 66.6f;

	printf("%d,%f\n",st.age,pst->score);


	return 0;
}