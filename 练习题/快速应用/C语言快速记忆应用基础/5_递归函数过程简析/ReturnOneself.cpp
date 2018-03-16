#include <stdio.h>
int getPeachNumber(n)
{
    int num;    //定义所剩桃子数
    if(n==10)
    {
       return        //递归结束条件
    } 
    else
    {
        //今天的剩余量 = 前一天总/ 2 - 1 
        
        /*
              (sum) = 第九天剩的=（第10天剩的 + 1）*2
                        =（1+1）*2=4
            (sum) 第8天剩的=（  (sum) + 1）*2
                        = （4 + 1）* 2 = 10
                        
                        g(n+1)*2
            
        
        */
        num = (n+1)*2 + getPeachNumber(n);   //这里是不应该用递归呢？
        printf("第%d天所剩桃子%d个\n", (10-n), num); //天数，所剩桃子个数
    }
    return num;
}
int main()
{
    int num = getPeachNumber(1);
    printf("猴子第一天摘了:%d个桃子。\n", num);
    return 0;
}

/*
10: 一个

已知：
第十天：剩下 一个 桃子

今天的剩余量 = 前一天总/ 2 - 1 

要求：打印每天剩下的的桃子 ，从第十天开始

      并打印出第一天一共摘了多少桃子。
      
      第九天总的桃子：
      （ 今天剩余量 + 1 ） * 2 = （1 + 1） * 2 = 4
      
      

*/