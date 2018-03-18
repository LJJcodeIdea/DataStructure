#include "stdio.h" 

int main(){
	
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
	
	for(i1 = 0;i1<=9;i1++){   // i1
		
		for(i2 = 0;i2<=9;i2++){    // i2
			
			if(i2!=i1){   // check  i2!=i1
				
				for(i3 = 0;i3<=9;i3++){  //i3
				
					if(i3!=i2&&i3!=i1){   //check i3 != i1,i2
						
						for(i4 = 0;i4<=9;i4++){  //i4
							
							if(i4!=i3&&i4!=i2&&i4!=i1){  //check
								
								for(i5 = 0;i5<=9;i5++){  // i5
									
									if(i5!=i4&&i5!=i3&&i5!=i2&&i5!=i1){
										
										for(i6 = 0;i6<=9;i6++){  //i6
											
											if(i6!=i5&&i6!=i4&&i6!=i3&&i6!=i2&&i6!=i1){  //check
												
												for(i7 = 0;i7<=i9;i7++){  //i7
													
													if(i7!=i6&&i7!=i5&&i7!=i4&&i7!=i3&&i7!=i2&&i7!=i1){  //check
														
														for(i8 = 0;i8<=9;i8++){  //i8
															
															if(i8!=i7&&i8!=i6&&i8!=i5&&i8!=i4&&i8!=i3&&i8!=i2&&i8!=i1){  //check
																
																for(i9 = 0;i9<=9;i9++){  //i9
																	
																	if(i9!=i8&&i9!=i7&&i9!=i6&&i9!=i5&&i9!=i4&&i9!=i3&&i9!=i2&&i9!=i1){   //check
																		
																		for(i10 = 0;i10<=9;i10++){ //i10
																			
																			if(i10!=i9&&i10!=i8&&i10!=i7&&i10!=i6&&i10!=i5&&i10!=i4&&i10!=i3&&i10!=i2&&i10!=i1){
																				
																				int a = i1*1000+i2*100+i3*10+i4;
																				int b = i5*1000+i6*100+i7*10+i8;
																				int c = i9*10+i10;
																				
																				if((a-b)*c==900){
																					printf("%d,%d,%d\n",a,b,c); //
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
	
	printf("%d\n",(6048-5973)*12);
	
	return 0;
}
