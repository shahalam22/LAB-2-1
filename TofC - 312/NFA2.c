// NFA code to show all possible path for the string


#include <stdio.h>
#include <string.h>

int a, b, startState, endState;
char ans[100][100];
int m=0, n=0;

int nfaTraversal(int (*trans)[b][a], int state, char *input, int pos){
    if(input[pos]=='\0'){
        if(state == endState){
            // printf("%d ", state);
            ans[m][n] = state + '0';
            
            for(int i=0; i<n; i++){
                ans[m+1][i] = ans[0][i];
            }

            // n--;
            m = m + 1;
            // printf("\nAccepted.\n");
            return 0;
        }else {
            // printf("%d ", state);
            ans[m][0] = '1';
            n--;
            m++;
            // printf("\nRejected.\n");
            return 0;
        }
    }

    int value = input[pos] - '0';
    for(int i=0; i<a; i++){
        if(trans[state][value][i] != -1){
            // printf("%d ", state);
            ans[m][n] = state + '0';
            n++;
            nfaTraversal(trans, trans[state][value][i], input, pos+1);
            n--;
        }
    }

    return 0;
}

int main(){

    //taking general infos
    printf("Enter the number of states : ");
    scanf("%d", &a);
    printf("Enter the number of symbols : ");
    scanf("%d", &b);

    char smbl[b];
    printf("Enter the symbols : ");
    scanf("%s", &smbl);

    //taking transition function from file
    int trans[a][b][a];

    FILE *fp = fopen("nfa.txt", "r");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<a; k++){
                fscanf(fp, "%d", &trans[i][j][k]);
            }
        }
    }
    
    // int startState, endState;
    printf("Enter Starting State: ");
    scanf("%d", &startState);
    printf("Enter Ending State: ");
    scanf("%d", &endState);

    // // Printing transition function
    // for(int i=0; i<a; i++){
    //     for(int j=0; j<b; j++){
    //         for(int k=0; k<a; k++){
    //             printf("%d ", trans[i][j][k]);
    //         }
    //         //printf("\t");
    //     }
    //     //printf("\n");
    // }

    //Taking input of the STRING to be checked
    char str[100];

    while(1){
        printf("\nEnter the String to check : ");
        scanf("%s", &str);

        for(int i=0; i<m; i++){
            memset(ans[i], '\0', sizeof(ans[i]));
        }
        
        m = 0;

        nfaTraversal(trans, 0, str, 0);

        printf("Solutions: ");
        for(int i=0; i<m; i++){
            if(ans[i][0]=='1'){
                continue;
            }
            printf("%s  ", ans[i]);
        }
    }

    return 0;
}