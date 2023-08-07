#include <stdio.h>
#include <stdlib.h>

char arr[] = {'0', '1'};

char* str5;

//b
int len(char* str){
    int i = 0;
    for(;;i++){
        if(str[i]=='\0') break;
    }
    return i;
}

//c
int check(char *str){
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]!='0' && str[i]!='1'){
			return 0;
		}
	}	
	return 1;
}

//d
void concat(char str1[], char str2[]){
	char str3[100];
   
    int l1 = len(str1);
    int l2 = len(str2);
    
    for(int i=0; i<l1; i++){
    	str3[i] = str1[i];
    }
    
    for(int i=0; i<l2; i++){
    	str3[i+l1] = str2[i];
    }
    
    str3[l1+l2] = '\0';
    
    printf("concatenated string is - %s\n", str3);
   
}

int main(){

    for(int j=0; j<5; j++){
    
        int length = rand()%15 + 2;
        char str[length];
    
        for(int i=0; i<length; i++){
            str[i] = '0';
            int index = rand()%2;
            str[i] = arr[index];
        }
    
        str[length] = '\0';
        printf("%s\n", str);
        printf("Length of this string is : %d\n\n", len(str));
    
    }
    
    //check whether entered string is built of the alphabtes
    char str2[100];
    
    printf("Enter String - ");
    scanf("%s", str2);
    
    int a = check(str2);
    
    if(a==1){
    	printf("True\n\n");
    }else {
    	printf("False\n\n");
    }
    
    //concatenating two string
    char str3[100], str4[100];
    
    printf("First String - ");
    scanf("%s", &str3);
    printf("\n");
    
    printf("First String - ");
    scanf("%s", &str4);
    printf("\n");

    concat(str3, str4);
    
    return 0;
}












