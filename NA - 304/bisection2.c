#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 10.0e-6

double func(double a){
	return ((a*a*a)+(4*a*a)-5);
}

int main(void){

	int n = 100;
	double a, b, c, r1 = -5, r2 = 5;
	
	double diff = (r2-r1)/6;
	
	for(int i=0; i<6; i++){
		a = r1+(i*diff);
		b = r1+((i+1)*diff);
		
		//printf("%0.6lf   %0.6lf\n", a, b);
	
	
		if(func(a)*func(b)>0){	
			continue;
		}
	
		for(int j=0; j<n; j++){
			c = (a+b)/2;
			if(fabs(func(c))<EPS){
				printf("Root is %lf\n", c);
				break;
			}
			if(func(a)*func(c)<0) b=c;
			else a=c;
		}
	
	
	}
	
	
	return 0;
}
