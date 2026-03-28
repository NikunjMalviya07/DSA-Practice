#include <iostream>
using namespace std;
    // but and sell , max profit stock
void maxProfitStock(int *price, int n){
    int bestBuyPrice[100000];
    int maxProfit = 0;
    bestBuyPrice[0] = INT_MAX;
    for(int i=1;i<n;i++){
        bestBuyPrice[i] = min(bestBuyPrice[i-1],price[i-1]);
        maxProfit = max(maxProfit , price[i]-bestBuyPrice[i]);
    }
    cout << "Maximum Profit possible is : " << maxProfit; 
}

int main(){
    int price[] = {7,6,5,4,3,2};
    int n = sizeof(price)/sizeof(int);
    maxProfitStock(price,n);
}