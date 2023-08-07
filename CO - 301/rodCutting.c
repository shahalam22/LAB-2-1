// Application of Top Down Algorithm for ROD-CUTTING

#include <stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int cutRod(int price[], int n){
    if(n==0){
        return 0;
    }
    int q = price[n-1];
    for(int i=1; i<n; i++){
        q = max(q, (price[i-1]+cutRod(price, n-i)));
    }

    return q;
}


// Application of Top Down Memorize Algorithm for ROD-CUTTING

int r[100];

int cutRodAux(int price[], int n){
    if(r[n]>=0) return r[n];

    int q;
    if(n==0){
        q = 0;
    }else{
        q = price[n-1];
        for(int i=1; i<n; i++){
            q = max(q, price[i-1]+cutRodAux(price, n-i));
        }
    }
    r[n] = q;
    return q;
}

int cutRodMemorize(int price[], int n){
    for(int i=0; i<=n; i++){
        r[i] = -1;
    }

    return cutRodAux(price, n);
}


// Application of Bottom Up Algorithm for ROD-CUTTING

int cutRodBU(int price[], int n){
    int k[100];

    k[0] = 0;
    for(int i=1; i<=n; i++){
        int q = -1;
        for(int j=1; j<=i; j++){
            q = max(q, price[j-1]+r[i-j]);
        }
        r[i] = q;
    }
    return r[n];
}

// Extended Application of Bottom Up Algorithm for ROD-CUTTING

int c[50], d[50];

void extendedCutRodBU(int price[], int n){
    c[0] = 0;
    for(int i=1; i<=n; i++){
        int q = -1;
        for(int j=1; j<=i; j++){
            if(q<price[j-1]+c[i-j]){
                q = price[j-1]+c[i-j];
                d[i] = j;
            }
        }
        c[i] = q;
    }
    return;
}

void printCutRod(int price[], int n){
    extendedCutRodBU(price, n);
    while(n>0){
        printf("%d  ", d[n]);
        n = n - d[n];
    }
    return;
}

// Application of Top Down Algorithm for ROD-CUTTING with having cutting cost

int cutRodWithCost(int price[], int n, int cut){
    if(n==0){
        return 0;
    }
    int q = price[n-1];
    for(int i=1; i<n; i++){
        q = max(q, (price[i-1]+cutRod(price, n-i)-cut));
    }

    return q;
}


// Main Function

int main(){
    int length[] = {1,2,3,4,5,6,7,8,9,10};
    int price[] = {1,5,8,9,10,17,17,20,24,30};

    int n;
    printf("Enter size of the rod: ");
    scanf("%d", &n);

    int maxPrice = cutRod(price, n);
    printf("Maximum selling price is %d.", maxPrice);
    
    // printf("Cutting points of rod are: ");
    // printCutRod(price, n);

    // //for multiple rods
    // int m;
    // printf("Enter number of rods: ");
    // scanf("%d", &m);

    // for(int i=0; i<m; i++){
    //     printf("\nEnter size of the rod: ");
    //     scanf("%d", &n);
    //     int maxPrice = cutRodBU(price, n);
    //     printf("Maximum selling price is %d.\n", maxPrice);
    //     printCutRod(price, n);    
    // }

    // //having cutting cost
    // int cut;
    // printf("Enter the cutting cost: ");
    // scanf("%d", &cut);

    // int maxPrice = cutRodWithCost(price, n, cut);
    // printf("Maximum selling price is %d.", maxPrice);

    return 0;
}