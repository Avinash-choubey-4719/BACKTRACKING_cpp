#include<bits/stdc++.h>
using namespace std;

int makeSolution(int x, int y, int move, int sol[8][8], int xMove[8], int yMove[8]);

int isSafe(int x, int y, int sol[8][8]){
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && sol[x][y] == -1);
}


void printSolution(int sol[8][8]){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cout<<setw(2)<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}


void KnightTour(){
    int sol[8][8];
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            sol[i][j] = -1;
        }
    }

    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    sol[0][0] = 0;

    if(makeSolution(0, 0, 1, sol, xMove, yMove)){
        printSolution(sol);
    }
    else{
        cout<<"No Solution Exists for this";
        return;
    }
}


int makeSolution(int x, int y, int move, int sol[8][8], int xMove[8], int yMove[8]){
    if(move == 64){
        return 1;
    }
    else{
        for(int i = 0;i<8;i++){
            int next_x = x + xMove[i];
            int next_y = y + yMove[i];

            if(isSafe(next_x, next_y, sol)){
                sol[next_x][next_y] = move;
                if(makeSolution(next_x, next_y, move + 1, sol, xMove, yMove)){
                    return 1;
                }
                else{
                    sol[next_x][next_y] = -1;
                }
            }
        }
    }
    return 0;
}

int main(){
    KnightTour();
    return 0;
}