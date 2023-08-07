#include <stdio.h>

int n;

struct activitySelection{
    char name[100];
    int startTime;
    int finishTime;
    int compatibility;
} activity[100];

//sorting activity according to finishing time
void sorting(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(activity[i].finishTime < activity[j].finishTime){
                struct activitySelection temp = activity[i];
                activity[i] = activity[j];
                activity[j] = temp; 
            }
        }
    }
}

//iterative algorithm
void iterative(){
    struct activitySelection k = activity[0];
    printf("%s  ", k.name);
    for(int i=1; i<n; i++){
        if(activity[i].startTime>k.finishTime){
            k = activity[i];
            printf("%s  ", k.name);
        }
    }
}

//recursive algorithm
void recursive(int i){
    if(i>=n){
        return;
    }
    printf("%s  ", activity[i].name);
    int j = i+1;
    for(; j<n; j++){
        if(activity[j].startTime>activity[i].finishTime){
            break;    
        }
    }
    return recursive(j);
}

int main(){

    FILE *fp = fopen("activitySelection.txt", "r");
    fscanf(fp, "%d", &n);

    // reading values from file
    for(int i=0; i<n; i++){
        fscanf(fp, "%s %d %d", &activity[i].name, &activity[i].startTime, &activity[i].finishTime);
    }

    // sorting according to finishTime
    sorting();

    // for(int i=0; i<n; i++){
    //     printf("%s %d %d\n", activity[i].name, activity[i].startTime, activity[i].finishTime);
    // }
    // printf("%d", n);

    iterative();

    printf("\n");

    recursive(0);

    return 0;
}