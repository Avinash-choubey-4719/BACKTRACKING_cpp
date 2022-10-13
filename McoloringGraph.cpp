#include<bits/stdc++.h>
using namespace std;
#define V 4

bool isSafe(int graph[V][V], int m, int color[V], int vertex){
    for(int i = 0;i<V;i++){
        if(graph[vertex][i] && color[i] == m){
            return false;
        }
    }
    return true;
}

bool MColoringGraph(int graph[V][V], int m, int index, int color[V]){
    if(index == V){
        return true;
    }

    for(int i = 1;i<=m;i++){
        if(isSafe(graph, i, color, index)){
            color[index] = i;

            if(MColoringGraph(graph, m, index + 1, color)){
                return true;
            }

            color[index] = 0;
        }
    }

    return false;
}

void printsolution(int color[V]){
    for(int i = 0;i<V;i++){
        cout<<color[i]<<" ";
    }
    return;
}

int main(){
    int graph[V][V] = { { 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 }, };

    int color[V] = {0, 0, 0, 0};

    int m = 3;

    if(MColoringGraph(graph, m, 0, color)){
        printsolution(color);
    }                     
    else{
        cout<<"solution not exist";
    }
    return 0;
}