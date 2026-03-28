#include<iostream>
using namespace std;
int main(){
    int row,column;
    cout << "Enter row:column ";
    cin>> row;
    cin>> column;
    int* *matrix = new int*[row];
    for(int i=0;i<row;i++){
        matrix[i] = new int[column];
    }
    // data store;
    int x=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            *(*(matrix + i) + j) = x++;
            cout<< *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}
