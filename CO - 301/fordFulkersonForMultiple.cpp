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
    int graph[12][12] = {
        {0,0,0,0,0,10,0,0,0,0,0,0},
        {0,0,0,0,0,12,5,0,0,0,0,0},
        {0,0,0,0,0,0,8,14,0,0,0,0},
        {0,0,0,0,0,0,0,7,11,0,0,0},
        {0,0,0,0,0,0,0,0,2,0,0,0},
        {0,0,0,0,0,0,0,0,0,3,0,0},
        {0,0,0,0,0,0,0,0,0,15,6,0},
        {0,0,0,0,0,0,0,0,0,0,20,13},
        {0,0,0,0,0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0}
    };

    int max_flow = 0, source, destination, n;
    int numOfSource, numOfDestination;
    vector<int> sources;
    vector<int> destinations;
    
    // //taking input
    // cout << "Enter number of vertices: ";
    // cin >> n;       // 12
    n = 12;

    // cout << "Enter number of source: ";
    // cin >> numOfSource;     // 5
    numOfSource = 5;

    // cout << "Enter source: ";    // 0 1 2 3 4
    // for(int i=0; i<numOfSource; i++){
    //     int temp;
    //     cin >> temp;
    //     sources.push_back(temp);
    // }
    sources = {0,1,2,3,4};

    // cout << "Enter number of destination: ";
    // cin >> numOfDestination;    // 3
    numOfDestination = 3;

    // cout << "Enter destination: ";      // 9 10 11
    // for(int i=0; i<numOfDestination; i++){
    //     int temp;
    //     cin >> temp;
    //     destinations.push_back(temp);
    // }
    destinations = {9,10,11};

    //copying graph to graphOri
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            graphOri[i+1][j+1] = graph[i][j];
        }
    }

    for(int i=0; i<n; i++){
        if(hasValue(sources, i)){
            graphOri[0][i+1] = INT_MAX;
        }
        else{
            graphOri[0][i+1] = 0;
        }
    }

    for(int i=0; i<n; i++){
        if(hasValue(destinations, i)){
            graphOri[i+1][n+1] = INT_MAX;
        }
        else{
            graphOri[i+1][n+1] = 0;
        }
    }

    // updating source, destination, and n
    source = 0;
    destination = n+1;
    n = n+2;


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

}