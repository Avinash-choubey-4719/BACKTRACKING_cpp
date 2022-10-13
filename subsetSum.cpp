#include<bits/stdc++.h>
using namespace std;

int sol[] = {0, 0, 0, 0, 0};

int isSafe(int arr[], int index, int sum){
    return (sol[index] != 1 && arr[index] <= sum);
}

int solveSubset(int arr[], int start, int end, int sum){
    if(sum == 0){
        return true;
    }

    for(int i = start;i<=end;i++){
        if(isSafe(arr, i, sum)){
            sol[i] = 1;

            if(solveSubset(arr, i + 1, end, sum - arr[i])){
                return true;
            }

            sol[i] = 0;
        }
    }
    return false;
}

void printSolution(){
    for(int i = 0;i<5;i++){
        cout<<sol[i]<<" ";
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int sol[] = {0, 0, 0, 0, 0};

    solveSubset(arr, 0, 4, 5);
    printSolution();
    return 0;
}