#include <iostream>
using namespace std;


int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int point(int a, int b){
    if(a==max(a,b)){
        return 1;
    }
    return 0;
}


int main(){
    int weight[] = {2,1,3,2};
    int value[] = {12,10,20,15};
    int W = 5, item = 4;
    
    // cout << "Enter the max weight : ";
    // cin >> W;
    // cout << "Enter the number of item : ";
    // cin >> item;


    int answerMatrix[item+1][W+1];
    int answerPoint[item+1][W+1][2];

    // filling up the answer matrix answer point matrix
    for(int i=0; i<=item; i++){
        answerMatrix[i][0] = 0;
        answerPoint[i][0][0] = 0;
        answerPoint[i][0][1] = 0;
    }
    for(int w=0; w<=W; w++){
        answerMatrix[0][w] = 0;
        answerPoint[0][w][0] = 0;
        answerPoint[0][w][1] = 0;
    }
    for(int i=1; i<=item; i++){
        for(int w=1; w<=W; w++){
            if(weight[i-1]>w){
                answerMatrix[i][w] = answerMatrix[i-1][w];
                answerPoint[i][w][0] = i-1;
                answerPoint[i][w][1] = w;
            }else{
                answerMatrix[i][w] = max(value[i-1]+answerMatrix[i-1][w-weight[i-1]], answerMatrix[i-1][w]);
                if(point(value[i-1]+answerMatrix[i-1][w-weight[i-1]], answerMatrix[i-1][w]) == 1){
                    answerPoint[i][w][0] = i-1;
                    answerPoint[i][w][1] = w-weight[i-1];
                }else if(point(value[i-1]+answerMatrix[i-1][w-weight[i-1]], answerMatrix[i-1][w]) == 0){
                    answerPoint[i][w][0] = i-1;
                    answerPoint[i][w][1] = w;
                }
            }
        }
    }

    // //printing answer matrix
    // cout << endl << "Answer matrix : " << endl;
    // for(int i=0; i<=item; i++){
    //     for(int j=0; j<=W; j++){
    //         cout << answerMatrix[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    // //printing pointing matrix - which denotes that which cell is pointing to which cell
    // cout << endl << "Point matrix : " << endl;
    // for(int i=0; i<=item; i++){
    //     for(int j=0; j<=W; j++){
    //         cout << answerPoint[i][j][0] << "," << answerPoint[i][j][1] << "\t";
    //     }
    //     cout << endl;
    // }

    //printing picked items
    int i0 = item;
    int w0 = W;

    cout << endl << "We will take -" << endl;
    while(w0!=0 && i0!=0){
        cout << "Item - " << i0 << endl;
        // cout << i0 << w0 << endl;
        int tempI = i0, tempW = w0;
        i0 = answerPoint[tempI][tempW][0];
        w0 = answerPoint[tempI][tempW][1];
        if(w0==tempW){
            tempI = i0;
            tempW = w0;
            i0 = answerPoint[tempI][tempW][0];
            w0 = answerPoint[tempI][tempW][1];
        }
    }
    cout << endl;
}