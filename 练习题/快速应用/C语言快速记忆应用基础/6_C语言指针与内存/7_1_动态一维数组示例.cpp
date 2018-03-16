#include <stdio.h>
#include <malloc.h>

int main(void)
{
	//int  a[5];  //如果int 占4个字节的话，则本数组总共包含20个字节，每四个字节都被当做了一个int变量来使用

	int len;

	int i;

	int * pArr; 

	printf("请输入你要存放的元素的个数");

	scanf("%d",&len);

	/* 动态的一维数组，类似于int pArr[len] ,该一维数组的长度是 len*/

	pArr = (int *)malloc(4 * len); //这里一共20个字节，若一个 int 站4个字节，pArr 指向开头四个字节，pArr + 1 指向接下来的 四个字节，依次类推。若（double *），如果double类型是 8个字节，那pArr指向开头8个字节
								
									// 那么 pArr[0]  或 *pArr【前提，pArr的指向没有更改】  是相当于 一个数组 的 第一个 元素。

	for(i = 0;i < len;++i)
	{
		scanf("%d",&pArr[i]);
	}


	for( i= 0;i<len;++i)
	{
			printf("%d\t",pArr[i]);
	}
	
	free(pArr);  //释放掉动态分配的数组

	return 0;
}