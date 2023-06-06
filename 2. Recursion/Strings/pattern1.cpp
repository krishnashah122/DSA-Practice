// Pattern 1 using Recursion
    // * * * *
    // * * *
    // * *
    // *

// Parameterized Recursion

#include <iostream>
using namespace std;

void printPattern(int row, int col){
    if(row == 0){
        return;
    }
    if(col < row){
        cout << "* ";
        printPattern(row, col + 1);
    }else{
        cout << endl;
        printPattern(row - 1, 0);
    }
}

int main(){
    printPattern(4, 0);
    return 0;
}