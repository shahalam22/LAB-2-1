#include <stdio.h>
#include <stdlib.h>

int len(char* str){
    int i = 0;
    for(;;i++){
        if(str[i]=='\0') break;
    }
    return i;
}

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

void printStr(char str[], int leng, int k, char *str2, int strLen){
    if(strLen == k){
        printf("%s  \n", str2);
        return;
    }

    for(int i=0; i<leng; i++){
        str2[strLen] = str[i];
        str2[strLen+1] = '\0';
        printStr(str, leng, k, str2, strLen+1); 
    }

    return;
}

int main(){

	char str[] = "01";
	
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

    //printing permutation of all
    int k;
    printf("Enter K : ");
    scanf("%d", &k);
    char str3[k+1];
    printStr(str, len(str), k, str3, 0);
	
	return 0;
}