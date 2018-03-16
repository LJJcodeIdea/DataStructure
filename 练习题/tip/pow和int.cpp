
#include "stdio.h" 
#include "math.h"

int main(){
	int temp = 2147483647;  //这是 int 的极限范围，如果pow的结果超出了，就会得不出想要的结果。int 也存不了，考虑用 long long 型~ 
	int test = 88888;
	printf("%d,%d\n",(int)pow(test,2),temp);
	return 0;
}
