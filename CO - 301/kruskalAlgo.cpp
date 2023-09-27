#include <bits/stdc++.h>
using namespace std;

vector<char> startNodes;
vector<char> endNodes;
vector<int> weights;
set<char> nodes;
set<char> mst;


struct node{
    char p;
    int rank;
};

struct node nodesStruct[100];

node makeSet(char p){
    struct node newNode;
    newNode.p = p;
    newNode.rank = 0;
    return newNode;
}

int findIndex(int w){
    for(int i=0; i<weights.size(); i++){
        if(weights[i] == w){
            weights[i] = -1;
            return i;
        }
    }
    return -1;
}

char findSet(char p){
    if(p != nodesStruct[p-'a'].p){
        nodesStruct[p-'a'].p = findSet(nodesStruct[p-'a'].p);
    }
    return nodesStruct[p-'a'].p;
}

void link(char x, char y){
    if(nodesStruct[x-'a'].rank > nodesStruct[y-'a'].rank){
        nodesStruct[y-'a'].p = x;
    }
    else{
        nodesStruct[x-'a'].p = y;
        if(nodesStruct[x-'a'].rank == nodesStruct[y-'a'].rank){
            nodesStruct[y-'a'].rank = nodesStruct[y-'a'].rank + 1;
        }
    }
}

void unionSet(char x, char y){
    link(findSet(x), findSet(y));
}

int main(){

    int noOfNodes;

    fstream file;
    file.open("kruskalAlgo.txt", ios::in);
    file >> noOfNodes;
    while(file){
        char startNode, endNode;
        int weight;
        file >> startNode >> endNode >> weight;
        startNodes.push_back(startNode);
        endNodes.push_back(endNode);
        weights.push_back(weight);
        nodes.insert(startNode);
        nodes.insert(endNode);
    }
    startNodes.pop_back();
    endNodes.pop_back();
    weights.pop_back();

    file.close();

    // for(auto v : nodes){
    //     cout << v << " ";
    // }


    //// KUSKAL ALGORITHM ////

    vector<string> mstEdges;

    //make-set of vertices
    int i=0;
    for(auto v : nodes){
        nodesStruct[i] = makeSet(v);
        i++;
    }

    //sort edges by weight
    int sortedWeights[weights.size()];
    copy(weights.begin(), weights.end(), sortedWeights);
    sort(sortedWeights, sortedWeights+weights.size());

    //kuskal main loop
    for(int j=0; j<weights.size(); j++){
        int index = findIndex(sortedWeights[j]);
        char startNode = startNodes[index];
        char endNode = endNodes[index];
        if(findSet(startNode) != findSet(endNode)){
            unionSet(startNode, endNode);
            string edge = "";
            edge += startNode;
            edge += "-";
            edge += endNode;
            mstEdges.push_back(edge);
        }
    }

    //print mst
    cout << "MST is :\n";
    for(int j=0; j<mstEdges.size(); j++){
        cout << mstEdges[j] << "\n";
    }

    return 0;
}