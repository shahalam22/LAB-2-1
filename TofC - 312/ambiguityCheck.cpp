#include <bits/stdc++.h>
using namespace std;

vector<string> productions;
vector<string> terminals;
vector<string> answer;
string input;

void ambiguity(string s, int pos, int j){

    // cout << s << endl;

    string temp;

    for(int i=0; i<s.size(); i++){
        if(s[i]!='S'){
            temp.push_back(s[i]);
        }
    }
   
    if(temp.size()>input.size()){
        return;
    }

    if(temp.size()<=input.size()){
        answer.push_back(s);
    }

    if(temp == input){
        cout << "String is accepted by the grammar\n";
        answer.push_back(temp);
        return;
    }

    for(int i=0; i<productions.size(); i++){
        if(productions[i][0] == input[pos]){
            int posOfS = s.find("S");
            s.replace(posOfS, 1, productions[i]);
            ambiguity(s, pos+1, j+1);
        }
    }
}

int main(){
    productions.push_back("S");
    productions.push_back("aS");
    productions.push_back("aSbS");

    terminals.push_back("a");
    terminals.push_back("b");

    cout << "Enter a string: ";
    cin >> input;
    
    ambiguity("aS", 0, 0);

    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }

}