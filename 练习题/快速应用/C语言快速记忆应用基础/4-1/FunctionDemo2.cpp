#include <stdio.h>
/* 考虑一下哪个输出该用无参函数哪个输出该用有参函数呢？ */
int Demo()
{
    printf("小明在慕课网上学习\n");
    return 0;
}



int Demo2(int n)
{
    printf("小明在慕课网上已经参与学习了%d门课程\n",n);
    return 0;
}






int main()
{
    Demo();
    Demo2(3);

    return 0;
}