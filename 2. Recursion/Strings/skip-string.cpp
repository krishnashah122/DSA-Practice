// Skip a String

#include <iostream>
using namespace std;

string skipStr(string p, string up, string s){
    if(up.empty()){
        return "";
    }
    if(s == up.substr(0, up.find(" "))){
        return skipStr(p, up.substr(s.size(), up.size()), s);
    }else{
        return up.at(0) + skipStr(p, up.substr(1, up.size()), s);
    }
    
}

int main(){
    string str = "ball apple ball";
    cout << skipStr("", str, "apple");
    return 0;
}