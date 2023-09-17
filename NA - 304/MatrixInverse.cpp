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


    //determinant
    float det = 1;
    for(int i=0; i<row; i++){
        det = det * mat[i][i];
    }

    // cout << det << endl;


    // X matrix -
    for(int i=0; i<row; i++){
        float temp = mat[i][i];
        for(int j=0; j<col; j++){
            mat[i][j] = mat[i][j]/temp;
        }
        for(int j=0; j<row; j++){
            identity[i][j] = identity[i][j]/temp;
        }
    }


    //upper triangular
    for(int i = row-1; i>=0; i--){
        for(int j = i-1; j>=0; j--){
            float temp = mat[j][i]/mat[i][i];
            for(int k=col-1; k>=0; k--){
                mat[j][k] = mat[j][k] - temp*mat[i][k];
            }
            for(int k=0; k<row; k++){
                identity[j][k] = identity[j][k] - temp*identity[i][k];
            }
        }
    }


    //print
    cout << "Identity matrix from main matrix with value of X's: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%7.2f", mat[i][j]);
        }
        cout << endl;
    }
    cout << endl;

    // Values of X's
    cout << "X matrix is : ";
    for(int i=0; i<row; i++){
        cout << mat[i][col-1] << " ";
    }
    cout << endl;
    cout << endl;

    // Inverse of main matrix
    cout << "Inverse of main matrix is : " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%7.2f", identity[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}