#include <stdio.h>
#include <string.h>

int main(){
    int n, m, i, j, k, p;

    printf("Enter Number of states: ");
    scanf("%d", &n);

    int states[n];

    printf("Enter Number of symbols: ");
    scanf("%d", &m);

    char symbols[m];

    printf("Enter the symbols:");
    scanf("%s", &symbols);

    int transitionFunction[n][m];

    printf("Enter the transition function: \n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d x %c = ", i, symbols[j]);
            scanf("%d", &transitionFunction[i][j]);
        }
    }

    int startState, nOfe;
    printf("Enter starting state: \n");
    scanf("%d", &startState);

    printf("How many ending points are there?\n");
    scanf("%d", &nOfe);
    int endState[nOfe];
    for(p=0; p<nOfe; p++){
        printf("Enter %d-th ending state: \n", p+1);
        scanf("%d", &endState[p]);
    }

    char string[100];

    int l;
    for(l=0; ;l++){
        printf("Enter the string: ");
        scanf("%s", string);

        int currentState = startState;
        char* ptr = &string;

        printf("Path is : ");

        while (*ptr != '\0') {
            currentState = transitionFunction[currentState][*ptr - 48];
            printf("%d ", currentState);
            ptr++;
        }

        printf("\n");

        int flag = 0;

        for(i=0; i<nOfe; i++){
            if(currentState==endState[i]){
                flag=1;
            }
        }

        if(flag==1){
            printf("Accepted!!\n\n");
        }else{
            printf("Rejected!!\n\n");
        }

    }

    return 0;
}
