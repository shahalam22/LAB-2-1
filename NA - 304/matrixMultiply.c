#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int a[15][15] = {0}, b[15][15] = {0}, ans[15][15] = {0}, ans2[15][15] = {0};
	clock_t start, end;
	
	srand(time(0));
	
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			a[i][j] = (int)rand()%15;
			b[i][j] = (int)rand()%15;
		}
	}
	
	
	start = clock();
	
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			for(int k=0; k<15; k++){
				ans[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	
	end = clock();
	
	printf("\nTime need here is - %lf\n", ((double)(end - start))/CLOCKS_PER_SEC);
	
	
	printf("Matrix 1 -\n");
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	printf("Matrix 2 -\n");
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");

	printf("Answer -\n");
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	
	
	start = clock();
	
	for(int k=0; k<15; k++){
		for(int i=0; i<15; i++){
			for(int j=0; j<15; j++){
				ans2[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	
	end = clock();
	
	printf("\nTime need here is - %lf\n", ((double)(end - start))/CLOCKS_PER_SEC);
	
	
	printf("\n");

	printf("Answer -\n");
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			printf("%d ", ans2[i][j]);
		}
		printf("\n");
	}
	
	
}
