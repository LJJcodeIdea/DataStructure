/*
	1���������鲻�ܸ����鸳ֵ�����ǲ����� 
*/
/*
	ʵ�飺
	1������һ����ָ�������ȥ������һ����ַ����һ��δ��ֵ�ķ�ָ�������ܹ�ͨ���÷��ص�ַ����ֵ
	���޷� ��  ���� ���ݽ�ȥ���� 
	2����֤һ�� ���ֲ�ͬ��ʽ �Ĳ�����int *  �� int a[] ,int a[3]
	���� 
	4�� ֱ�Ӷ������� ָ�� ���飬һ���ѳ�ʼ������һ��δ��ʼ����ģ�� ��Ŀ���������װ档   
		a/һ�����ڽ���λ�õĺ����������Ĳ���Ϊ  int * ���� ���� 
		b/ ����һ�� �ѳ�ʼ���� int * ���� �� ��ַ ���ú��� �� �������� һ�� int[3] ������ �� 
		c/��Ϊ �������ݽ�ȥ�� int * �������ڲ��������󣬱��뱣��Ϊԭ��ֵ
		d/��һ�� δ��ʼ�� ��  int * ���͵ı��� �����践�صĵ�ַ���ñ�����ֵ Ϊ ������Ľ�� 
*/
/*
	���ۣ�experiment1�� 1����ָ��������Ϊ����ʱ�����޷�����һ����ָ�����鴫�ݽ�ȥ�� �� 
						������ʽ������int��Ϊ���� int ������[] 
		  experiment2:  2����ָ��������Ϊ����ʱ���ǿ��Խ���һ��ָ������ĵ�ַ��
		  						�����Ǵ����˵�ַ��ȥ�����ں�����ı������ݣ�������ָ�����������Ҳ�ᷢ���ı�  
		                3���������Ͳ����趨Ϊ��ָ���������飬���磺 int [] ����������{} ���ǲ����е�, 
		                4�����㷵�� int * ��ֵʱ���ɷ���һ��������׵�ַ�����޷��÷�ָ������������ ����ֵ��
		  experiment3:  5��ָ��������Ϊ����ʱ�����Խ���ָ������� �׵�ַ����ȥ��
		  						���ں�����Բ��������ݽ������޸ģ�������ȥ�ķ�ָ�������ֵҲ�ᷢ���ı䡣 
		  			    6�����Ҫ����ָ�����鴫��ָ�����飬Ӧ�ý���ָ����������ƽ��д��ݡ������ָ�������ָ��������ָ����׵�ַ �� 
	�ܽ᣺
		1����ָ���������Ͳ�����Ϊ�����ķ�������
		2����ָ�����鲻��ֱ�Ӹ�ֵ����ָ�����飨������ͨ��forѭ�������ֵ�� 
		3����ָ���������Ϳ�����Ϊ ������ ���������磺int a[]�� ,�����޷����շ�ָ��������Ϊ�������������ܽ�2���� 
		4����ָ���������Ϳ�����Ϊ ������ ����������  ָ�����顣
		5������ָ������������Ϊ�����Ĳ��������� ���� �ı�Ȼ�� һ����ַ���������Ĳ��������ݸı䣬���������ĺ��������ݱ�Ȼ�� �ı䡣
		 
		 
		  			    
		                  
		   
*/

#include <stdio.h>
#include <malloc.h>

//experiment4
int * experiment5(int * a,int len,int i1,int i2,int i3,int i4){
	int * temp = (int *)malloc(sizeof(int)*len);
	int tp;
	
	for(int i = 0;i<len;i++){
		temp[i] = a[i];
	}
	
	tp = temp[0];
	temp[0] = temp[i1];
	temp[i1] = tp;
	
	tp = temp[1];
	temp[1] = temp[i2];
	temp[i2] = tp;
	
	tp = temp[2];
	temp[2] = temp[i3];
	temp[i3] = tp;
	
	tp = temp[3];
	temp[3] = temp[i4];
	temp[i4] = tp;
	
	return temp;
	 
} 

int main(void){
	
	int * array = (int *)malloc(sizeof(int)*4);
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3]  = 4;
	
	int * result = experiment5(array,4,0,3,1,2);
	
	int i = 0; 
	
	for(i = 0;i<4;i++){
		printf("%d\n",array[i]);
	}
	
	printf("============\n");
	
	for(i = 0;i<4;i++){
		printf("%d\n",result[i]);
	}
	
	return 0;
}

//experiment3,ָ����Ϊ�����������������ȥ
/*
int * experiment3(int * a) {
	printf("���Ǵ��������󣬲����������\n");
	for(int i = 0;i<3;i++){
		printf("%d\n",a[i]);
	}
	
	for(int j = 0;j<3;j++){
		a[j] = 5;
	}
}

int main(void){
	int num[3] = {1,2,3};
	experiment3(num);
//	experiment(num[3]);	error��num[3]  ����� ��һ�� int ���͵�ֵ�� 
	printf("�������ִ���˺�����������Ĳ��������ݽ������޸ġ��ٹۿ�num���飺\n");
	for(int k = 0;k<3;k++){
		printf("%d\n",num[k]);
	}
	return 0;
}
*/

//experiment2,��ָ��������Խ���ָ������ 
/* 
int * experiment2(int a[]){
	
	
	
	for(int i = 0;i<3;i++){
		printf("%d\n",a[i]); 
	}
	
	//�ı� a �����е�ֵ
	for(int j = 0;j<3;j++){
		a[j] = 55;
	} 
	
	return a;
} 

int main(void){
	
	int * notx = (int *)malloc(sizeof(int)*3);
	int * test; 
	notx[0] = 1;
	notx[1] = 2;
	notx[2] = 3;
	int  tp[3];
	//	tp = experiment2(notx);  //����,�޷��÷�ָ���������ָ������ķ���ֵ 
	
	test = experiment2(notx);
	
	for(int k = 0;k<3;k++){
		printf("%d\n",notx[k]);
	}
	
	return 0;
} 
*/



//experiment 1��ʵ��ʧ�ܣ����鲻�� ֱ�� ��ֵ ��  ���� 
/*
int * experiment1(int a[]){
	int * temp = a;
	return temp;
} 
int * experiment11(int a[3]){
	int * temp = a;
	return temp;
}
*/

/*
int main(void){
	
	int * notx[3] = {1,2,3};
	int  tp[3];
	
	
//	tp = experiment1(notx);   ʧ�ܣ��޷��� notx ���� int a[]  Ϊ�����ĺ���
// 	tp = experiment1(notx[3 ]);  ʧ�� 
//    tp = experiment11(notx);   ʧ��
//	tp = experiment11(notx[3]);  ʧ�� 
	printf("");
	return 0;
} 

*/
