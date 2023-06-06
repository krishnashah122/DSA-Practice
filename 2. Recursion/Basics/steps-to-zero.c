// LEETCODE EASY LEVEL QUESTION
// Given an integer num, return the number of steps to reduce it to zero.
// In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
// Parameterized Recursion

#include <stdio.h>

int helper(int n, int count){
    if(n == 0){
        return count;
    }
    if(n%2 == 0){
        return helper(n/2, count = count + 1);
    }
    return helper(n-1, count = count + 1);
}

int numberOfSteps(int num){
    return helper(num, 0);
}

int main(){
    printf("The number of steps required to make the number zero is: %d", numberOfSteps(1234));
    return 0;
}