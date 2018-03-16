#include <stdio.h>


/* 自定义整型函数 sayLove() */
int sayLove()
{
    //在这里输入输出语句printf，输出内容为I Love imooc 
   printf("I Love imooc\n");
    return 0;
}

/* 自定义整型函数 dividLine() */
int dividLine()
{
    printf("%s\n", "*************");
    return 0;
}

/* 主函数 */
int main()
{
	sayLove();
	dividLine();
    
	return 0;
}