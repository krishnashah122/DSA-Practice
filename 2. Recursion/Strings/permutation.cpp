// Permutation or Subsets of any String

#include <iostream>
#include <vector>
using namespace std;

vector<string> subsets(string p, string up){
    if(up.empty()){
        vector<string> ans;
        ans.push_back(p);
        return ans;
    }
    char ch = up.at(0);
    vector<string> left = subsets(p + ch, up.substr(1, up.size()));
    vector<string> right = subsets(p, up.substr(1, up.size()));
    for(int i = 0; i < right.size(); i++){
        left.push_back(right[i]);
    }
    return left;
}

int main(){
    vector<string> str = subsets("", "abc");
    for(int i = 0; i < str.size(); i++){
        cout << str[i] << " ";
    }
    return 0;
}