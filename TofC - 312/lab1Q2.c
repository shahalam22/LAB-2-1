#include <stdio.h>
#include <stdlib.h>

int len(char* str){
    int i = 0;
    for(;;i++){
        if(str[i]=='\0') break;
    }
    return i;
}

/*int d2b(int num){
	int i=0;
	while(num!=0){
		int k = num%2;
		i = i*10 + k;
		num = num/2;
	}
	
	return i;
}*/

int isPal(char str[]){
	int a = len(str);
	int i=0, j=a;
	
	while(i<=j){
		if(str[i]!=str[a-i-1]){
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

/*void lastOne(int k){
	int a = pow(2, k);
	for(int i=0; i<a; i++){
		num[i] = d2b(i);
	}
}*/

int main(){

	char str[] = {'0','1'};
	
	
	//palindrom
	
	char str1[100];
	
	printf("Enter number - ");
	scanf("%s", str1);
	
	int pal = isPal(str1);
	
	if(pal==1){
    	printf("True\n\n");
    }else {
    	printf("False\n\n");
    }
    
    //enter k value
    /*int k;
    
    printf("Enter the value of K - ");
    scanf("%d", &k);
    
    lastOne(k);
    
    for(int i=0; i<pow(2, k); i++){
    
    	printf("%d\n", num[i]);
    }*/
	
	return 0;
}



