#include <bits/stdc++.h>
using namespace std;

vector<string> cities;
vector<string> in;
vector<string> out;
vector<string> weight;
vector<string> pi;
vector<int> d;
int transitionMatrix[100][100] = {0};
std::set<string> nodes;

void inputTaking(){
    fstream file;
    string filename, word;
    filename = "dijkstra.txt";
    file.open(filename.c_str());

    int i=1;
    while (file >> word)
    {
        if(i%3 != 0){
            nodes.insert(word);
        }
        i++;
    }
    file.close();
    // pushing nodes in cities matrix
    for(auto i:nodes){
        cities.push_back(i);
    }
}

int findIndex(string str){
    for(int i=0; i<cities.size(); i++){
        if(cities.at(i)==str){
            return i;
        }
    }
    return -1;
}

void creating_Transition_Matrix(){
    fstream file;
    string filename, word;
    filename = "dijkstra.txt";
    file.open(filename.c_str());

    while (file>>word)
    {
        in.push_back(word);
        file >> word;
        out.push_back(word);
        file >> word;
        weight.push_back(word);
    }
    file.close();

    for(int i=0; i<in.size(); i++){
        transitionMatrix[findIndex(in.at(i))][findIndex(out.at(i))] = stoi(weight.at(i));
    }
}

// int extract_min(vector<int> list){
//     int min = INT16_MAX;
//     for(int i=0; i<list.size(); i++){
//         if(list.at(i) < min){
//             min = list.at(i);
//         }
//     }
//     return min;
// }

void initialize_single_source(int s){
    for(int i=0; i<d.size(); i++){
        d[i] = INT_MAX;
        pi[i] = '\0';
    }
    d[s] = 0;
}

int main(){
    inputTaking();
    creating_Transition_Matrix();

    // for(auto i:cities){
    //     cout << i << endl;
    // }

    // cout << endl;

    // for(auto i:in){
    //     cout << i << endl;
    // }

    // cout << endl;

    // for(auto i:out){
    //     cout << i << endl;
    // }

    // cout << endl;

    // for(auto i:weight){
    //     cout << i << endl;
    // }

    cout << "\nTransition Matrix\n" << endl;
    for(int i=0; i<cities.size(); i++){
        for(int j=0; j<cities.size(); j++){
            cout << transitionMatrix[i][j] << " ";
        }
        cout << endl;
    }


}