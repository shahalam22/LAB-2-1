#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 10.0e-6

double func(double a){
	return ((a*a)+1);
}

double differn(double a){
	return (2*a);
}

int main(void){

	int n = 10;
	double a = 0.0, b = 2.0;
	double h = (b-a)/n;
	
	double x[n+1], y[n+1], diff[n+1], yBar[n+1];
	
	x[0] = a, x[n] = b;
	for(int i=1; i<n; i++){
		x[i] = x[i-1] + h;
	}
	for(int i=0; i<n+1; i++){
		y[i] = func(x[i]);
		yBar[i] = differn(x[i]);
	}
	
	for(int i=0; i<n+1; i++){
		//FORWARD-DIFFERENCE
		if(i==0){
			diff[i] = (y[i+1]-y[i])/(x[i+1]-x[i]);
		}else if(i==n){
			diff[i] = (y[i]-y[i-1])/(x[i]-x[i-1]);
		}else{
			diff[i] = (y[i+1]-y[i-1])/(x[i+1]-x[i-1]);
		}
	}
	
	printf("x     y    diff  y'\n");
	
	for(int i=0; i<n+1; i++){
		printf("%0.2f  %0.2f %0.2f  %0.2f\n", x[i], y[i], diff[i], yBar[i]);
	}
	
	return 0;
}
