#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

int maxLength, maxIndex;
list<int> LBar;

//biggest issue with this is that time complexity of this is n*n
void LIS_Naive_DP(int *a, int *L, int *prev, int size){
    L[0] = 0;
    prev[0] = -1;
    maxLength = 0;
    maxIndex = 0;

    for(int i=1; i<size; i++){
        L[i] = 0;
        for(int j=0; j<i; j++){
            if(a[i]>a[j] && L[j]+1 >= L[i]){
                L[i] = L[j] + 1;
                prev[i] = j;
            }
        }
        if(L[i]>maxLength){
            maxLength = L[i];
            maxIndex = i;
        }
    }
}

// void LIS_Fast_DP(int *a, int *L, int *prev, int size){
    
// }

void Print_LIS_Naive_DP(int *a, int *prev, int index){
    if(index==0){
        return;
    }
    Print_LIS_Naive_DP(a, prev, prev[index]);
    cout << a[index] << " ";
}

int main(void){
    int a[] = {0,9,2,5,3,7,11,8,10,13,6};
    int size = sizeof(a)/sizeof(a[0]);
    int L[size] = {0};
    int prev[size] = {0};

    LIS_Naive_DP(a, L, prev, size);
    
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }

    cout << endl;

    for(int i=0; i<size; i++){
        cout << L[i] << " ";
    }

    cout << endl;
    
    for(int i=0; i<size; i++){
        cout << prev[i] << " ";
    }

    cout << endl;

    cout << maxLength << " " << maxIndex << " " << endl;

    cout << "One of the LIS is - " << endl;
    Print_LIS_Naive_DP(a, prev, maxIndex);
}