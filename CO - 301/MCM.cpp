#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

string input;
int m[10][10], s[10][10];

// recursive-matrix-chain
int rmc(int p[], int i, int j){
    if(i==j){
        m[i][j] = 0;
        return m[i][j];
    }
    m[i][j] = INT_MAX;

    for(int k=i; k<j; k++){
        int q = rmc(p, i, k) + rmc(p, k+1, j) + (p[i]*p[k+1]*p[j+1]);
        if(q<m[i][j]){
            m[i][j] = q;
            s[i][j] = k; //ekhane k+1 dile slide er moto ans ashe kintu slide e index 1 theke ar amar index 0 theh=ke tai k ei deya hoise.
        }
    }
    return m[i][j];
}

// printing optimal parenthesis
void printOptimalP(int p[], int i, int j){
    if(i==j){
        cout << "A" << i+1; 
    }else{
        cout << "(";
        printOptimalP(p, i, s[i][j]);
        cout << "x";
        printOptimalP(p, s[i][j]+1, j);
        cout << ")";
    }
}

// matrix-chain-order
void mco(int p[], int len){

    len = len -1;
    cout << len << "\n";
    
    for(int i=0; i<=len; i++){
        m[i][i] = 0;
    }

    for(int l=1; l<=len; l++){
        for(int i = 0; i<len-l+1; i++){
            int j = i + l;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q = m[i][k] + m[k+1][j] + (p[i]*p[k+1]*p[j+1]);
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// memorized Matrix Chain
int lookUp(int p[], int i, int j){
    if (m[i][j] < INT_MAX) return m[i][j];

    if( i==j ){
        m[i][j] = 0;
    }else{
        for(int k=i; k<j; k++){
            int q = lookUp(p, i, k) + lookUp(p, k+1, j) + (p[i]*p[k+1]*p[j+1]);
            if( q < m[i][j]){
                m[i][j] = q;
                s[i][j] = k;
            }
        }
    }

    return m[i][j];
}


void mem(int p[], int len){
    int n = len -1;
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            m[i][j] = INT_MAX;
        }
    }
    
    lookUp(p, 0, n);
}


int main(void){
    
    int input[] = {10,5,1,10,2,10};
    int len = sizeof(input)/(sizeof(int))-1;

    // rmc(input, 0, len-1);

    // mco(input, len);

    // mem(input, len);

    // for(int j=0; j<len; j++){
    //     for(int i=0; i<len; i++){
    //         cout << m[j][i] << "\t";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // for(int j=0; j<len; j++){
    //     for(int i=0; i<len; i++){
    //         cout << s[j][i] << "\t";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    printOptimalP(input, 0, len-1);

    return 0;
}