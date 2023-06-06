// Print from  N to 1 using Backtracking.

// Parameterized Recursion
// Time Complexity : O(n)

#include <iostream>
using namespace std;

void print(int n, int i){
    if(i > n){
        return;
    }
    print(n, i + 1);
    cout << i << " ";
}

int main(){
    print(3, 1);
    return 0;
}