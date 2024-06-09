// Divide Two Integers (Leetcode)
// Leetcode Link : https://leetcode.com/problems/divide-two-integers/description/

// Time Complexity : O(Logn^2)
// Space Complexity : O(1)

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        // Determine the sign of the quotient
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor >= 0) sign = false;

        // Use long long to avoid overflow when taking the absolute value of INT_MIN
        long long n = abs(dividend);
        long long d = abs(divisor);

        int quotient = 0;
        // Subtract the divisor from the dividend until the dividend is less than the divisor
        while(n >= d){
            int count = 0;
            // Find the largest shift such that (divisor << count + 1) is less than or equal to the dividend
            while(n >= (d << (count + 1))){
                count++;
            }
            // Add the corresponding power of 2 to the quotient
            quotient += 1 << count;
            // Subtract the shifted divisor from the dividend
            n = n - (d << count);
        }

        if(quotient == (1 << 31) && sign) return INT_MAX;
        if(quotient == (1 << 31) && !sign) return INT_MIN;

        return sign? quotient : -quotient;
    }
};