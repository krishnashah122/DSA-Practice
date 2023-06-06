// Skip a Character

#include <iostream>
using namespace std;

string skipChar(string p, string up, char c){
    if(up.empty()){
        return "";
    }
    char ch = up.at(0);
    if(ch == c){
        return skipChar(p, up.substr(1, up.size()), c);
    }else{
        return ch + skipChar(p, up.substr(1, up.size()), c);
    }
    
}

int main(){
    string str = "baccad";
    cout << skipChar("", str, 'a');
    return 0;
}