#include "stdio.h"
int main(){	
	int a,b,c,d,e,f,g,h;
	for(a = 0;a<=9;a++){    //a
		for(b = 0;b<=9;b++){    //  b
			if(b!=a){
				for(c = 0;c<=9;c++){   // c
					if(c!=a&&c!=b){
						for(d = 0;d<=9;d++){   // d
							if(d!=a&&d!=b&&d!=c){  
								for(e = 0;e<=9;e++){  //e
									if(e!=a&&e!=b&&e!=c&&e!=d){
										for(f = 0;f<=9;f++ ){   // f
											if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e){
												for(g = 0;g <= 9;g++){    // g
													if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f){
														for(h = 0;h<=9;h++ ){
															if(h!=a&&h!=b&&h!=c&&h!=d&&h!=e&&h!=f&&h!=g){
																if( (a*1000+b*100+c*10+d) + (e*1000+f*100+g*10+b) == (e*10000+f*1000+c*100+b*10+h) ){
																	printf("%d,%d,%d,%d\n",e,f,g,b);
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
	return 0;
}
