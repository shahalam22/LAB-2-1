//This code is providing area inside f(x) = root(x) & g(x) = x*x

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 10.0e-6

//this is h(x) function = f(x) - g(x)
double func(double a){
	return ((sqrt(a))-(a*a));
}

//code for simpson
int simpSon(double a, double b){
	int n = 10000;
	double h, x[n+1], y[n+1], sum_x, sum_o = 0, sum_e = 0;
	x[0] = a;
	x[n] = b;
	y[0] = func(x[0]);
	y[n] = func(x[n]);
	
	if(n%2==1) h = (b-a)/(n+1);
	else h = (b-a)/n;
	
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

double bisection(int n, double a, double b){
	double c, root = 0;
	
	if(func(a)*func(b)>0) exit(0);
	
	for(int i=0; i<n; i++){
		c = (a+b)/2;
		if(fabs(func(c))<EPS){
			printf("\nRoot is %lf\n\n", c);
			root = c;
			break;
		}
		if(func(a)*func(c)<0) b=c;
		else a=c;
	}
}

//this is main function
int main(void){
	double root;
	
	root = bisection(100, 0.25, 1.25);
	
	simpSon(0.0, root);
	
	return 0;
}
