#include <stdio.h> 
#include <malloc.h>
#include <string.h>
/*
	输入初始状态 及 目标状态  预计 用两个字符数组  （长度 999） 
	
	输出最少的次数 
	
	 
*/

int main(void){
	char str1[999];
	char str2[999];
	char * str3 = (char *)malloc(sizeof(char)*999);
	int i = 0;
	int len,len2; //硬币的个数 
	int num; //记录翻转的次数 
	
	//数组初始化 
	/*for(i = 0;i<999;i++){
		str1[i] = 'n';
		str2[i] = 'n';
	}*/
	
	
	/*
		
		长度的比较 
		
	*/
	//输入：
	scanf("%s",str1); 
	scanf("%s",str3);
	
	len = sizeof(str1)/sizeof(char);  //用这个，没法直接算出你输入的字符个数。给出的只是你初始好的长度 。那么只有用for循环和末尾用特殊的字符标记，来确定长度咯。 
	len2 = strlen(str3);			//如果用 指针 字符 数组的方法，能够有效的算出你输入的字符个数 
	
	
	printf("两种方式的长度：%d,%d\n",len,len2);

	

}
