#include <bits/stdc++.h>
using namespace std;

vector<string> source;
vector<string> destination;
vector<int> weight;
set<string> vertices;

int d[100];
string pi[100];

int mat[100][100];
int p[100][100];

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

string get_value(int i){
    int j=0;
    for(auto n: vertices){
        if(j == i){
            return n;
        }
        j++;
    }
    return "";
}

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}

void printPath(string s, string d){
    int i = get_index(s);
    int j = get_index(d);
    if(p[i][j] == -1){
        cout << "No Path\n";
        return;
    }
    else if(p[i][j] == i){
        cout << s << " -> " << d << endl;
        return;
    }
    else{
        printPath(s, get_value(p[i][j]));
        printPath(get_value(p[i][j]), d);
    }
}


int main(){
    fstream file;
    file.open("FloydWarshallSIR.txt");
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

    cout << "source: \n";
    for(auto v: source){
        cout << v << " ";
    }
    cout << "\n";

    cout << "\ndestination: \n";
    for(auto v: destination){
        cout << v << " ";
    }
    cout << "\n";
    
    cout << "\nweight: \n";
    for(auto v: weight){
        cout << v << " ";
    }
    cout << "\n";

    cout << "\nvertices: \n";
    for(auto v: vertices){
        cout << v << " ";
    }
    cout << "\n\n";


    //initializing mat matrix

    for(int i=0; i<vertices.size(); i++){
        for(int j=0; j<vertices.size(); j++){
            if(i == j){
                mat[i][j] = 0;
                continue;
            }
            mat[i][j] = INT_MAX;
        }
    }
    for(int i=0; i<source.size(); i++){
        mat[get_index(source[i])][get_index(destination[i])] = weight[i];
    }

    //inititalizing path matrix
    for(int i=0; i<vertices.size(); i++){
        for(int j=0; j<vertices.size(); j++){
            if(i==j || mat[i][j] == INT_MAX){
                p[i][j] = -1;
            }else if(i!=j && mat[i][j] != INT_MAX){
                p[i][j] = i;
            }
        }
    }


    // printf("\n\nD(0)): \n");
    // for(int i=0; i<vertices.size(); i++){
    //     for(int j=0; j<vertices.size(); j++){
    //         cout << mat[i][j] << "\t";
    //     }
    //     cout << endl;
    // }


// Floyd Warshall Algorithm

    for(int m=0; m<vertices.size(); m++){
        for(int i=0; i<vertices.size(); i++){
            for(int j=0; j<vertices.size(); j++){
                if(mat[i][m] != INT_MAX && mat[m][j] != INT_MAX){
                    if(mat[i][j] > mat[i][m] + mat[m][j]){
                        mat[i][j] = mat[i][m] + mat[m][j];
                        p[i][j] = p[m][j];
                    }
                }
            }
        }
    }
    
    printf("\n\nAnswer Matrix : \n");
    for(int i=0; i<vertices.size(); i++){
        for(int j=0; j<vertices.size(); j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    printf("\n\nPath Matrix : \n");
    for(int i=0; i<vertices.size(); i++){
        for(int j=0; j<vertices.size(); j++){
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }

    printPath("Dhaka", "Tangail");

}