#include "stdio.h"
#include "math.h"
#include "string.h"
/*
	A  1 
	Z  26
	
	AA 27
	AZ 52
	
	BA 53
	BZ 78
	
	...
	ZA
	ZZ
	
	AAA
	AAZ
	
	1、我考虑的是先算出它有几个字母 （7种可能：初始：A AA AAA AAAA AAAAA  AAAAAA AAAAAAA） 
	2、 然后根据情况，从末尾开始加数字，直到相同为止。同时字母要进行相应的变换 
	以示例二为例子：
	pow(26,2)+1  
	AAA
	然后就是不断加的过程：
	首先是：
	末尾Z

	 
	while(){
	}
*/

int main() {
	
	/*
		好吧，一开始就分析错了，下面的for循环，得出的数据，根本就不是 Z 到  ZZZZZZZ 的相应值啊（实际上是：Z  YZ YYZ YYYZ ...的相应值）。还做个毛线啊。
		 
	*/
	char A = 'A';
	printf("%c\n",64+26);
	printf("%d\n",2054/26); 
	printf("%d\n",26*26);
	for(int i = 1;i<=7;i++){
		printf("%d,%f\n",i,pow(26,i));
	} 
	

	
}
