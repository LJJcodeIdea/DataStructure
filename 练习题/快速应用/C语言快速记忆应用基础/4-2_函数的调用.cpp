#include <stdio.h>

int main()
{
	/*int a,b,c,d,e = 0;
	while(a>>b>>c>>d&&b!=-1){
	printf("%d��%d��%d��%d\n",a,b,c,d);
	}
	return 0;*/

	int a[4] = {1,2,3,4};


	void fack(int b[4]);  //�ڵ��ú���ǰ������������������������������� �����ô��ĺ��� ֮ǰ
	fack(a);


	return 0;
}
void fack(int b[4]){
	printf("%d",b[0]);
}