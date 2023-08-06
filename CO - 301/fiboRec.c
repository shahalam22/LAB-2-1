#include <stdio.h>

long int fibo(long int a);

long int f[100];

int main(){
	long int a = 50;

	for(int i=0; i<100; i++){
		f[i] = -1;
	}

	long int b = fibo(a);
	
	printf("%ld th fibonacci number is %ld\n", a, b);
}

long int fibo(long int a){
	if(a<=1){
		f[a] = a;
		return a;
	}
	else{
		if(f[a]<0){
			f[a] = fibo(a-1) + fibo(a-2);
		}
		return f[a];
	}
}
