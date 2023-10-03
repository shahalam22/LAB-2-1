#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int graph[6][6], int src, int des){
    int parent[6];
    bool visited[6];
    queue<int> q;
    vector<int> path;

    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<6; v++){
            if(!visited[v] && graph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    if(visited[des]){
        int v = des;
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

int main(){
    int graph[6][6] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int max_flow = 0;
    int source = 0;
    int destination = 5;

    while(bfs(graph, source, destination).size() > 0){
        int min_flow = INT_MAX;
        vector<int> path = bfs(graph, source, destination);
        for(int i=0; i<path.size()-1; i++){
            min_flow = min(min_flow, graph[path[i]][path[i+1]]);
        }

        for(int i=0; i<path.size()-1; i++){
            graph[path[i]][path[i+1]] -= min_flow;
            graph[path[i+1]][path[i]] += min_flow;
        }

        max_flow += min_flow;
        path.clear();
    }

    cout << "Max flow: " << max_flow << endl;
}