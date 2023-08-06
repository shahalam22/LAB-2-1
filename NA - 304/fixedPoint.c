#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 10.0e-6

double func(double a){
	return ((a*a*a)+(4*a*a)-10);
}

double funcG1(double a){
	return sqrt((10-(a*a*a))/4);
}

int main(void){

	int n = 100;
	double a0 = 1.5, a1;
	/*printf("Enter the value of lower bound: \n");
	scanf("%lf", &a);
	printf("Enter the value of upper bound: \n");
	scanf("%lf", &b);*/
	
	printf("Iter\t\ta0\t\ta1\t\tfuncG1(a0)\t\tfunc(a1)\n");
	printf("-------------------------------------------------------------------------------------------------------\n");
	
	for(int i=0; i<n; i++){
		a1 = funcG1(a0);
		printf("%d\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n",i+1 ,a0 ,a1 , funcG1(a0), func(a1));
		if(fabs(func(a1))<EPS){
			printf("Root is %lf\n", a1);
			exit(0);
		}
		else {
			a0 = a1;
		}
	}
	return 0;
}
