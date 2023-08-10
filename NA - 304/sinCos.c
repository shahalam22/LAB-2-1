#include <stdio.h>
#include <math.h>

#define PI 3.141659265

int main(void){
	int n = 100, i;
	double a = 0, b = 2*PI, h, x;
	h = (b-a)/n;
	
	printf("x,  y = sin(x), y' = cos(x)\n");	//this is a csv[comma separated value] file
	x = a;
	for(int i=0; i<=n; i++){
		x = a + i*h;
		printf("%lf, %lf, %lf\n", x, sin(x), cos(x));
	}
	return 0;
}
