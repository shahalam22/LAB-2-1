// NFA that shows only one path and "Accepted" or "Rejected" messege


#include<stdio.h>

int a, b, startState, endState;

int nfaTraversal(int trans[a][b][a], int state, char *input, int pos){
    if(input[pos]=='\0'){
        if(state == endState){
            printf("%d ", state);
            printf("\nAccepted.\n");
            return 0;
        }else {
            printf("%d ", state);
            printf("\nRejected.\n");
            return 0;
        }
    }

    printf("%d ", state);
    int value = input[pos] - '0';
    for(int i=0; i<a; i++){
        if(trans[state][value][i] != -1){
            // printf("%d ", state);
            return nfaTraversal(trans, trans[state][value][i], input, pos+1);
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

    //Taking input of the STRING to be checked
    char str[100];

    while(1){
            
        printf("Enter the String to check : ");
        scanf("%s", &str);

        nfaTraversal(trans, 0, str, 0);
    }

    return 0;
}