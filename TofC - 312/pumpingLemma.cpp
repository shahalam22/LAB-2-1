#include <bits/stdc++.h>
using namespace std;

bool isInLanguage(string w, char s1, string s2, char s3, int pOfs1, int pOfs3){
    int count1 = 0, count3 = 0;
    // int s2pos = w.find(s2);
    // cout << "s2pos = " << s2pos << endl;
    // cout << "s2pos + s2.length() = " << s2pos + s2.length() << endl;
    // if(s2pos == string::npos){
    //     return false;
    // }
    // for(int i=0; i<s2pos; i++){
    //     if(w[i] != s1 && i!=s2pos-1){
    //         return false;
    //     }
    //     else if(w[i] == s1){
    //         count1++;
    //     }
    // }    
    // for(int i=s2pos+s2.length(); i<w.length(); i++){
    //     if(w[i] != s3 && i!=w.length()-1){
    //         return false;
    //     }
    //     else if(w[i] == s3){
    //         count3++;
    //     }
    // }
    // if(count1 == count3){
    //     return true;
    // }else return false;

    for(int i=0; i<w.length(); i++){
        if(w[i] == s1){
            if(count3 > 0){
                return false;
            }else {
                count1++;
            }
        }
        if(w[i] == s3){
            count3++;
        }
    }

    if(count1!=count3){
        return false;
    }

    return true;
}

int main(){
    srand(time(NULL));

    int n, x, y, z;
    n = rand()%10 + 2;

    char s1 = '0';
    int pOfs1 = n;
    string s2 = "01";
    char s3 = '1';
    int pOfs3 = n;

    cout << "s1 = " << s1 << endl;
    cout << "pOfs1 = " << pOfs1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "pOfs2 = " << pOfs3 << endl;

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