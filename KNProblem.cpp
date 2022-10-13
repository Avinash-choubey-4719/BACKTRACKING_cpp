#include<bits/stdc++.h>
using namespace std;
#define N 8

int isSafe(int x, int y, int sol[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

int SolveKNT(int x, int y, int sol[N][N], int xMove[N], int yMove[N], int move){
    if(move == N*N){
        return 1;
    }

    for(int i = 0;i<N;i++){
        int xNext = x + xMove[i];
        int yNext = y + yMove[i];

        if(isSafe(xNext, yNext, sol)){
            sol[xNext][yNext] = move;

            if(SolveKNT(xNext, yNext, sol, xMove, yMove, move + 1)){
                return 1;
            }

            sol[xNext][yNext] = -1;
        }
    }
    return 0;
}

void printSolution(int sol[N][N]){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int sol[N][N];
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            sol[i][j] = -1;
        }
    }

    if(SolveKNT(0, 0, sol, xMove, yMove, 1)){
        printSolution(sol);
    }
    else{
        cout<<"no solution exists";
    }
    return 0;
}