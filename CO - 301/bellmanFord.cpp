#include <bits/stdc++.h>
using namespace std;

vector<string> source;
vector<string> destination;
vector<int> weight;
set<string> vertices;

int d[100];
string pi[100];

int get_index(string node){
    int i=0;
    for(auto n: vertices){
        if(n == node){
            return i;
        }
        i++;
    }
    return -1;
}

void printPath(string s){
    if(s == "NIL"){
        return;
    }
    printPath(pi[get_index(s)]);
    cout<<s<<" ";
}

void bellmanFord(string starting_node){
    for(int i=0; i<vertices.size(); i++){
        d[i] = INT_MAX;
        pi[i] = "NIL";
    }
    d[get_index(starting_node)] = 0;

    for(int i=1; i<=vertices.size()-1; i++){
        for(int j=0; j<source.size(); j++){
            if((d[get_index(source[j])] != INT_MAX) && (d[get_index(destination[j])] > d[get_index(source[j])] + weight[j])){
                d[get_index(destination[j])] = d[get_index(source[j])] + weight[j];
                pi[get_index(destination[j])] = source[j];
            }
        }
    }

    for(int i=0; i<source.size(); i++){
        if(d[get_index(destination[i])] > d[get_index(source[i])] + weight[i]){
            cout<<"Negative weight cycle found"<<endl;
            return;
        }
    }
}


int main(){
    fstream file;
    file.open("bellmanFord.txt");
    string s;
    while(file >> s){
        source.push_back(s);
        file >> s;
        destination.push_back(s);

        int a;
        file >> a;
        weight.push_back(a);
    }

    for(int i=0; i<source.size(); i++){
        vertices.insert(source[i]);
        vertices.insert(destination[i]);
    }

    bellmanFord("s");

    printPath("z");

}