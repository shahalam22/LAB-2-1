#include <bits/stdc++.h>
using namespace std;

vector<string> source;
vector<string> destination;
vector<int> weight;
set<string> vertices;

int d[100];
string pi[100];

int graph[100][100];

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

//for topological sort
void make_graph(){
    for(int i=0; i<vertices.size(); i++){
        for(int j=0; j<vertices.size(); j++){
            graph[i][j] = INT_MAX;
        }
    }

    for(int i=0; i<source.size(); i++){
        graph[get_index(source[i])][get_index(destination[i])] = weight[i];
    }
}

//for topological sort
bool is_zeroIndegreeNode(int i){
    for(int j=0; j<vertices.size(); j++){
        if(graph[j][i] != INT_MAX){
            return false;
        }
    }
    return true;
}

//for topological sort
vector<string> topologicalSort(){
    make_graph();
    
    vector<string> sorted_vertices;
    vector<string> demo;
    
    for(auto v: vertices){
        demo.push_back(v);
    }

    while(demo.size() != 0){
        for(int i=0; i<demo.size(); i++){
            if(is_zeroIndegreeNode(i)){
                sorted_vertices.push_back(demo[i]);
                demo.erase(demo.begin()+i);
                for(int j=0; j<vertices.size(); j++){
                    graph[i][j] = INT_MAX;
                }
                break;
            }
        }
    }
    return sorted_vertices;
}



//for single source shortest path
void relax(string u, string v, int w){
    if(d[get_index(v)] > d[get_index(u)]+w){
        d[get_index(v)] = d[get_index(u)] + w;
        pi[get_index(v)] = u;
    }
}

//for single source shortest path
void DAG_Shortest_Path(string s){
    vector<string> sorted_vertices = topologicalSort();
    
    for(int i=0; i<vertices.size(); i++){
        d[i] = INT_MAX;
        pi[i] = "NIL";
    }
    d[get_index(s)] = 0;

    for(int i=0; i<sorted_vertices.size(); i++){
        for(int j=0; j<source.size(); j++){
            if((d[get_index(source[j])] != INT_MAX) && (d[get_index(destination[j])] > d[get_index(source[j])] + weight[j])){
                relax(source[j], destination[j], weight[j]);
            }
        }
    }
    
    
}

//for single source shortest path
void printPath(string s){
    if(s == "NIL"){
        return;
    }
    printPath(pi[get_index(s)]);
    cout << s << " ";
}


int main(){
    fstream file;
    file.open("bellmanFordDAG.txt");
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


    DAG_Shortest_Path("s");
    
    printPath("z");

}