// Top Down Algorithm for finding COMBINATION

#include <stdio.h>

int comb(int n, int r){
    if(r==1){
        return n;
    }else if(r==n || r==0){
        return 1;
    }

    return comb(n-1, r-1) + comb(n-1, r);
}

int main(){
    
    int n, r;
    
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);

    printf("Cobination of %d numbers from %d numbers is %d", r, n, comb(n, r));

    return 0;
}



// // Top Down Memorized Algorithm for finding COMBINATION

// #include <stdio.h>

// int c[50][50];

// int min(int a, int b);
// int comb(int n, int r);

// int main(){

//     int n, r;
    
//     printf("Enter n: ");
//     scanf("%d", &n);
//     printf("Enter r: ");
//     scanf("%d", &r);

//     for(int i=0; i<=n; i++){
//         for(int j=0; j<=min(i,r); j++){
//             c[i][j] = -1;
//         }
//     }

//     printf("Cobination of %d numbers from %d numbers is %d", r, n, comb(n, r));

//     return 0;
// }

// int min(int a, int b){
//     if(a>b){
//         return b;
//     }
//     return a;
// }

// int comb(int n, int r){
//     if(c[n][r] != -1){
//         return c[n][r];
//     }

//     if(r==1){
//         c[n][r] = n;
//     }else if(r==n || r==0){
//         c[n][r] = 1;
//     }else {
//         c[n][r] = comb(n-1, r-1) + comb(n-1, r);
//     }

//     return c[n][r];
// }



// // Bottom Up Algorithm

// #include <stdio.h>

// int c[50][50];

// int min(int a, int b){
//     if(a<b){
//         return a;
//     }
//     return b;
// }

// int comb(int n, int r){
//     for(int i=0; i<=n; i++){
//         for(int j=0; j<=min(i, r); j++){
//             if(j==1) c[i][j] = i;
//             else if(j==i || j==0){
//                 c[i][j] = 1;
//             }else{
//                 c[i][j] = c[i-1][j-1] + c[i-1][j];
//             }
//         }
//     }
//     return c[n][r];
// }

// int main(void){
//     int n, r;
    
//     printf("Enter n: ");
//     scanf("%d", &n);
//     printf("Enter r: ");
//     scanf("%d", &r);

//     printf("Cobination of %d numbers from %d numbers is %d", r, n, comb(n, r));

//     return 0;
// }