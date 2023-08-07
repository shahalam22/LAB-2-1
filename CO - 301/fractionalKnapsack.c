#include <stdio.h>

int n;

struct object{
    int weight;
    int price;
    double pricePerWeight;
} obj[20];

//sorting according to pricePerWeight
void sorting(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(obj[i].pricePerWeight>obj[j].pricePerWeight){
                struct object temp = obj[i];
                obj[i] = obj[j];
                obj[j] = temp;
            }
        }
    }
}

// iterative fractional knapsack algorithm
double maxBenefit(int maxWeight){
    int i = 0;
    double maxBenefitt = 0;
    while(maxWeight>=0){
        if(obj[i].weight<=maxWeight){
            maxBenefitt += obj[i].pricePerWeight*obj[i].weight;
            maxWeight -= obj[i].weight;
            i++;
        }else if(obj[i].weight>maxWeight && maxWeight!=0){
            maxBenefitt += maxWeight*obj[i].pricePerWeight;
            break;
        }
    }
    return maxBenefitt;
}


int main(){

    // creating file & handling this
    FILE *fp = fopen("fractionalKnapsack.txt", "r");
    fscanf(fp, "%d", &n);

    for(int i=0; i<n; i++){
        fscanf(fp, "%d %d", &obj[i].weight, &obj[i].price);
        obj[i].pricePerWeight = (double)obj[i].price/obj[i].weight;
    }

    sorting();

    // for(int i=0; i<n; i++){
    //     printf("%d %d %0.2f\n", obj[i].weight, obj[i].price, obj[i].pricePerWeight);
    // }

    int maxWeight;
    printf("\nEnter max weight : ");
    scanf("%d", &maxWeight);

    printf("Max Benefit is : %0.2f", maxBenefit(maxWeight));

    return 0;
}