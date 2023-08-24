#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char c;
    FILE *fp;
    if ((fp = fopen("test_code.c", "r")) == NULL) {
        printf("Error! File cannot be opened.");
        return 0;
    }

    int line = 1;

    char a[2];

    while(c!=EOF){
        c = fgetc(fp);
        //printf("%c", c);
        if(c){
            a[0] = a[1];
            a[1] = c;
        }

        if(!strcmp(a, "//")){
            printf("There is a single line comment in %d line.\n", line);
            while(c != '\n'){
                c = fgetc(fp);
                printf("%c", c);
            }
            printf("\n");
        }else if(!strcmp(a, "/*")){
            printf("There is a multi line comment in %d line.\n", line);
            while(c != '/'){
                if(c==EOF){
                    printf("This is an incomplete multi-line comment!");
                    break;
                }
                printf("%c", c);
                c = fgetc(fp);
            }
            printf("\n\n");
        }

        if(c == '\n') line ++;
    }

    fclose(fp);

    return 0;
}