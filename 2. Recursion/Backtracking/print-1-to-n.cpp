// Print from 1 to N using Backtracking.

// Parameterized Recursion
// Time Complexity : O(n)

#include <iostream>
using namespace std;

void print(int i, int n){
    if(i < 1){
        return;
    }
    print(i - 1, n);
    cout << i << " ";
}

int main(){
    print(3, 3);
    return 0;
}