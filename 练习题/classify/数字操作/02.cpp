/*
�ڶ��⣺������
�������ǲ����ٽ��еȷֵ��������磺2 3 5 7 11 �ȡ�
    9 = 3 * 3 ˵��������3�ȷ֣��������������
���ǹ�����1949�꽨�������ֻ���� 1 9 4 9 ��4�����ֿ�Ƭ����������ڷ����ǵ��Ⱥ�˳�򣨵���Ƭ���ܵ��ŰڷŰ������ǲ������Խת�䣡������ô��������ɶ��ٸ�4λ�������أ�
���磺1949��4919 ������Ҫ��
��̣�����ɵ�4λ�����ĸ�������������Щ����!

˼·1���� 1949 ������λ�ÿ����г����ж��Ƿ�Ϊ��������ȥ�أ� 
		

˼·2����1000 �� 9999�����������г���ֻҪ��1��4������9 

*/

#include <stdio.h> 
#include <malloc.h>

	/*
		����һ���ж������ġ�����ֻ�ܱ�1 �� ���������� 
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
	C�����ﲻ����  ���� �������ͣ��� int[]  char[] �����������������͵ġ� 
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
  	Ԥ�����ĸ�forѭ�������п����г� 
  */

	for(i = 0;i<4;i++){
		for(j=0;j<4;j++){
			if(j==i) continue;
			for(k=0;k<4;k++){
				if(k==i||k==j) continue;
				for(l=0;l<4;l++){
					if(l==i||l==j||l==k) continue;
					tempyear = swap(i,j,k,l,year); //����λ�ý��� 
					check = tempyear[0]*1000 + tempyear[1]*100 + tempyear[2]*10 +tempyear[3];  //��ŵ���ʱ���� 
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





