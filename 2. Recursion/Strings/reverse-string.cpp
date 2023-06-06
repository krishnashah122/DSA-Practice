// Reverse String using Recursion
// Parameterized & Functional Recursion

#include <iostream>
using namespace std;

string reverse(string str, int i){
    if(i < 0){
        return "\0";
    }
    return str[i] + reverse(str, i - 1);
}

int main(){
    string str = "Krishna";
    cout << reverse(str, str.length() - 1);
    return 0;
}