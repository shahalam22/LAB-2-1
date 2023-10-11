#include <bits/stdc++.h>
using namespace std;

int graphOri[100][100];

vector<int> bfs(int source, int destination, int n){
    
    int parent[n];
    bool visited[n];
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent)); 
    queue<int> q;
    vector<int> path;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++){
            if(!visited[v] && graphOri[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    if(visited[destination]){
        int v = destination;
        while(v != -1){
            path.push_back(v);
            v = parent[v];
        }
        reverse(path.begin(), path.end());
        return path;
    }
    else{
        return {};
    }
    
}

bool hasValue(vector<int> a, int value){
    for(int i=0; i<a.size(); i++){
        if(a[i] == value){
            return true;
        }
    }
    return false;
}

int main(){

//example 1
    // int graph[6][6] = {
    //     {0,2,3,0,0,0},
    //     {0,0,0,3,1,0},
    //     {0,0,0,1,1,0},
    //     {0,0,0,0,0,2},
    //     {0,0,0,0,0,3},
    //     {0,0,0,0,0,0}
    // };

//example 2
    int graph[4][4] = {
        {0,6,2,0},
        {0,0,4,4},
        {0,0,0,8},
        {0,0,0,0}
    };

    int max_flow = 0, source, destination, n;
    
    // //taking input
    // cout << "Enter number of vertices: ";
    // cin >> n;
    // n = 6;
    n = 4;

    //adding supply and demand
    // int supply[n], demand[n];

    // cout << "Enter supply:";
    // for(int i=0; i<n; i++){
    //     cin >> supply[i];
    // }
    // int supply[6] = {3,3,0,1,0,0};
    int supply[4] = {4,5,0,0};
    
    // cout << "Enter demand:";
    // for(int i=0; i<n; i++){
    //     cin >> demand[i];
    // }
    // int demand[6] = {0,0,1,0,1,5};
    int demand[4] = {0,0,2,7};

    //calculating total supply. Here we will count this as total supply = total demand 
    int totalSupply = 0;
    for(int i=0; i<n; i++){
        totalSupply += supply[i];
    }

    // updating source, destination, n
    source = n;
    destination = n+1;
    n = n+2;

    //renovationg graph to graphOri
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            graphOri[i][j] = 0;
        }
    }

    for(int i=0; i<n-2; i++){
        for(int j=0; j<n-2; j++){
            graphOri[i][j] = graph[i][j];
        }
    }

    for(int i=0; i<n-2; i++){
        graphOri[source][i] = supply[i];
        graphOri[i][destination] = demand[i];
    }
    

//printing graphOri
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << graphOri[i][j] << " ";
        }
        cout << endl;
    }

    while(bfs(source, destination, n).size() > 0){
        int min_flow = INT_MAX;
        vector<int> path = bfs(source, destination, n);

        for(int i=0; i<path.size()-1; i++){
            min_flow = min(min_flow, graphOri[path[i]][path[i+1]]);
        }

        for(int i=0; i<path.size()-1; i++){
            graphOri[path[i]][path[i+1]] -= min_flow;
            graphOri[path[i+1]][path[i]] += min_flow;
        }

        max_flow += min_flow;
        path.clear();
    }

    cout << "Max flow: " << max_flow << endl;
    if(max_flow == totalSupply){
        cout << "Feasible solution" << endl;
    }
    else{
        cout << "Infeasible solution" << endl;
    }

}