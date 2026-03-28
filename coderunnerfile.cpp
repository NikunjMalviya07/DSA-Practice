#include<iostream>
using namespace  std;
    // spiral 

void spiral(int arr[3][3] , int n , int m){
    int top = 0;
    int left = 0;
    int  right = m-1;
    int bottom = n-1;
    int direction = 0;
    while(left<= right && top<=bottom){
        
        if(direction == 0 ){
            for(int i=left;i <= right;i++){
                cout<<arr[top][i] <<" ";
            }
                            top++;

        }

        else if(direction == 1){
            for(int i=top;i<= bottom ;i++){
                cout <<arr[i][right] << " ";
            }
                            right--;

        }

        else if (direction == 2){
            for(int i=right ; i>= left; i++){
                cout << arr[bottom][i] <<" ";
            }
                            bottom--;
            
        }

        else {
            for(int i=bottom; i>= top ; i++){
                cout << arr[i][left] <<" ";
            }
                            left++;

        }
        direction = (direction+1)%4;
    }
}

int main(){
    const int n = 3;
    const int m = 3;
    int arr[n][m] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    spiral(arr , n , m);
}