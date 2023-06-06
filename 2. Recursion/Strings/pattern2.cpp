// Pattern 2 using Recursion
    // *
    // * *
    // * * *
    // * * * *

// Parameterized Recursion

#include <iostream>
using namespace std;

void printPattern(int row, int col){
    if(row == 0){
        return;
    }
    if(col < row){
        printPattern(row, col + 1);
        cout << "* ";
    }else{
        printPattern(row - 1, 0);
        cout << endl;
    }
}

int main(){
    printPattern(4, 0);
    return 0;
}