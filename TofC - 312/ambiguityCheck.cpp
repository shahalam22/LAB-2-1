#include <bits/stdc++.h>
using namespace std;


// bool hasThere(vector<string> v, string s, int i, int j){
//     for(int k=0; k<v.size(); k++){
//         if(v[k][1] == ){
//             return true;
//         }
//     }
// }

string inSymbol(string S){
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

int main(){

    vector<string> productions;
    vector<string> terminals;
    string input;

    // int n;
    
    // cout << "Enter the number of productions: ";
    // cin >> n;

    // for(int i=0; i<n; i++){
    //     string s;
    //     cin >> s;
    //     productions.push_back(s);
    // }

    productions.push_back("S");
    productions.push_back("aS");
    productions.push_back("aSbS");

    terminals.push_back("a");
    terminals.push_back("b");

    cout << "Enter a string: ";
    cin >> input;

    
    for(int i=0; i<productions.size(); i++){
        string S = productions[i];
        string temp = input;
        string innerSsymbol = inSymbol(S);
        // cout << innerSsymbol << endl;
        int posInner = S.find_last_of(innerSsymbol);
        if(temp.find_first_of(innerSsymbol) == string::npos){
            // cout << "String is not accepted by the grammar\n";
            continue;
        }
        string ansTemp = S;
        cout << "LMD : " << ansTemp << "  ";

//leftmost derivation
        for(int i=0; i<temp.size(); i++){
            int j=0;
            for(; j<ansTemp.size(); j++){
                if(ansTemp[j]=='S'){
                    i = j;
                    break;
                }
            }

            for(int k=0; k<productions.size(); k++){
                if(productions[k][0] == temp[i]){
                    ansTemp.replace(j, 1, productions[k]);
                }
                else{
                    ansTemp.replace(j, 1, "");
                }
            }
        

            if(i==(temp.size()-1)){
                cout << ansTemp << "  ";
                ansTemp.replace(i+1, 1, "");
            }

            cout << ansTemp << "  \n";
        }
        
    }
    

}