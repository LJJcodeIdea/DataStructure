#include  <stdio.h>

int main(void){
	int A,B,C,D,E,F,G,H,I;

	int num = 0;

	for(int i1 = 1;i1<=9;i1++){
		for(int i2 = 1;i2<=9;i2++){
			if(i2 == i1) continue;
			for(int i3 = 1;i3<=9;i3++){
				if(i3 == i2||i3 ==i1) continue;
				for(int i4 = 1;i4<=9;i4++){
					if(i4 == i3 || i4 == i2 || i4 == i1) continue;
					for(int i5 = 1;i5<=9;i5++){
						if(i5 == i4 || i5 == i3 || i5== i2 || i5==i1) continue;
						for(int i6=1;i6<=9;i6++){
							if(i6 == i4 || i6 == i3 || i6== i2 || i6==i1 || i6==i5) continue;
							for(int i7 = 1;i7<=9;i7++){
								if(i7 == i4 || i7 == i3 || i7== i2 || i7==i1 || i7==i5 || i7 == i6) continue;
								for(int i8 = 1;i8<=9;i8++){
									if(i8 == i4 || i8 == i3 || i8== i2 || i8==i1 || i8==i5 || i8 == i6 || i8 == i7) continue;
									for(int i9 = 1;i9<=9;i9++){
										if(i9 == i4 || i9 == i3 || i9== i2 || i9==i1 || i9==i5 || i9 == i6 || i9 == i7 || i9 == i8) continue;
										if((i1 + i2/(float)i3 + (i4*100+i5*10+i6)/(float)(i7*100+i8*10+i9)) == 10){
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
	

	printf("%d\n",num);
	return 0;
}