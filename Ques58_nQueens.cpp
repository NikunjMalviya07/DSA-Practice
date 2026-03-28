#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(vector<vector<char>> board , int row , int col){
    int n = board.size();
    // horizonral
    for(int i = 0;i<n;i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }
    // verticle
    for(int i = 0;i<n;i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    // left diagonal
    for(int i = row ,  j =col ;i>=0 && j>=0 ;i-- && j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // right diagonal 
    for(int i = row ,  j = col ;i>=0 && j<n ;i-- && j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return  true;

}

void printBoard(vector<vector<char>> board){
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "__________________________";
    cout<<endl;
}

void nQueens(vector<vector<char>> board , int m){
    int n = board.size();
    if(m==n){
        printBoard(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board , m , i)){
        board[m][i] = 'Q';
        nQueens(board , m+1);
        board[m][i] = '.';
        }
    }
}

int main(){
    vector<vector<char>> board;
    int  n = 4;
        for(int i=0;i<n;i++){
            vector<char> row;
            for(int j=0;j<n;j++){
                row.push_back('.');
            }
            board.push_back(row);
        }

    nQueens( board, 0);
}