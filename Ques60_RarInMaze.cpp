#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printPath(string &path){
    cout<<path<<endl;
}

void ratInMaze(vector<vector<int>> &maze , int row , int col , string &path , vector<vector<int>> &isVisited){
    int n = maze.size();

    // condition
    if(row >= n || col >=n || row < 0 || col < 0){
        return;
    }
    // base case
    if(row == n-1 && col == n-1){
        printPath(path);
        return;
    }

    
    // right call
    if(col + 1 < n && maze[row][col + 1] == 1 && !isVisited[row][col + 1]){
        isVisited[row][col] = true;
        path.push_back('R');
        ratInMaze(maze, row, col + 1, path, isVisited);
        path.pop_back();
    }

    // left call
    if(col - 1 >= 0 && maze[row][col - 1] == 1 && !isVisited[row][col - 1]){
        isVisited[row][col] = true;
        path.push_back('L');
        ratInMaze(maze, row, col - 1, path, isVisited);
        path.pop_back();
    }

    // up call
    if( row - 1 >=0 && maze[row-1][col] == 1 && !isVisited[row-1][col]){
        isVisited[row][col] = true;
        path.push_back('U');
        ratInMaze(maze, row - 1 , col, path, isVisited);
        path.pop_back();
    }

    // down call
    if( row + 1 < n && maze[row+1][col] == 1 && !isVisited[row+1][col]){
        isVisited[row][col] = true;
        path.push_back('D');
        ratInMaze(maze, row + 1 , col, path, isVisited);
        path.pop_back();
    }
    isVisited[row][col] = false;
}


int main(){
    vector<vector<int>> maze = { {1,0,0,0},
                                 {1,1,0,0},
                                 {1,1,0,0},
                                 {0,1,1,1} };
                                

    int n = maze.size();
    vector<vector<int>> isVisited(n,vector<int>(n ,0));
    string path = "";
    ratInMaze(maze , 0 , 0 , path , isVisited);
    return 0;
}