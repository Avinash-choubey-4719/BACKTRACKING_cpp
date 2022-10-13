#include<bits/stdc++.h>
using namespace std;

void permutation(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<" ";
    }
    else{
        for(int i = 0;i<str.length();i++){
            char ch = str[i];
            string left = str.substr(0, i);
            string right = str.substr(i + 1, str.length() - 1);
            string rest = left + right;
            permutation(rest, ans + ch);
        }
    }
}

int main(){
    string str = "abc";
    permutation(str, "");
    return 0;
}