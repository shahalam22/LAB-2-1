#include <iostream>
using namespace std;

int main(){
    float mat[4][5] = {
        {1,-1,2,-1,-8},
        {2,-2,3,-3,-20},
        {1,1,1,0,-2},
        {1,-1,4,3,4}
    };

    for(int i=0; i<4; i++){
        for(int j=0; j< 5; j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    float arr[4];

    for(int i=1; i<4; i++){
        arr[i] = mat[i][0];
        cout << mat[i][0] << " ";
    }


    cout << endl;
    cout << endl;


    // // column 1 to zero
    // for(int k=0; k<4; k++){

    //     for(int i=k+1; i<4; i++){

    //         if(i==k+1 && mat[i][k+1] == 0){
    //             for(int m=0; m<5; m++){
    //                 int temp = mat[k+1+1][m];
    //                 mat[k+1+1][m] = mat[k+1][m];
    //                 mat[k+1][m] = temp;
    //             }
    //         }

    //         for(int j=0; j<5; j++){
    //             mat[i][j] = (mat[k+1][j]*arr[k+1]) - mat[i][j];  
    //         }
    //     }

    //     cout << endl;
    //     cout << endl;

    //     for(int i=0; i<4; i++){
    //         for(int j=0; j< 5; j++){
    //             cout << mat[i][j] << "\t";
    //         }
    //         cout << endl;
    //     }
    // }

    for(int i=1; i<4; i++){
        for(int j=i; j<4; j++){
            if(i==j && mat[i][j]==0){
                for(int k=0; k<5; k++){
                    int temp = mat[i+1][k];
                    mat[i+1][k] = mat[i][k];
                    mat[i][k] = temp;
                }
            }

            for(int k=i-1; k<5; k++){
                mat[j][k] = (mat[i-1][i-1]/mat[j][i-1]) - mat[j][k];
            }

        }

        for(int i=0; i<4; i++){
            for(int j=0; j< 5; j++){
                // cout <<  << "\t";
                printf("%3.2f\t", mat[i][j]);
            }
            cout << endl;
        }

        cout << endl;
        cout << endl;

    }

}