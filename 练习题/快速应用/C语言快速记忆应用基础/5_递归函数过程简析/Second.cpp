/*
题目：
猴子第一天摘下N个桃子，当时就吃了一半，还不过瘾，就又多吃了一个。
第二天又将剩下的桃子吃掉一半，又多吃了一个。以后每天都吃前一天剩下的一半零一个。
到第10天在想吃的时候就剩一个桃子了,问第一天共摘下来多少个桃子？并反向打印每天所剩桃子数



*/
#include <stdio.h>
long getPeachNumber(int n)
{
    int num;    //定义所剩桃子数
	
    if(n==10)
    {
       return 1;      //递归结束条件
    } 
    else
    {
		printf("k\n");
        num = ( getPeachNumber ( n + 1 ) + 1 ) * 2;   //这里是不应该用递归呢？
       printf("第%d天所剩桃子%d个\n", n, num); //天数，所剩桃子个数
    
       

    }
    printf("%d\n",num);
		return num;   //问题：  当执行了结束递归的条件后，逐级返回递归时，我把返回语句注释了，为什么，会返回2？
}
int main()
{
    int num = getPeachNumber(1);
    printf("猴子第一天摘了:%d个桃子。\n", num);
    return 0;
}