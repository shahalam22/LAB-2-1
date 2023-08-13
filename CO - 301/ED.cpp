// Code for Edit Distance (LEVENSHTEIN)

#include <iostream>
#include <string>
using namespace std;

//here we will use 1 as Insert sign, 2 as Delete sign, 3 as Replace sign, 4 as No edit sign

int min(int a, int b, int c){
    if(a<=b && a<=c){
        return a;
    }else if(b<=a && b<=c){
        return b;
    }else return c;
}

int sign[15][15];
string str1, str2;

void print_ED(int i, int j){
    //base case
    if(i==0 || j==0){
        if(j==0 && sign[i][j] == 2){
            while(i!=0){
                cout << "Delete " << str1[i-1] << "\n";
                i--;
            }
            return;
        }
        else if(i==0 && sign[i][j]==1){
            while(j!=0){
                cout << "Insert " << str2[j-1] << "\n";
                j--;
            }
            return;
        }
        // else return;
    }

    if(sign[i][j]==3){
        print_ED(i-1, j-1);
        cout << "Replace " << str1[i-1] << " by " << str2[j-1] << "\n";
    }else if(sign[i][j]==2){
        print_ED(i-1, j);
        cout << "Delete " << str1[i-1] << "\n";
    }else if(sign[i][j]==1){
        print_ED(i, i-1);
        cout << "Insert " << str2[i] << "\n";
    }else print_ED(i-1, j-1);
}

int main(void){

    //getting strings from user
    cout << "Enter string to be converted: ";
    cin >> str1;
    cout << "Enter string to which other string will be converted : ";
    cin >> str2;

    int m = str1.size() + 1, n = str2.size() + 1;

    int c[m][n];

    // Computing & Entering values to c[][] and sign[][] matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0){
                c[i][j] = j;
                sign[i][j] = 1;
            }
            else if(j==0){
                c[i][j] = i;
                sign[i][j] = 2;
            }
            else if(str1[i-1] == str2[j-1]){
                c[i][j] = c[i-1][j-1];
                sign[i][j] = 4;
            }
            else if(str1[i-1] != str2[j-1]){
                // cout << i << j << min(c[i-1][j-1], c[i-1][j], c[i][j-1]) << "(" << c[i-1][j-1] << "," << c[i-1][j] << "," << c[i][j-1] << ")" << " ";
                c[i][j] = min(c[i-1][j-1], c[i-1][j], c[i][j-1]) + 1;

                if(c[i][j] == c[i-1][j-1] + 1){
                    sign[i][j] = 3;
                }else if(c[i][j] == c[i-1][j]+1){
                    sign[i][j] = 2;
                }else if(c[i][j] == c[i][j-1] + 1){
                    sign[i][j] = 1;
                }
            }
        }
        // cout << "\n";
    }

    sign[0][0] = 0;

    // Printing c[][] matrix
    cout << "\nC matrix of length: \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }

    // Printing sign[][] matrix
    cout << "\nsign matrix : \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << sign[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    cout << "Sequence of edit operations needed to convert " << str1 << " to " << str2 << "-" << endl;
    print_ED(m, n);

    return 0;
}