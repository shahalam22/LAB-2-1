#include <bits/stdc++.h>
using namespace std;

string inSymbol(vector<string> symbols, string S){
    for(int i=0; i<S.size(); i++){
        if(S[i] == 'a'){
            return "a";
        }
        else if(S[i] == 'b'){
            return "b";
        }
    }
    return "";
}

bool hasThere(vector<string> v, char s){
    for(int i=0; i<v.size(); i++){
        if(v[i][0] == s){
            return true;
        }
    }
    return false;
}

int main(){
    vector<string> productions;
    // productions.push_back("S");
    productions.push_back("aS");
    productions.push_back("aSbS");

    vector<string> symbols;
    symbols.push_back("a");
    symbols.push_back("b");

    vector<string> veriables;
    veriables.push_back("S");

    string input;
    cout << "Enter a string: ";
    cin >> input;

    string S = productions[1];

    string temp = input;
    string innerSsymbol = inSymbol(symbols, S);
    int posInner = S.find_last_of(innerSsymbol);
    string ansTemp = S;
    cout << "LMD : " << ansTemp << "  ";
    
    for(int i=0; i<temp.size(); i++){
        int j=0;
        for(; j<ansTemp.size(); j++){
            if(hasThere(veriables, ansTemp.at(j))){
                i = j;
                break;
            }
        }

        if(temp[i]=='S'){
            
        }

    }

}