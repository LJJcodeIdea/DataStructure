#include  <stdio.h> 
#include <malloc.h>

/*
	A   1
	
	B   2
	
	Z   26
	
	AA  27
	
	AZ  52   --> 52/26==2  Ԥ�� ��Ҫ�õ� 1 
	
	BA  53    
	
	BZ  78    --->  78/26 == 3
	
	ZZ  702 
	
	BZZ  2054
	
	
	ϣ����Ƚ��ƽ������⣬���Ͼ�����ȫ�ǡ�
	������Z�����ʱ��ǰһλ���ܵ�Ӱ�졣
	���˺ܾã�����ʲô���µĻ��ǲ����� 
	�����Ȱѽ��������
	
	��ʼʱ����ͨ����26��ȥһ��ĩλ����ǰһλ�����ж��������Z���ͱ��һ�� flag = 1��
	����λ��Ϊ2ʱ�����ã�����λ��Ϊ3������BZZʱ�ͻ��������˵ȡ��B������ǰ��������Z  2054/26 == 79 [79%26!=0]  79/26 ==3   
	
	�ţ�������Ӱ�� �� ZZZ ʱ��λ�����жϴ���
	
	������˼·�����⡣ 
	
*/
int main(){
	
	//���룺
	int in;
	scanf("%d",&in); 
	
	//��ȡλ����
	int count = 1;
	int tempIn = in;

	while(tempIn>26){
		count++;

		tempIn /=  26;
	}
	printf("%d\n",count);

	
	//��Ž��
	char * result = (char *)malloc(sizeof(char)*count);
	int tempD; 
	int i,j;	//����ѭ�� 
	int flag = 0; //����Ƿ�Ҫ����Ӱ�� 
	//ȡ������λ��
	for(i=1;i<=count;i++){
		//��ȡ��ĩλ
		if(i==1){
			result[i-1] = in%26;
		}
		else{
			j = i;
			tempD = in;
			while(j!=1){
				printf("j = %d\n",j);
				if(j>2&&tempD%2==0){   //����Ӱ�� 
					tempD = tempD/26-1;
					printf("tempD   %d,%d\n",tempD,j); 
					j--;
					continue;
				}
				if(tempD%26==0&&j==2){
					flag=1;
				}
				
				tempD /= 26;
				j--;
				if(i == 3){
					printf("The temp %d,%d,%d\n",tempD,flag,j);
				}
				 
			}
			printf("%d,%d\n",tempD,tempD%26);
			result[i-1] = tempD%26;
		
			if(flag==1){
				result[i-1] -= 1;
			} 
		
			flag = 0;
		} 
		 
	} 
	

	
	for(i=count-1;i>=0;i--){
		
		if(result[i]==0){
			printf("ֵ��%d\n",result[i]);
			printf("Z\n");
		}
		else{
			printf("ֵ��%d\n",result[i]);
			printf("%c\n",result[i]+64);
		}
	
	}
	
	return 0;
}


