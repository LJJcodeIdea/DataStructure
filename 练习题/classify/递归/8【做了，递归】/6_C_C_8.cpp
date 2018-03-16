#include  "stdio.h" 


/*
		begin = 5
		
		//begin / 3 >= 1 
		get = begin/3 = 5/3 = 1
		
		
		
		----------------------------------

		
		begin = 6
		//begin/3>1
		get = 6/3 = 2   //获得的  
		rest = begin - (get*3)  //剩余的
		
		
		begin = rest =  0
		 
*/

int all(int begin){
	int get,rest;
	if(begin/3<1) return 0;

	get = begin/3;
	//printf("%d\n",get);
	rest = begin -(get*3)+get ;
	return get + all(rest);
}

int main(){
	
	int i;
	scanf("%d",&i);
	
	printf("%d\n",i+all(i));
	
	return 0;
}
