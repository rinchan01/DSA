#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void permute(string s, int ind){
    if(ind == s.length()){
            cout << s << endl;
    } else {
        for(int i = ind; i < s.length(); i++){
            swap(s[i], s[ind]);
            permute(s, ind + 1);
        }
    }
}

int main(){
    string s;
    cin >> s;
    permute(s,0);
}