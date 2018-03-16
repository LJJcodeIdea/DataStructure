#include <stdio.h>

int main()
{
	/*int a,b,c,d,e = 0;
	while(a>>b>>c>>d&&b!=-1){
	printf("%d、%d、%d、%d\n",a,b,c,d);
	}
	return 0;*/

	int a[4] = {1,2,3,4};


	void fack(int b[4]);  //在调用函数前，先声明函数，除非这个函数定义在 被调用处的函数 之前
	fack(a);


	return 0;
}
void fack(int b[4]){
	printf("%d",b[0]);
}