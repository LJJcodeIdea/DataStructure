#include <stdio.h>
#include <malloc.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN],size;

//�ѵĳ�ʼ��
void Create()
{
	size = 0;
	H[0] = MINH; //���� �ڱ�
}

//�������
int Insert(int X)
{
	/*�� X ����H*/

	if(size==1000) return 0;

	int i;
	
	/*
		�����Ǵ����һ���ڵ�ĸ��ڵ� ��ʼ �� X ���бȽϣ�
		һ��ʼ��i���� �ѵ����һ���ڵ���±꣬i/2 ����
		��ǰ�ڵ�ĸ��ڵ���±ꡣ

		������һ���� XС �Ľڵ㣬������ѭ�������뵽��ǰ�ڵ���ӽڵ��У��±�Ϊi��

		��һ��ʼ�����һ���ڵ�ĸ��ڵ�� X �󣬾ͻ� ����ǰ�ڵ� �ƶ������ֽڵ��λ�ã�
		Ȼ���������һ���ڵ�Ƚ�
	*/
	for(i=++size;H[i/2]>X;i/=2)
		H[i] = H[i/2];

	H[i]=X;
	return 1;
}

int main()
{
	int n,m,x,i,j;

	scanf("%d %d/n",&n,&m);

	Create();  //��ʼ���ѣ�

	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		Insert(x);
	}
	
	for(i=0;i<m;i++)
	{
		scanf("%d",&j);
		printf("%d",H[j]);
		while(j>1)
		{
			j/=2;
			printf(" %d",H[j]);
		}
		printf("\n");
	}

	return 0;
}