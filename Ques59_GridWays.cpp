#include<iostream>
#include<vector>

using namespace std;
    // Grid Ways

int gridWays(int row , int col,int n , int m){
    if(row == n-1 && col == m-1){
        return 1;
    }

    if(row>= n || col>=m){
        return 0;
    }

    return gridWays(row + 1 , col , n , m ) + gridWays(row , col + 1 , n , m );
}

int main(){
    int n , m;
    n= 3;
    m= 3;
    cout<<gridWays(0,0,n,m);
}