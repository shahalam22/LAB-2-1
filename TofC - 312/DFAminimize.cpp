#include <bits/stdc++.h>
using namespace std;

int numOfStates, nOfEndingState, numOfSymbol;
char ss, es[10];
char states[10];
// char matchedStates[10];


bool isEndState(char a){
    for(int i=0; i<nOfEndingState; i++){
        if(a == es[i]) return true;
    }
    return false;
}


int main(){

    // cout << "Enter number of states: ";
    // cin >> numOfStates;

    // cout << "Enter states: ";
    // for(int i=0; i<numOfStates; i++){
    //     cin >> states[i];
    // }

    // cout << "Enter number of symbol: ";
    // cin >> numOfSymbol;

    // cout << "Enter starting state: ";
    // cin >> ss;

    // cout << "Enter number ending states: ";
    // cin >> nOfEndingState;

    // for(int i=0; i<nOfEndingState; i++){
    //     cout << "Enter " << i+1 << "th ending state: ";
    //     cin >> es[i];
    // }



    fstream file;
    file.open("practice.txt");


    file >> numOfStates;
    for(int i=0; i<numOfStates; i++){
        file >> states[i];
    }
    file >> numOfSymbol;
    file >> ss;
    file >> nOfEndingState;
    for(int i=0; i<nOfEndingState; i++){
        file >> es[i];
    }


    char transitionMatrix[numOfStates][numOfSymbol];
    char table[numOfStates][numOfStates];
    char modifiedTable[numOfStates][6];

    
    for(int i=0; i<numOfStates; i++){
        for(int j=0; j<numOfSymbol; j++){
            file >> transitionMatrix[i][j];
        }
    }
    file.close();

    for(int i=0; i<numOfStates; i++){
        modifiedTable[i][0] = transitionMatrix[i][0];
        modifiedTable[i][1] = transitionMatrix[i][1];
        modifiedTable[i][2] = transitionMatrix[transitionMatrix[i][0]-'a'][0];
        modifiedTable[i][3] = transitionMatrix[transitionMatrix[i][0]-'a'][1];
        modifiedTable[i][4] = transitionMatrix[transitionMatrix[i][1]-'a'][0];
        modifiedTable[i][5] = transitionMatrix[transitionMatrix[i][1]-'a'][1];
    }


    // for(int i=0; i<numOfStates; i++){
    //     for(int j=0; j<6; j++){
    //         cout << modifiedTable[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    //table filling
    for(int i=0; i<numOfStates; i++){
        for(int j=0; j<i; j++){
            if((isEndState(modifiedTable[i][0])==isEndState(modifiedTable[j][0])) && (isEndState(modifiedTable[i][1])==isEndState(modifiedTable[j][1])) && (isEndState(modifiedTable[i][2])==isEndState(modifiedTable[j][2])) && (isEndState(modifiedTable[i][3])==isEndState(modifiedTable[j][3])) && (isEndState(modifiedTable[i][4])==isEndState(modifiedTable[j][4])) && (isEndState(modifiedTable[i][5])==isEndState(modifiedTable[j][5])) && (isEndState(states[i])==isEndState(states[j]))){
                table[i][j] = '=';
            }else{
                table[i][j] = 'x';
            }
        }
    }

    //print table
    for(int i=0; i<numOfStates; i++){
        cout << states[i] << ": ";
        for(int j=0; j<i; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << "   ";
    for(int i=0; i<numOfStates; i++){
        cout << states[i] << " ";
    }
    cout << endl;

}