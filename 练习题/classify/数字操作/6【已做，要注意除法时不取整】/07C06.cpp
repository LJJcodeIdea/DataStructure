#include <stdio.h>
int main(){
	
	int num = 0;

	int all[9] = {0};

	for(int a1 = 1;a1<=9;a1++){

		for(int a2 = 1;a2<=9;a2++){
			if(a2==a1) continue;

			for(int a3 = 1;a3<=9;a3++){
				if(a3==a2||a3==a1) continue;

				for(int a4 = 1;a4<=9;a4++){
					if(a4==a1||a4==a2||a4==a3)continue;

					for(int a5 = 1;a5<=9;a5++){
						if(a5==a1||a5==a2||a5==a3||a5==a4)continue;

						for(int a6 = 1;a6<=9;a6++){
							if(a6==a1||a6==a2||a6==a3||a6==a4||a6==a5)continue;

							for(int a7 = 1;a7<=9;a7++){
								if(a7==a1||a7==a2||a7==a3||a7==a4||a7==a5||a7==a6)continue;

								for(int a8 = 1;a8<=9;a8++){
									if(a8==a1||a8==a2||a8==a3||a8==a4||a8==a5||a8==a6||a8==a7)continue;
									
									for(int a9 =1;a9<=9;a9++){
										if(a9==a1||a9==a2||a9==a3||a9==a4||a9==a5||a9==a6||a9==a7||a9==a8)continue;
										
										float result = a1 + (a2*(1.0)/a3) + (a4*100.0+a5*10.0+a6)*(1.0)/(a7*100.0+a8*10.0+a9);  //注意进行除法的地方都要转换成float型
										if(result == 10){
											//printf("%d %d  %d  %d  %d  %d  %d  %d  %d \n",a1,a2,a3,a4,a5,a6,a7,a8,a9);
											//printf("%f\n",result);
											num++;
										}
										
									
									}
								}	
							}
						}
					}
				}
			}
		}
	}

	printf("结果：%d\n",num);

	return 0;
}
