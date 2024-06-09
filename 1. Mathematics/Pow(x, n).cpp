// Pow(x, n) (Leetcode)
// Leetcode Link : https://leetcode.com/problems/powx-n/description/

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    double myPow(double x, int n) {
        // Taking long to avoid overflow
        long power = n;
        long m = power;
        
        // If n is negative then make it positive
        if(power < 0) power = -power;

        double ans = 1;
        while(power > 0){
            // If n is odd
            if(power % 2 == 1){
                ans *= x;
                power = power - 1;
            // If n is even
            }else{
                power /= 2;
                x *= x;
            }
        }

        // If n was negative, assign reciprocal of ans to ans
        if(m < 0){
            ans = 1 / ans;
        }

        return ans;
    }
};