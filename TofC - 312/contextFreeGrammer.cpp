#include <bits/stdc++.h>
using namespace std;

vector<string> productions;
vector<string> terminals;

string term = "P";

int findP(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'P'){
            return i;
        }
    }
    return -1;
}

void termRegenarate(char c){
    string temp = "";
    for(int i=0; i<term.size(); i++){
        if(term[i] == 'P'){
            temp += c;
            temp += 'P';
            temp += c;
        }else{
            temp += term[i];
        }
    }
    term = temp;
}


int main(){
    productions.push_back("e");
    productions.push_back("0");
    productions.push_back("1");
    productions.push_back("0P0");
    productions.push_back("1P1");

    string input;
    cout << "Enter the input string: ";
    cin >> input;

    terminals.push_back(term);

    while(input.size()>0){
        for(int i=0; i<productions.size(); i++){
            if(input == productions[i]){
                cout << "String accepted" << endl;
                term[findP(term)] = productions[i][0];
                terminals.push_back(term);

                //print path
                cout << "Path: ";
                for(int i=0; i<terminals.size()-1; i++){
                    cout << terminals[i] << " -> ";
                }
                cout << terminals[terminals.size()-1] << endl;

                return 0;
            }
            else if(input[0] == productions[i][0] && input[input.size()-1] == productions[i][productions[i].size()-1]){
                input = input.substr(1, input.size()-2);
                // terminals.push_back(productions[i]);
                termRegenarate(productions[i][0]);
                terminals.push_back(term);
                break;
            }
            else{
                if(i==productions.size()-1){
                    cout << "String is not accepted" << endl;
                    return 0;
                }
            }
        }
    }
}