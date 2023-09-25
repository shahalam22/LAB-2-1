#include <iostream>
using namespace std;


// this is the code for checking whether multiplication of L & U matrix is equals to main matrix or not
// here, be careful about making of L matrix

int main(){
    float mat[3][4] = {
        {4,1,1,8},
        {2,5,2,3},
        {1,2,4,11}
    };

    float U[3][4];
    float ans[3][3];

    float L[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int row = 3;
    int col = 4;


    //copying values of mat to U
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            U[i][j] = mat[i][j];
        }
    }


    //lower triangular
    for(int i=0; i<row; i++){
        for(int j=i+1; j<row; j++){
            float temp = U[j][i]/U[i][i];
            L[j][i] = temp;     // making of L matrix
            for(int k=0; k<row; k++){
                U[j][k] = U[j][k] - temp*U[i][k];
            }
        }
    }


    //multiplication of L & U
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            float sum = 0;
            for(int k=0; k<row; k++){
                sum += L[i][k]*U[k][j];
            }
            ans[i][j] = sum;
        }
    }


    // print 
    cout << "Original Matrix:" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", mat[i][j]);
        }
        cout << endl;
    }
    cout << "\n\n";
    cout << "U matrix:" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", U[i][j]);
        }
        cout << endl;
    }
    cout << "\n\n";
    cout << "L matrix:" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", L[i][j]);
        }
        cout << endl;
    }
    cout << "\n\n";
    cout << "ans matrix:" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("%10.2f", ans[i][j]);
        }
        cout << endl;
    }


    // //determinant
    // float det = 1;
    // for(int i=0; i<row; i++){
    //     det = det * mat[i][i];
    // }

    // // cout << det << endl;


    // // X matrix -
    // for(int i=0; i<row; i++){
    //     float temp = mat[i][i];
    //     for(int j=0; j<col; j++){
    //         mat[i][j] = mat[i][j]/temp;
    //     }
    //     for(int j=0; j<row; j++){
    //         L[i][j] = L[i][j]/temp;
    //     }
    // }


    // //upper triangular
    // for(int i = row-1; i>=0; i--){
    //     for(int j = i-1; j>=0; j--){
    //         float temp = mat[j][i]/mat[i][i];
    //         for(int k=col-1; k>=0; k--){
    //             mat[j][k] = mat[j][k] - temp*mat[i][k];
    //         }
    //         for(int k=0; k<row; k++){
    //             L[j][k] = L[j][k] - temp*L[i][k];
    //         }
    //     }
    // }


    // //print
    // cout << "L matrix from main matrix with value of X's: " << endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         printf("%7.2f", mat[i][j]);
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // // Values of X's
    // cout << "X matrix is : ";
    // for(int i=0; i<row; i++){
    //     cout << mat[i][col-1] << " ";
    // }
    // cout << endl;
    // cout << endl;

    // // Inverse of main matrix
    // cout << "Inverse of main matrix is : " << endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<row; j++){
    //         printf("%7.2f", L[i][j]);
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    return 0;
}