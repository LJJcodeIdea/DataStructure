/*
	1、首先数组不能给数组赋值，就是不许拷贝 
*/
/*
	实验：
	1、传递一个非指针数组进去，返回一个地址，看一个未赋值的非指针数组能够通过该返回地址被赋值
	【无法 将  数组 传递进去。】 
	2、验证一下 各种不同形式 的参数：int *  ， int a[] ,int a[3]
	【】 
	4、 直接定义两个 指针 数组，一个已初始化，另一个未初始化。模拟 题目场景，简易版。   
		a/一个用于交换位置的函数，函数的参数为  int * 类型 参数 
		b/ 传递一个 已初始化的 int * 类型 的 地址 给该函数 （ 类似用于 一个 int[3] 的数组 ） 
		c/作为 参数传递进去的 int * 变量的在参数结束后，必须保持为原有值
		d/有一个 未初始化 的  int * 类型的变量 被赋予返回的地址，该变量的值 为 调换后的结果 
*/
/*
	结论：experiment1： 1、非指针数组作为参数时，是无法接收一个非指针数组传递进去的 。 
						参数形式：（以int型为例） int 变量名[] 
		  experiment2:  2、非指针数组作为参数时，是可以接收一个指针数组的地址。
		  						由于是传递了地址进去，当在函数里改变了内容，被传的指针参数的内容也会发生改变  
		                3、返回类型不能设定为非指针类型数组，例如： int [] 函数名（）{} 这是不可行的, 
		                4、若你返回 int * 的值时，可返回一个数组的首地址，但无法用非指针数组接收这个 返回值。
		  experiment3:  5、指针数组作为参数时，可以将非指针数组的 首地址传进去。
		  						当在函数里，对参数的内容进行了修改，被传进去的非指针参数的值也会发生改变。 
		  			    6、如果要将非指针数组传给指针数组，应该将非指针数组的名称进行传递。（因非指针数组的指针名就是指针的首地址 ） 
	总结：
		1、非指针数组类型不能作为函数的返回类型
		2、非指针数组不能直接赋值给非指针数组（但可以通过for循环逐个赋值） 
		3、非指针数组类型可以作为 函数的 参数（例如：int a[]） ,但是无法接收非指针数组作为参数（不符合总结2）。 
		4、非指针数组类型可以作为 函数的 参数，接收  指针数组。
		5、当以指针数组类型作为函数的参数，传参 过来 的必然是 一个地址。当函数的参数的内容改变，被传进来的函数的内容必然会 改变。
		 
		 
		  			    
		                  
		   
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

//experiment3,指针作为函数参数，传数组进去
/*
int * experiment3(int * a) {
	printf("这是传进函数后，参数的输出：\n");
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
//	experiment(num[3]);	error，num[3]  代表的 是一个 int 类型的值。 
	printf("下面的是执行了函数，函数里的参数的内容进行了修改。再观看num数组：\n");
	for(int k = 0;k<3;k++){
		printf("%d\n",num[k]);
	}
	return 0;
}
*/

//experiment2,非指针数组可以接受指针数组 
/* 
int * experiment2(int a[]){
	
	
	
	for(int i = 0;i<3;i++){
		printf("%d\n",a[i]); 
	}
	
	//改变 a 里所有的值
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
	//	tp = experiment2(notx);  //出错处,无法用非指针数组接收指针数组的返回值 
	
	test = experiment2(notx);
	
	for(int k = 0;k<3;k++){
		printf("%d\n",notx[k]);
	}
	
	return 0;
} 
*/



//experiment 1，实验失败，数组不能 直接 赋值 给  数组 
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
	
	
//	tp = experiment1(notx);   失败，无法将 notx 传进 int a[]  为参数的函数
// 	tp = experiment1(notx[3 ]);  失败 
//    tp = experiment11(notx);   失败
//	tp = experiment11(notx[3]);  失败 
	printf("");
	return 0;
} 

*/
