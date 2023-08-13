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
	double h = (b-a)/n;
	
	double x[n+1], y[n+1], sum_x, sum_y = 0;
	
	x[0] = a;
	x[n] = b;
	
	y[0] = func(x[0]);
	y[n] = func(x[n]);
	
	for(int i=1; i<n; i++){
		x[i] = x[i-1] + h;
		y[i] = func(x[i]);
	}
	
	double sum_x = y[0] + y[n];
	
	for(int i=1; i<n; i++){
		sum_y = sum_y + y[i];
	}
	
	double i = (h/2)*(sum_x + (2*sum_y));
	
	printf("Trapezoidal Rule\n");
	printf("-----------------\n");
	printf("Integral Value: %lf\n", i);
	printf("-----------------\n");
	
	return 0;
}
