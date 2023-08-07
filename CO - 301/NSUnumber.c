#include <stdio.h>

long int f[100];

long int nsu(long int a){
	if(a<=2){
		f[a] = a;
		return a;
	}
	else{
		if(f[a]<0){
			f[a] = nsu(a-1) + nsu(a-2) + nsu(a-3);
		}
		return f[a];
	}
}


int main(){

	long int a;
    printf("Enter nth number: ");
    scanf("%d", &a);

	for(int i=0; i<100; i++){
		f[i] = -1;
	}

	long int b = nsu(a);
	printf("%ld th NSU number is %ld\n", a, b);

    return 0;
}