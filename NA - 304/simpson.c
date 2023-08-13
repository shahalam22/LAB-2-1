//we use this rule to find area of a function

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double a){
	return ((a*a) + 1);
}

int main(void){

	int n = 10;
	double a = 0.0, b = 2.0;
	double h, x[n+1], y[n+1], sum_x, sum_o = 0, sum_e = 0;
	
	if(n%2==1) h = (b-a)/(n+1);
	else h = (b-a)/n;
	
	x[0] = a;
	x[n] = b;
	
	y[0] = func(x[0]);
	y[n] = func(x[n]);
	
	for(int i=1; i<n; i++){
		x[i] = x[i-1] + h;
		y[i] = func(x[i]);
	}
	
	sum_x = y[0] + y[n];
	
	for(int i=1; i<n; i++){
		if(i%2==1) sum_o = sum_o + y[i];
		else sum_e = sum_e + y[i];
	}
	
	double i = (h/3)*(sum_x + (4*sum_o) + (2*sum_e));
	
	printf("Simpson Rule\n");
	printf("-----------------\n");
	printf("Integral Value: %lf\n", i);
	printf("-----------------\n");
	
	return 0;
}
