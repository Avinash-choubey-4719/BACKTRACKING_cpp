#include<bits/stdc++.h>
using namespace std;
#define N 9
#define UNASSIGNED 0

bool checkGrid(int grid[N][N], int &i, int &j);
bool inRow(int grid[N][N], int row, int n);
bool inCol(int grid[N][N], int col, int n);
bool inBox(int grid[N][N], int n, int row, int col);
bool isSafe(int grid[N][N], int row, int col, int n);
void printGrid(int grid[N][N]);

bool solveSudoku(int grid[N][N]){

    int row, col;

    if(!checkGrid(grid, row, col)){
        return true;
    }


    for(int i = 1;i<=9;i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;

            if(solveSudoku(grid)){
                return true;
            }

            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool checkGrid(int grid[N][N], int &i, int &j){
    for(i = 0;i<N;i++){
        for(j = 0;j<N;j++){
            if(grid[i][j] == UNASSIGNED){
                return true;
            }
        }
    }
    return false;
}

bool inRow(int grid[N][N], int row, int n){
    for(int i = 0;i<N;i++){
        if(grid[row][i] == n){
            return true;
        }
    }
    return false;
}

bool inCol(int grid[N][N], int col, int n){
    for(int i = 0;i<N;i++){
        if(grid[i][col] == n){
            return true;
        }
    }
    return false;
}

bool inBox(int grid[N][N], int n, int row, int col){
    for(int i = row;i<row + 3;i++){
        for(int j = col;j<col + 3;j++){
            if(grid[row][col] == n){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int n){
    if(!inCol(grid, col, n) && !inRow(grid, row, n) && !inBox(grid, n,  row - row%3, col - col%3) && grid[row][col] == UNASSIGNED){
        return true;
    }
    return false;
}

void printGrid(int grid[N][N]){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(solveSudoku(grid)){
        printGrid(grid);
    }
    else{
        cout<<"No solution exists";
    }

    return 0;                   
}