// 参考：http://blog.csdn.net/zhangge138/article/details/79590822 




#include<stdio.h>  
  
char s[7] = {0};  
  
int main()  
{  	
	 char test = 'A';
	 printf("%d",test-1); 
     int x;  
     
     /*
     	字母是可以相同的，就不用设置那么多判断了 
	 	巧妙之处：
		   关于如何设置前面几位是没有的时候，该怎么做。
		    
	 */
     
     scanf("%d",&x);  
     for(int i = -1 ; i < 26 ; i++)  
        for(int j = (i == -1)?-1 : 0 ; j < 26 ; j++)  
             for(int k = (j == -1)?-1 : 0 ; k < 26 ; k++)  
                 for(int l = (k == -1)?-1 : 0 ; l < 26 ; l++)  
                      for(int m = (l == -1)?-1 : 0 ; m < 26 ; m++)  
                          for(int n = (m == -1)?-1 : 0 ; n < 26 ; n++)  
                                 for(int o = (n == -1)?-1 : 0 ; o < 26 ; o++)  
                                   {  
                                         s[0] = 'A' + i ;  
                                         s[1] = 'A' + j ;  
                                         s[2] = 'A' + k ;  
                                         s[3] = 'A' + l ;  
                                         s[4] = 'A' + m ;  
                                         s[5] = 'A' + n ;  
                                         s[6] = 'A' + o ;  
                                         
                                         /*
											A表示第1列，
											B表示第2列，
											Z表示第26列，
											
											AA表示第27列，   27
											AB表示第28列，
											
											BA表示第53列，  27 + 26 
											CA表示第79列，  53 + 26 = 27 + 26*2
											。。。
											ZA表示 677列                   27 + 26*25 
											ZZ  ->  702
											
											思路：
											
											根据提示：
											1、可以用下面判断出
										
											
											
																					
										*/
                                         
                                         int q = 0;  
                                         for(int p = 0 ; p < 7 ; p ++)  
                                         {  
                                             q = q * 26 + (s[p] - 'A' + 1);  
                                            // printf("q * 26 + (s[p] - 'A' + 1)\n");
                                            // printf("%d * 26 + (%d  - 65 + 1)\n",q,s[p]);
                                         } 
                                         printf("%d  ",q); 
										 for(int r = 0 ; r < 7 ; r++)  
                                             {  
                                                 if(s[r] == '@')printf("");  
                                                  else printf("%c",s[r]);  
                                             }  
                                        printf("\n");
                                         if(q == x)  
                                         {  
                                             for(int r = 0 ; r < 7 ; r++)  
                                             {  
                                                 if(s[r] == '@')printf("");  
                                                  else printf("%c",s[r]);  
                                             }  
                                             printf("\n");  
                                             return 0;  
                                         }  
                                   }  
     return 0;  
          
}   
