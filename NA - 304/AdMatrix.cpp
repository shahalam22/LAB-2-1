#include <iostream>
using namespace std;

int main(){
    float A[3][4] = {
        {4,1,1,8},
        {2,5,2,3},
        {1,2,4,11}
    };

    float D[3][3];
    float Ad[3][3];
    float Di[3][3]; //diagonal inverse
    float ans[3][3];

    float identity[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int row = 3;
    int col = 4;

    // D matrix making
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            if(i==j){
                D[i][j] = A[i][j];
            }else{
                D[i][j] = 0;
            }
        }
    }

    // Ad matrix making
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            Ad[i][j] = A[i][j] - D[i][j];
        }
    }

    //making of Di
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            if(i!=j) Di[i][j] = D[i][j];
            else Di[i][j] = 1.0/D[i][j];
        }
    }

    //multiplication of D & Di
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            float sum = 0;
            for(int k=0; k<3; k++){
                sum += D[i][k]*Di[k][j];
            }
            ans[i][j] = sum;
        }
    }


    //print Ad Matrix

    // Ad matrix making
    cout << "Ad [A-D] Matrix is : " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", Ad[i][j]);
        }
        cout << endl;
    }
    cout << "\n\n";

    // D matrix making
    cout << "D Matrix is : " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", D[i][j]);
        }
        cout << endl;
    }
    cout << "\n\n";

    // Di matrix making
    cout << "Di Matrix is : " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", Di[i][j]);
        }
        cout << endl;
    }
    cout << "\n\n";

    // ans matrix making
    cout << "D x Di Matrix is : " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", ans[i][j]);
        }
        cout << endl;
    }
    cout << "\n\n";


    // //lower triangular
    // for(int i=0; i<row; i++){
    //     for(int j=i+1; j<row; j++){
    //         float temp = A[j][i]/A[i][i];
    //         for(int k=0; k<col; k++){
    //             A[j][k] = A[j][k] - temp*A[i][k];
    //         }
    //         for(int k=0; k<row; k++){
    //             identity[j][k] = identity[j][k] - temp*identity[i][k];
    //         }
    //     }
    // }


    // //determinant
    // float det = 1;
    // for(int i=0; i<row; i++){
    //     det = det * A[i][i];
    // }

    // // cout << det << endl;


    // // X matrix -
    // for(int i=0; i<row; i++){
    //     float temp = A[i][i];
    //     for(int j=0; j<col; j++){
    //         A[i][j] = A[i][j]/temp;
    //     }
    //     for(int j=0; j<row; j++){
    //         identity[i][j] = identity[i][j]/temp;
    //     }
    // }


    // //upper triangular
    // for(int i = row-1; i>=0; i--){
    //     for(int j = i-1; j>=0; j--){
    //         float temp = A[j][i]/A[i][i];
    //         for(int k=col-1; k>=0; k--){
    //             A[j][k] = A[j][k] - temp*A[i][k];
    //         }
    //         for(int k=0; k<row; k++){
    //             identity[j][k] = identity[j][k] - temp*identity[i][k];
    //         }
    //     }
    // }


    // //print
    // cout << "Identity matrix from main matrix with value of X's: " << endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         printf("%7.2f", A[i][j]);
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // // Values of X's
    // cout << "X matrix is : ";
    // for(int i=0; i<row; i++){
    //     cout << A[i][col-1] << " ";
    // }
    // cout << endl;
    // cout << endl;

    // // Inverse of main matrix
    // cout << "Inverse of main matrix is : " << endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<row; j++){
    //         printf("%7.2f", identity[i][j]);
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    return 0;
}