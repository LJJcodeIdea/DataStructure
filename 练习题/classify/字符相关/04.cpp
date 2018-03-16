/*
	
第四题：字符图形
利用字母可以组成一些美丽的图形，下面给出了一个例子：
ABCDEFGH
BABCDEFG
CBABCDEF
DCBABCDE
这是一个4行8列的图形，请找出这个图形的规律，并输出一个n行m列的图形。
输入格式
输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。
输出格式
输出n行，每个m个字符，为你的图形。
样例输入
4 8
样例输出
ABCDEFGH
BABCDEFG
CBABCDEF
DCBABCDE
数据规模与约定
1 <= n, m <= 26

*/
/*
	两个用于存储，输入数字的变量n,m
	一个初始字符数组：包含最开始的数组 
	注意当 加  1  大于 72时， 变换为   
*/
#include <stdio.h> 
int main(){
	int n,m,i,j;
	char lt;
	char result[26];
	result[0] = 'A'; //A  65
	scanf("%d",&n); 
	scanf("%d",&m);
	printf("%c",result[0]);
	for(i = 1;i<m;i++){
		result[i] = result[i-1] + 1;
			printf("%c",result[i]);
	}
	printf("\n");
	lt = result[i-1] + 1;
	for(i = 1;i<n;i++){
		for(j = 0;j<m;j++){
			result[j] = result[j] + 1;
			if(result[j] == lt){
				result[j] = 'A';
				printf("%c",result[j]);
				continue;
			}
			printf("%c",result[j]);
		}
		printf("\n");
	}
	//printf("%c",lt);
	//printf("%d\n",result[0]);	
	return 0;
}
