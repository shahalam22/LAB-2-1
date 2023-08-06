#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 10.0e-6

double func(double a){
	return ((a*a*a)+(4*a*a)-10);
}

double derFunc(double a){
	return ((3*a*a)+(8*a));
}

int main(void){

	int n = 100;
	double x0=1.25, x1;
	/*printf("Enter the value of lower bound: \n");
	scanf("%lf", &a);
	printf("Enter the value of upper bound: \n");
	scanf("%lf", &b);*/
	
	printf("Iter\t\tx0\t\tx1\tfunc(x0)\tderFunc(x0)\tfunc(x1)\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	
	for(int i=0; i<n; i++){
		x1 = x0 - ((func(x0))/derFunc(x0));
		printf("%d\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n",i+1 ,x0 ,x1 ,func(x0) ,derFunc(x0), func(x1));
		if(fabs(func(x1))<EPS){
			printf("Root is %lf\n", x1);
			exit(0);
		}else x0 = x1;
	}
	return 0;
}
