/*
第二题：组素数
素数就是不能再进行等分的数。比如：2 3 5 7 11 等。
    9 = 3 * 3 说明它可以3等分，因而不是素数。
我们国家在1949年建国。如果只给你 1 9 4 9 这4个数字卡片，可以随意摆放它们的先后顺序（但卡片不能倒着摆放啊，我们不是在脑筋急转弯！），那么，你能组成多少个4位的素数呢？
比如：1949，4919 都符合要求。
编程：能组成的4位素数的个数，并罗列这些素数!

思路1：将 1949 的所有位置可能列出，判断是否为素数并且去重， 
		

思路2：将1000 到 9999的所有素数列出，只要有1、4、两个9 

*/

#include <stdio.h> 
#include <malloc.h>

	/*
		先做一个判断素数的。素数只能被1 或 它本身整除 
	*/
int issu(int temp){
	int i = 0;
	
	for(i = 2;i<temp;i++){
		if(temp%i == 0){
			return 0;
		}
	}	
	
	if(i == temp){
		return 1;
	} 
	
	return 0;
}

/*
	C语言里不存在  返回 数组类型，即 int[]  char[] 不可能用作返回类型的。 
*/
int * swap(int i,int j,int k,int l, int * tt){
	int temp;
	int * ty = (int *)malloc(sizeof(int)*4);
	for(int i = 0;i<4;i++){
		ty[i] = tt[i];
	} 
	
	ty[0] = tt[i];
	ty[1] = tt[j];
	ty[2] = tt[k];
	ty[3] = tt[l];

	
	return ty;
	
} 

int main(void){
  int num = 4;

  int * year = (int *)malloc(sizeof(int)*4);
  year[0] = 1;
   year[1] = 9;
    year[2] = 4;
     year[3] = 9;
  int * tempyear;
  int check;
  int result[1000] = {7};
  int i,j,k,l,m;
  int m2 = 0;
  int flag = 1;
	
  /*
  	预计用四个for循环将所有可能列出 
  */

	for(i = 0;i<4;i++){
		for(j=0;j<4;j++){
			if(j==i) continue;
			for(k=0;k<4;k++){
				if(k==i||k==j) continue;
				for(l=0;l<4;l++){
					if(l==i||l==j||l==k) continue;
					tempyear = swap(i,j,k,l,year); //进行位置交换 
					check = tempyear[0]*1000 + tempyear[1]*100 + tempyear[2]*10 +tempyear[3];  //存放到临时变量 
					//printf("==%d\n",check);
					if(issu(check)){
						for(m = 0;m <=m2;m++){
							if(result[m] == check){
								flag = 0;
								break;
							}
						}
						if(flag){
							result[m2] = check;
							m2++; 
							printf("%d\n",check);
						}
						
					}
					flag = 1;
				}
			}
		}
	} 
	
	printf("%d\n",m2);

	
	return 0;
}





