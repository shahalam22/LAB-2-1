#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 10.0e-6

double func(double a){
	return ((a*a*a)+(4*a*a)-10);
}

int main(void){

	int n = 100;
	double a=1.25, b=1.5, c;
	/*printf("Enter the value of lower bound: \n");
	scanf("%lf", &a);
	printf("Enter the value of upper bound: \n");
	scanf("%lf", &b);*/
	
	if(func(a)*func(b)>0) exit(0);
	
	printf("Iter\t\ta\t\tb\t\tc\t\tfunc(a)\t\tfunc(b)\t\tfunc(c)\n");
	printf("-------------------------------------------------------------------------------------------------------\n");
	
	for(int i=0; i<n; i++){
		c = ((a*func(b))-(b*func(a)))/(func(b)-func(a));
		printf("%d\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n",i+1 ,a ,b ,c ,func(a), func(b), func(c));
		if(fabs(func(c))<EPS){
			printf("Root is %lf\n", c);
			exit(0);
		}
		if(func(a)*func(c)<0) b=c;
		else a=c;
	}
	return 0;
}
