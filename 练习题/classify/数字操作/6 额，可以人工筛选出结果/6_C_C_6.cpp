/*
	˼·���ȴ���ȷ�����·�Χ 
	
	һ���� ��
	
	numlen ��ȡ������ƽ�������� �� ��λ��
	
	���� numlen ��ȡ ����λ���������ж�
	��ע��ȥ���жϣ� 
	 
		
	1234 / 10  = 123
	123 /10 = 12
	12 /10  =  1
	1 /10  = 0
	
	1234 % 10 = 4	
	1234 / 10 % 10 = 3      //  ʮλ     �� 10 ȡ�� 
	1234 /10 /10 %10 = 2    //   ��λ    �� 100 ȡ��  
	1234 /10 /10 /10 = 1
	
	12  % 10 = 2
	12 /10 = 
	
*/

/*
	Ҫȷ���� ��ʹ�� double x = pow() ���� int ǿ��ת��ʱ�� x ����ʲô��Χ���ͻ�ʧȥ׼ȷ��
	
	Ӧ���������գ�
	 
	�����ж�һ�����ж���λ�ķ���
	
	��ȡһ������ÿһλ
	
	���⼼�ɣ�
	����һ��Ҫ���һ��ͨ�õĳ�������ȡ�𰸡�
	����������ģ������¾�֪�������������ˣ� ����£�Ӧ������ �����н���г������˹�ɸѡҲ�ǿ��Եġ� 
*/


#include "stdio.h"
#include "math.h"
#include "malloc.h"
#define max 10


 //�ж�һ�����Ǽ�λ�� 
int checkLen(int num){
	int count = 0;
	while(num/10!=0){
		num = num/10;
		count++;
	}
	count++;
	
	return count;
} 

//��ȡһ����ÿһλ,���� ���ȡ�� temp ����� 
void getNum(int num,int numLen,int * temp){
	
	void judgeNum(int num,int * temp);
	judgeNum((num%10),temp);
	
	if(numLen>1){   //
		for(int i = 2;i<numLen;i++){  // Ĭ��i��ȡ num �ĵڼ�λ���� 
		printf("test: %d,%d\n",(int)(pow(10,i-1)),num);
			judgeNum( (num/(int)(pow(10,i-1)))%10 , temp ); 
		}
	
		judgeNum((num/(int)pow(10,numLen-1)),temp);  //���һλ 
		 
	} 
	
	
} 

//�жϷ���Ҫ��ĸ��� 
void judgeNum(int num,int * temp){
	//	printf("oj9k,%d\n",num);
	for(int i = 0;i<max;i++){  //sizeof(temp)  == 8, max == 10
	//	printf(",%d\n",i);
		if(i == num&&temp[i]==13){  //ȷ��  ƽ�� �� �����󣬲����м�¼��ͬ������ 
			temp[i] = i;
		
		}
	}
	
}


int main(){
	
	//printf("%d,%d\n",pow(),pow());
	/*
	printf("%d\n",checkLen(1));
	printf("%f,%f\n",pow(19,2),pow(19,3));
	printf("%f,%f\n",pow(29,2),pow(29,3));
	printf("%f,%f\n",pow(39,2),pow(39,3));
	*/
	int * result = (int *)malloc(sizeof(int)*max);
	int flag = 1;
	
	

	int tempResult;
	for(int i = 0;i<100;i++){
		//�Խ������䣬������� 
		for(int j = 0;j<max;j++){
			result[j] = 13;
		}
		printf("%d\n",i);
		for(int i2 = 2;i2<=3;i2++){
			int tempNum;
			if(i2 == 2){
				 tempNum = i*i;
			}
			else{
				 tempNum = i*i*i;	
			}
			
			//printf("i2=%d,%d",i2,tempNum);
			getNum(tempNum,checkLen(tempNum),result); //�ж�i 
		
			for(int k = 0;k<max;k++){
				if(result[k] == 13){
					flag = 0;
				}
			} 
			printf("\n");
			
			if(flag == 1){
			
				tempResult = i;
				break;
			}
			flag = 1; 
		}
		
	}
		printf("�𰸣�%d,%d,%d\n",tempResult,(tempResult*tempResult),(tempResult*tempResult*tempResult));
	return 0;
}
