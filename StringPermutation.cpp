#include<bits/stdc++.h>
using namespace std;

void permutation(string str, int l, int r){
    if(l == r){
        cout<<str<<" ";
    }

    else{
        for(int i = l;i<=r;i++){
            swap(str[i], str[l]);
            permutation(str, l + 1, r);
            swap(str[i], str[l]);
        }
    }
}

int main(){
    string str = "abc";
    permutation(str, 0, str.length() - 1);
    return 0;
}