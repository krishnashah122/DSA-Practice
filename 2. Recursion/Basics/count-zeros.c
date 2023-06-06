// Count no. of zeros digits in a number.
// Parameterized Recursion

#include <stdio.h>

int helper(int n, int count){
    if(n == 0){
        return count;
    }
    if(n%10 == 0){
        return helper(n/10, count = count + 1);
    }
    return helper(n/10, count);
}

int counter(int n){
    return helper(n, 0);
}

int main(){
    printf("The number of zeros in the digit is: %d", counter(302040));
    return 0;
}