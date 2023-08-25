#include <iostream>
using namespace std;

int maxi;

void MaxSumInterval(int *a, int *sum, int *prev, int size){
    sum[0] = 0;
    maxi = 0;
    for(int i=1; i<size; i++){
        sum[i] = sum[i-1] + a[i];
        prev[i] = i-1;
        if(sum[i]>sum[maxi]){
            maxi = i;
        }
        if(a[i]>=sum[i]){
            sum[i] = a[i];
            prev[i] = 0;
        }
    }
}

void Print_MaxSumInterval(int *a, int *prev, int i){
    if(prev[i]==0){
        cout << a[i];
        return;
    }
    Print_MaxSumInterval(a, prev, i-1);
    cout << a[i] << " ";
}

int main(void){
    int a[] = {0,2,-5,9,-3,1,7,-15,2,3};
    int size = sizeof(a)/sizeof(a[0]);
    int sum[size] = {0};
    int prev[size] = {0};

    MaxSumInterval(a, sum, prev, size);

    Print_MaxSumInterval(a, prev, maxi);
}