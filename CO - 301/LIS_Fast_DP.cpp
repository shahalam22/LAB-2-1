#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int LIS_fast_DP(int *a, int *L, int *L_prime, int *prev, int size){
    int len = 0;
    L[0] = INT_MIN;
    L_prime[0] = -1;
    prev[0] = -1;

    for(int i=1; i<size; i++){
        if(L[len] < a[i]){
            L[++len] = a[i];
            L_prime[len] = i;
            prev[i] = L_prime[len-1];
        }else {
            int s = 0;
            int h = len;
            while(s<h){
                int m = (s+h)/2;
                if(L[m]<a[i]){
                    s = m+1;
                }else {
                    h = m;
                }
            }
            L[s] = a[i];
            L_prime[s] = i;
            prev[i] = L_prime[s-1];
        }
    }
    return len;
}

void print_LIS(int *a, int *prev, int index){
    if(prev[index]==-1){
        ans += a[index];
        cout << a[index] << " ";
        return;
    }
    print_LIS(a, prev, prev[index]);
    ans += a[index];
    cout << a[index] << " ";
}

int main(void){
    int a[] = {0,2,5,3,6,1,2,10,7,9};
    int size = sizeof(a)/sizeof(a[0]);
    int L[size]={INT_MIN}, prev[size] = {INT_MIN}, L_prime[size];


    int len = LIS_fast_DP(a, L, L_prime, prev, size);


    // cout << "a - ";    
    // for(int i=0; i<size; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // cout << "L - ";
    // for(int i=0; i<size; i++){
    //     cout << L[i] << " ";
    // }
    // cout << endl;

    // cout << "L_prime - ";
    // for(int i=0; i<size; i++){
    //     cout << L_prime[i] << " ";
    // }
    // cout << endl;

    // cout << "prev - ";
    // for(int i=0; i<size; i++){
    //     cout << prev[i] << " ";
    // }
    // cout << endl;

    cout << "LIS is - ";
    print_LIS(a, prev, size-1);
    cout << endl;

    cout << "Max value is - " << ans << endl;
}