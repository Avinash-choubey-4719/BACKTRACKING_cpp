#include<bits/stdc++.h>
using namespace std;
#define N 4

int isSafe(int x, int y, int maze[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

int solveMaze(int sol[N][N], int maze[N][N], int x, int y){
    if(x == N-1 && y == N-1){
        return 1;
    }

    if(isSafe(x, y, maze)){
        if(sol[x][y] == 1){
            return false;
        }

        sol[x][y] = 1;

        if(solveMaze(sol, maze, x + 1, y)){
            return true;
        }

        if(solveMaze(sol, maze, x, y + 1)){
            return true;
        }

        sol[x][y] = 0;
        return false;
    }
    return false;
}

void printsolution(int sol[N][N]){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int sol[N][N];
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            sol[i][j] = 0;
        }
    }

    if(solveMaze(sol, maze, 0, 0)){
        printsolution(sol);
    }
    else{
        cout<<"no solution exists";
    }

    return true;
}