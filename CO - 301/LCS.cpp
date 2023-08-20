#include <iostream>
using namespace std;

string str1, str2;
int c[15][15], sign[15][15];

// max() function to find the maximum one from two integer
int max(int a, int b){
    if(a>b){
        return a;
    }else return b;
}

// prints LCS from two strings
void prinLCS(string str, int i, int j){
    if(i==0 || j==0){
        return;
    }
    
    if(sign[i][j] == 3){
        prinLCS(str, i-1, j-1);
        cout << str[i-1];
    }else if(sign[i][j] == 2){
        prinLCS(str, i-1, j);
    }else{
        prinLCS(str, i, j-1);
    }
}

// main() function
int main(void){

    // taking general infos
    cout << "Enter first string: " << endl;
    cin >> str1;
    cout << "Enter second string: " << endl;
    cin >> str2;

    int m = str1.size() + 1, n = str2.size() + 1;

    // entering values to the c[][] matrix and sign[][] matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0){
                c[i][j] = 0;
            }else if(str1[i-1] == str2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            }else if(str1[i-1] != str2[j-1]){
                c[i][j] = max(c[i][j-1], c[i-1][j]);
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j ==0){
                sign[i][j] = 0;
            }else if(str1[i-1] == str2[j-1]){
                sign[i][j] = 3;
            }else if(c[i-1][j]>=c[i][j-1]){
                sign[i][j] = 2;
            }else{
                sign[i][j] = 1;
            }
        }
    }

    // printing values of c[][] matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    // printing values of sign[][] matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << sign[i][j] << " ";
        }
        cout << "\n";
    }

    prinLCS(str1, str1.size(), str2.size());

    return 0;
}