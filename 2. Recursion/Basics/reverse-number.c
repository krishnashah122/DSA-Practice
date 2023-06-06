// Reverse number
// Parameterized Recursion

#include <stdio.h>

int reverse(int n){
    if(n == 0){
        return n;
    }
    static int rev = 0;
    rev = rev * 10 + n%10;
    reverse(n/10);
    return rev;
}

int main()
{
    printf("The reverse is: %d", reverse(12345));
    return 0;
}