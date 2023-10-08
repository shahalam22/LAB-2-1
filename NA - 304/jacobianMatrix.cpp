#include <bits/stdc++.h>
#include <cstdlib>
#define EPS 10e-6;
using namespace std;

bool diagonallyAugmented(double mat[3][3]){
    int flag = 0;
    for(int i=0; i<3; i++){
        double temp = 0;
        for(int j=0; j<3; j++){
            if(i!=j){
                temp += abs(mat[i][j]);
            }
        }
        if(abs(mat[i][i])<temp){
            flag = 1;
            break;
        }
    }

    if(flag==1) return false;
    else return true;
}

bool converge(double xO[3], double xN[3]){
    if((abs(xN[0]-xO[0])<10e-6) && (abs(xN[1]-xO[1])<10e-6) && (abs(xN[2]-xO[2])<10e-6)){
        return true;
    }
    else return false;
}

int main(){
    double mat[3][4] = {
        {4,1,1,8},
        {2,5,2,3},
        {1,2,4,11}
    };

    double matx[3][3], matA[3], matAi[3], b[3], xO[3], xN[3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matx[i][j] = mat[i][j];
        }
    }

    for(int i=0; i<3; i++){
        matA[i] = matx[i][i];
        matAi[i] = (double)1/matx[i][i];
        b[i] = mat[i][3];
        xO[i] = -1;
        xN[i] = 0;
    }

    if(!diagonallyAugmented(matx)){
        cout << "Matrix is not diagonally augmented" << endl;
        exit(0);
    }


// // jacobi method

    int i = 1;
//     cout << "IT No.\tx1\tx2\tx3" << endl;
//     while(!converge(xO, xN)){
//         //printing iterations
//         cout << i << "\t";
//         for(int i=0; i<3; i++){
//             cout << xN[i] << "\t";
//         }
//         cout << endl;

//         for(int i=0; i<3; i++){
//             xO[i] = xN[i];
//         }
//         for(int i=0; i<3; i++){
//             double temp = 0;
//             for(int j=0; j<3; j++){
//                 if(i!=j){
//                     temp += matx[i][j]*xO[j];
//                 }
//             }
//             xN[i] = (b[i]-temp)/matx[i][i];
//         }
//         i++;
//     }

//     cout << "\t\t\t" << endl;


// jaccobi method matrix formation

    for(int i=0; i<3; i++){
        xO[i] = -1;
        xN[i] = 0;
    }

    i = 1;
    cout << "IT No.\tx1\tx2\tx3" << endl;

    while(!converge(xO, xN)){
        //printing iterations
        cout << i << "\t";
        for(int i=0; i<3; i++){
            cout << xN[i] << "\t";
        }
        cout << endl;

        for(int i=0; i<3; i++){
            xO[i] = xN[i];
        }

        for(int i=0; i<3; i++){
            double temp = 0;
            for(int j=0; j<3; j++){
                temp += matx[i][j]*xO[j];
            }
            xN[i] = xO[i] + matAi[i]*(b[i]-temp);
        }

        i++;
    }

    cout << "\t\t\t" << endl;


// // gauss-seidel method

//     for(int i=0; i<3; i++){
//         xO[i] = -1;
//         xN[i] = 0;
//     }

//     i = 1;
//     cout << "IT No.\tx1\tx2\tx3" << endl;

//     while(!converge(xO, xN)){
//         //printing iterations
//         cout << i << "\t";
//         for(int i=0; i<3; i++){
//             cout << xN[i] << "\t";
//         }
//         cout << endl;

//         for(int i=0; i<3; i++){
//             xO[i] = xN[i];
//         }
        
//         for(int i=0; i<3; i++){
//             double temp = 0;
//             for(int j=0; j<3; j++){
//                 if(i!=j){
//                     temp += matx[i][j]*xN[j];
//                 }
//             }
//             xN[i] = (b[i]-temp)/matx[i][i];
//         }

//         i++;
//     }

    cout << "\t\t\t" << endl;

    for(int i=0; i<3; i++){
        cout << xN[i] << endl;
    }
}