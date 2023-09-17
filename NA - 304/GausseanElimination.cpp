#include <iostream>
using namespace std;

int main(){
    float mat[3][4] = {
        {4,1,1,8},
        {2,5,2,3},
        {1,2,4,11}
    };

    float identity[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int row = 3;
    int col = 4;


    //lower triangular
    for(int i=0; i<row; i++){
        for(int j=i+1; j<row; j++){
            float temp = mat[j][i]/mat[i][i];
            for(int k=0; k<col; k++){
                mat[j][k] = mat[j][k] - temp*mat[i][k];
            }
            for(int k=0; k<row; k++){
                identity[j][k] = identity[j][k] - temp*identity[i][k];
            }
        }
    }

    //print
    cout << "Gausean Elimination for lower triangle" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%7.2f", mat[i][j]);
        }
        cout << endl;
    }
    cout << endl;

}