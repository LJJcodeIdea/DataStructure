/*
	总结：
	1、如果计算字符串的实际长度，建议还是定义一个指针。使用strlen()获得实际的内容长度。而sizeof()获得的是字符串的最大长度加结束符~（在这里）	 
	2、如果输出字符串，不建议使用格式符%s，还是使用for循环输出比较保险一点。不会输出多余的东西。 
*/

#include "stdio.h" 
#include "string.h"
#include "malloc.h"
int main(){
	
	
	/*
	  先尝试下上半部分。 
	*/
	//  0<m<n  3<n<1000    n是奇数 
	int m,n;  //n指的是一共有多少行 
	scanf("%d %d",&m,&n); 
	//上半部分 占多少行 
	int topPart = n/2;
    //每行的宽度： 
	int singleLen = m+n-1;

	//单独一行的模板 
	char * Line = (char *)malloc(sizeof(char)*singleLen);
		//printf("%d,%d\n",singleLen,sizeof(Line));
	//左边部分的第一颗星的位置
	int x = 0;
	
	int i,j,k;
	int t = 0; 
	for(i=0;i<n;i++){
		x = i; 
		if(i<=topPart){
			for(j=0;j<singleLen;j++){
				//先把一整行都填满空格
				 Line[j] = '.';
			}
			//对应位置进行描绘 
			for(k=1;k<=m;k++){
				Line[x+t] = '*';
				Line[singleLen-x-t-1] = '*';
				//printf(" %d",(singleLen-x-t-1));
				t++;
			}
			t = 0;
			//这里没有用格式符 %s 的方式输出，因为可能会输出多余的东西 
			for(k=0;k<singleLen;k++){
				printf("%c",Line[k]);
			}			 
			printf("\n");
		}	
		
		if(i >= topPart+1){
			for(j=0;j<singleLen;j++){
				//先把一整行都填满空格
				 Line[j] = '.';
			}
			//对应位置进行描绘 
			for(k=1;k<=m;k++){
				Line[x+t] = '*';
				Line[singleLen-x-t-1] = '*';
				t++;
			}
			t = 0;
			for(k=0;k<singleLen;k++){
				printf("%c",Line[k]);
			}			 
			printf("\n");
		} 
		
	} 
	
	
	/*
	char string[] = "****................****";   
	char * string2 = "****................****";
	int len = sizeof(string);  //这个长度是算上了 结束符的， 
	int len2 = (int)strlen(string2);   //这个是 实际内容，还是用这个比较好 
	printf("长度：%d,%d\n",len,len2); 
	*/
	return 0;
}
