#include "stdio.h"
#include "string.h"
int f(char s[], int begin, int end)
{
	int mid;
	if(end-begin==1) return s[begin] - '0';

	mid = (end+begin) / 2;

	return f(s,begin,mid) + f(s,mid,end);  //МоїХ
}
	
int main()
{
	//char s[] = "4725873285783245723";
	char s[] = "472";
/*	char test = '0';
	printf("%d,%d,%d\n",s[0],s[1],test);*/
	printf("%d\n",f(s,0,strlen(s)));
	return 0;
}
