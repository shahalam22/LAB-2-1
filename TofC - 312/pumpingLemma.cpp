#include <bits/stdc++.h>
using namespace std;

bool isInLanguage(string w, char s1, string s2, char s3, int pOfs1, int pOfs3){
    int count1 = 0, count3 = 0;
    int s2pos = w.find(s2);
    // cout << "s2pos = " << s2pos << endl;
    // cout << "s2pos + s2.length() = " << s2pos + s2.length() << endl;
    if(s2pos == string::npos){
        return false;
    }
    for(int i=0; i<s2pos; i++){
        if(w[i] != s1 && i!=s2pos-1){
            return false;
        }
        else if(w[i] == s1){
            count1++;
        }
    }    
    for(int i=s2pos+s2.length(); i<w.length(); i++){
        if(w[i] != s3 && i!=w.length()-1){
            return false;
        }
        else if(w[i] == s3){
            count3++;
        }
    }
    if(count1 == count3){
        return true;
    }else return false;
}

int main(){
    srand(time(NULL));

    int n, x, y, z, pOfs1 = 1, pOfs3 = 1;
    char pOfs1char, pOfs3char;
    char s1, s3, userAns;
    string s2;

    string input[3];
    cout << "Is there any intermidiate w? (y/n): ";
    cin >> userAns;
    if(userAns == 'y' || userAns == 'Y'){
        cout << "Enter the language: ";
        cin >> input[0] >> input[1] >> input[2];
    }else{
        cout << "Enter the language: ";
        cin >> input[0] >> input[2];
        input[1] = "";
    }

// persing the input
    int s = 0;
    while(input[0][s]!='\0'){
        if(input[0][s] == '^'){
            s1 = input[0].substr(0, s)[0];
            if(isdigit(input[0][s+1])){
                pOfs1 = input[0][s+1] - '0';
                pOfs1char = input[0][s+2];
            }else{
                pOfs1char = input[0][s+1];
            }
        }
        s++;
    }
    s2 = input[1];
    int v = 0;
    while(input[2][v]!='\0'){
        if(input[2][v] == '^'){
            s3 = input[2].substr(0, v)[0];
            if(isdigit(input[2][v+1])){
                pOfs3 = input[2][v+1] - '0';
                pOfs3char = input[2][v+2];
            }else{
                pOfs3char = input[2][v+1];
            }
        }
        v++;
    }
// persing ends

    n = rand()%10 + 2;

// printing the persed values
    cout << "s1 = " << s1 << endl;
    cout << "pOfs1 = " << pOfs1 << pOfs1char << endl;
    // cout << "pOfs1char = " << pOfs1char << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    // cout << "pOfs3 = " << pOfs3 << pOfs3char << endl;

    pOfs1 = pOfs1*n;
    pOfs3 = pOfs3*n;

    string w = "";

    for(int i=0; i<pOfs1; i++){
        w += s1;
    }
    w += s2;
    for(int i=0; i<pOfs3; i++){
        w += s3;
    }

    cout << "w = " << w << endl;

    y = rand()%n + 1;
    x = n-y;
    z = w.length() - n;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    string u1 = w.substr(0, x);
    string u2 = w.substr(x, y);
    string u3 = w.substr(x+y, z);

    cout << "u1 = " << u1 << endl;
    cout << "u2 = " << u2 << endl;
    cout << "u3 = " << u3 << endl;


    int k=0;

    while(1){
        string check = u1;
        for(int i=0; i<k; i++){
            check += u2;
        }
        check += u3;
        cout << "check = " << check << endl;
        bool ans = isInLanguage(check, s1, s2, s3, pOfs1, pOfs3);
        if(!ans){
            cout << "This is not a Regular Language" << endl;
            break;
        }
        k++;
    }
}