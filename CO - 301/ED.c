#include <stdio.h>
#include <string.h>

int min(int a, int b, int c){
    if(a<=b && a<=c){
        return a;
    }else if(b<=a && b<=c){
        return b;
    }else return c;
}

int sign[20][20];

void printlcs(char *x, int i, int j){
    if(i==0 || j==0){
        return;
    }
    if(sign[i+1][j+1]==3){
        printlcs(x, i-1, j-1);
        printf("%c  ", x[i]);
    }else if(sign[i+1][j+1]==2){
        printlcs(x, i-1, j);
        printf("%c  ", x[i]);
    }else if(sign[i+1][j+1]==1){
        printlcs(x, i, j-1);
        printf("%c  ", x[i]);
    }else if (sign[i+1][j+1]==4){
        printlcs(x, i-1, j-1);
        // printf("%c  ", x[i]);
    }
}

int main(){
    char str1[100], str2[100];
    printf("Enter str to be replaced: ");
    scanf("%s", str1);
    printf("Enter str to be replaced with: ");
    scanf("%s", str2);

    int i = strlen(str1)+1;
    int j = strlen(str2)+1;

    int c[i][j];

    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            if(n==0){
                c[m][n] = m;
                // sign[m][n] = 2;
            }else if(m==0){
                c[m][n] = n;
                // sign[m][n] = 1;
            }else if(str1[m-1]==str2[n-1]){
                c[m][n] = c[m-1][n-1];
                sign[m][n] = 4;
            }else if(str1[m-1]!= str2[n-1]){
                c[m][n] = min(c[m-1][n-1], c[m-1][n], c[m][n-1]) + 1;
                sign[m][n] = 3;
            }
        }
    }

    printf("%s %s", str1, str2);

    printf("\n");printf("\n");

    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            printf("%d  ", c[m][n]);
        }
        printf("\n");
    }

    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            sign[m][n] = 4;
        }
        
    }

    printf("\n");printf("\n");

    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            if(str1[m-1]!=str2[n-1]){
                int mini = min(c[m-1][n-1], c[m][n-1], c[m-1][n]);
                if(mini==c[m-1][n-1]){
                    sign[m][n] = 3;
                }else if(mini==c[m][n-1]){
                    sign[m][n] = 1;
                }else if(mini==c[m-1][n]){
                    sign[m][n] = 2;
                }
                if(m==0){
                    sign[m][n] = 1;
                } if(n==0){
                    sign[m][n] = 2;
                }
            }
        }
        printf("\n");
    }

    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            printf("%d  ", sign[m][n]);
        }
        printf("\n");
    }

    int nOfEdit = 0, p = i-1, q = j-1;

    while(p==0 && q==0){
        if(sign[p][q]==4){
            p--;
            q--;
        }else if(sign[p][q]==3){
            p--;
            q--;
            nOfEdit++;
        }else if(sign[p][q]==2){
            p--;
            nOfEdit++;
        }else if(sign[p][q]){
            q--;
            nOfEdit++;
        }
    }

    // printf("\nNumber of edit need is %d\n", nOfEdit);
    
    printlcs(str1, i-1, j-1);

    return 0;
}