/*
第三题：字符串对比
给定两个仅由大写字母或小写字母组成的字符串(长度介于1到10之间)，它们之间的关系是以下4中情况之一：	
1：两个字符串长度不等。比如 Beijing 和Hebei	
2：两个字符串不仅长度相等，而且相应位置上的字符完全一致(区分大小写)，比如 Beijing 和 Beijing	
3：两个字符串长度相等，相应位置上的字符仅在不区分大小写的前提下才能达到完全一致（也就是说，它并不满足情况2）。比如beijing和BEIjing	
4：两个字符串长度相等，但是即使是不区分大小写也不能使这两个字符串一致。比如 Beijing 和 Nanjing	
编程判断输入的两个字符串之间的关系属于这四类中的哪一类，给出所属的类的编号。
input:
	包括两行，每行都是一个字符串
output:
	仅有一个数字，表明这两个字符串的关系编号
sample input:
	BEIjing
	beiJing
sample output:
	3
*/

#include <stdio.h> 
#include <string.h>
#include <malloc.h>

int main(){
	char * A = (char *)malloc(sizeof(char)*10);
	char * B = (char *)malloc(sizeof(char)*10);
	//输入
	scanf("%s",A);
	scanf("%s",B);
	//
	if(strlen(A) != strlen(B)){
		printf("%d\n",1);
	}
	else{
		if(strcmp(A,B) == 0){
			printf("%d\n",2);
		}
		if(strcasecmp(A,B)==0){
			printf("%d\n",3);
		}
		if(strcasecmp(A,B)!=0){
			printf("%d\n",4);
		}
	}
	return 0;
}
