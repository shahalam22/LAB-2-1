#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int a, b;
int m = 0, n;
string smbl, sState, eState;
string transitionDFA[20][2];
string states[20];

//checking if the state is declared as state before or not
bool checkValid(string states[], string state){
    for(int i=0; i<n; i++){
        if(states[i]==state){
            return true;
        }
    }
    return false;
}

// removing duplicate values from the string that made inside addNewState() function
string removeduplicate(string str, int f){
   int index=0;
   for (int i=0;i<f;i++){
        int j;
        for(j=0;j<i;j++){
            if(str[i]==str[j]){
               break;
            }
        }
        if(j==i){
            str[index++]=str[i];
        }
   }
   return str.substr(0, index);
}

//find state 
int findState(char h){
    string temp;
    temp += h;
	for(int i=0; i<n; i++){
		if(states[i].compare(temp)){
			return i+1;
		}
	}
	return -1;
}

//adding new state to the dfa that not been included before
string addNewState(string state, int i){

    string indxToAdd;
    for(int k=0; k<b; k++){
	    for(int j=0; j<state.size(); j++){
    		int indx = findState(state[j]);
    		indxToAdd = indxToAdd + (transitionDFA[indx][k]);
    	}
    }
    indxToAdd = removeduplicate(indxToAdd, indxToAdd.size());
    return indxToAdd;
}

int main(){  

    //taking general infos
    cout << "Enter the number of states of NFA : " << endl;
    cin >> a;
    n = a;
    cout << "Enter the number of symbols of NFA : " << endl;
    cin >> b;
    cout << "Enter the symbols of NFA : " << endl;
    cin >> smbl;
    cout << "Enter the starting state of NFA : " << endl;
    cin >> sState;
    cout << "Enter the ending state of NFA : " << endl;
    cin >> eState;

    string transitionNFA[a][b];
    //string transitionDFA[20][2];
    //string states[20];

    //reading transition table of NFA from File
    fstream file;
    file.open("1439.txt", ios::in);
    if(file.is_open()){
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                getline(file, transitionNFA[i][j]);
                transitionDFA[i][j] = transitionNFA[i][j];
            }
            states[i] = i + '0';
        }
        file.close();
    }

    //finding and adding the states that not been added before in the DFA
    for(int i=0; i<n; i++){
        for(int j=0; j<b; j++){
            if(!checkValid(states, transitionDFA[i][j])){
                for(int k=0; k<b; k++){
                    states[n] = transitionDFA[i][j];
                    transitionDFA[n][k] = addNewState(transitionDFA[i][j], k);
                }
                n++;
            }
        }
    }
    
    //printing states of the dfa
    cout << "\nStates of the DFA is - ";
    for(int i=0; i<n; i++){
    	cout << states[i] << " ";
    }
    cout << "\n";

    //Printing DFA
    cout << "\nDFA's transition function table is -\n\n";
    for(int i=0; i<n; i++){
        cout << states[i] << "\t";
        for(int j=0; j<b; j++){
            cout << transitionDFA[i][j] << "\t";
        }
        cout << endl;
    }
    
    //printing starting state and ending state
    cout << "\nStarting state of DFA is - " << sState << "\n";
    
    cout << "\nAcceptance state of DFA is - ";
    for(int i=0; i<n; i++){
    	if(states[i].find(eState) != -1){
    		cout << states[i] << " ";
    	}
    }
    cout << "\n";
    
    
    return 0;
}
