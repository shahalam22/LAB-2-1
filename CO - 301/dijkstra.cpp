#include <bits/stdc++.h>
using namespace std;

vector<string> source;
vector<string> destination;
vector<int> weight;
set<string> nodes;

int d[100];
string pi[100];


int get_index(string node){
    int i=0;
    for(auto n: nodes){
        if(n == node){
            return i;
        }
        i++;
    }
    return -1;
}


void initialize_single_source(string s){
    for(int i=0; i<nodes.size(); i++){
        d[i] = INT_MAX;
        pi[i] = "NIL";
    }
    d[get_index(s)] = 0;
}


void relax(string u, string v, int w){
    if(d[get_index(v)]>d[get_index(u)]+w){
        d[get_index(v)] = d[get_index(u)]+w;
        pi[get_index(v)] = u;
    }
}


void dijkstra(string s){
    initialize_single_source(s);
    set<string> q;
    for(auto i: nodes){
        q.insert(i);
    }
    while(!q.empty()){
        string a;
        int min = INT_MAX;
        for(auto i:q){
            if(d[get_index(i)]<min){
                min = d[get_index(i)];
                a = i;
            }
        }
        q.erase(a);
        for(int i=0; i<source.size(); i++){
            if(source[i] == a){
                relax(source[i], destination[i], weight[i]);
            }
        }
    }
}


void printPath(string s){
    if(s == "NIL"){
        return;
    }
    printPath(pi[get_index(s)]);
    cout << s << " ";
}


int main(){
    fstream file;
    file.open("dijkstra.txt");
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
        nodes.insert(source[i]);
        nodes.insert(destination[i]);
    }

    dijkstra("Dhaka");

    cout << "All the cities: ";
    for(auto i:nodes){
        cout << i << " ";
    }
    cout << endl;

    cout << "Shortest path array from Dhaka(source): ";
    for(int i=0; i<nodes.size(); i++){
        cout << d[i] << " ";
    }
    cout << endl;

    cout << "Shortest path from Dhaka(source) to Sylhet(destination): ";
    printPath("Sylhet");
    cout << endl;
}