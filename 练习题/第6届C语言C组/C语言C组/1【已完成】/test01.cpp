/*

隔行变色

Excel表的格子很多，为了避免把某行的数据和相邻行混淆，可以采用隔行变色的样式。
小明设计的样式为：第1行蓝色，第2行白色，第3行蓝色，第4行白色，....
现在小明想知道，从第21行到第50行一共包含了多少个蓝色的行。

请你直接提交这个整数，千万不要填写任何多余的内容。
*/

#include "stdio.h" 

int main(){	

	int num = 0;  //代表四种颜色 
	int count = 0;  //记录一共有多少蓝色 
	int count21 = 0; //记录到20行的时候，有多少个蓝色 
	for(int i = 1;i<=50;i++){
		num++;
		if(num==4){
			num=0;
		}
		if(num==3||num==1){
			count++;  //记录蓝色的行数 
		}
		if(i==20){
			count21 = count;
		} 
	}
	
	printf("%d,%d,结果：%d\n",count,count21,(count-count21));
	
	return 0;
}
