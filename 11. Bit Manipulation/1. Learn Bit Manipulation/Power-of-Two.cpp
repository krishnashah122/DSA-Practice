// Power of Two (Leetcode)
// Leetcode Link : https://leetcode.com/problems/power-of-two/description/

// Time Complexity : O(1)
// Space Complexity : (1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // APPROACH 1: (Recommended)
        
        // Ex: n = 16 (i.e 10000) then n-1 = 15 (i.e. 01111)
        // (10000) & (01111) == (00000) i.e. 0
        if (n > 0 && (n & n-1) == 0){
            return true;
        }
        
        return false;
        

        /* APPROACH 2:

        int x = 0;
        int temp = n;

        // Keep dividing temp until temp >= 2, to find x
        while(temp >= 2){
            x++;
            temp /= 2;
        }

        // 2^x equals to 1 followed by x times 0
        // Ex: 2^4 equals to 10000
        int mask = 1 << x;
        if(n == mask){
            return true;
        }
        
        return false;
        */
    }
};