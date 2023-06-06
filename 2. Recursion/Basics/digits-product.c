// Product of the digits of a number.
// Parameterized & Functional Recursion

#include <stdio.h>

int digitProduct(int n){
    if(n%10 == 0){
        return 1;
    }
    return n%10 * digitProduct(n/10);
}

int main(){
    printf("The product of digits is: %d", digitProduct(1234));
    return 0;
}