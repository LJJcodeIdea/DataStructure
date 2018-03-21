//×ªÔØ£ºhttp://blog.csdn.net/zhangge138/article/details/79590822
 
#include<stdio.h>  
  
int a[50];   
  
int main()  
{  
     int n;  
     int count = 0;  
     scanf("%d",&n);  
     while(n > 0)  
     {  
         int t = n%26;  
         if(t == 0)  
         {  
             a[count++] = 25;  
             n = n/26 - 1;  
             continue;  
         }  
         a[count++] = t - 1;  
         n /= 26;  
     }  
     for(int i = 0 ; i < count ; i++)  
     {  
         printf("%c", a[i] + 'A');  
     }  
     printf("\n");  
     return 0;  
}   

