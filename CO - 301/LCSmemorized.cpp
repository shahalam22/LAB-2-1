#include <iostream>
using namespace std;

string str1, str2;

int table[10][10];
char table2[10][10];

int max(int a, int b){
    if(a>=b) return a;
    return b;
}

void printLCS(string str1, int len1, int len2){
    if(len1 == 0 || len2==0) return;
    if(table2[len1-1][len2-1]=='D'){
        printLCS(str1, len1-1, len2-1);
        cout << str1[len1-1];
    }else if(table2[len1-1][len2-1]=='U'){
        printLCS(str1, len1-1, len2);
    }else if(table2[len1-1][len2-1]=='L'){
        printLCS(str1, len1, len2-1);
    }
}

int LCS(string str1, string str2, int len1, int len2){
    if(len1<0 || len2<0){
        return 0;
    }
    if(table[len1][len2]!=-1){
        return table[len1][len2];
    }
    else{ 
        if(str1[len1]==str2[len2]){
            table2[len1][len2] = 'D';
            table[len1][len2] = 1 + LCS(str1, str2, len1-1, len2-1); 
            return table[len1][len2];
        }
        else {
            table[len1][len2] = max(LCS(str1, str2, len1-1, len2), LCS(str1, str2, len1, len2-1));
            if(max(LCS(str1, str2, len1-1, len2), LCS(str1, str2, len1, len2-1))==table[len1-1][len2]){
                table2[len1][len2] = 'U';
            }else{
                table2[len1][len2] = 'L';
            }
            return table[len1][len2];
       }
    }

}

int main(){
    str2 = "bdcaba";
    str1 = "abcbdab";

    int len1 = str1.size();
    int len2 = str2.size();

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            table[i][j] = -1;
            table2[i][j] = 'x';
        }
    }

    int len = LCS(str1, str2, len1-1, len2-1);

    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            cout << table2[i][j] << " ";
        }
        cout << "\n";
    }

    printLCS(str1, len1, len2);

    cout << "\nLength of LCS is :" << len << endl;

}
