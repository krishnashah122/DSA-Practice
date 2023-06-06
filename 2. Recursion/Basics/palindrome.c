// Check Palindrome
// Parameterized Recursion

#include <stdio.h>

int isPalindrome(int n){
    if(n == 0){
        return n;
    }
    static int rev;
    rev = rev * 10 + n%10;
    isPalindrome(n/10);
    return rev;
}

int main(){
    int num = 12321;
    int key = isPalindrome(12321);
    if(key == num){
        printf("The number is Palindrome.");
    }else{
        printf("The number is not Palindrome.");
    }
    return 0;
}