// Minimum Bit Flips to Convert Number (Leetcode)
// Leetcode Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

// Time Complexity : O(Logn) where, n is (start ^ goal)
// Space Complexity : O(1)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR the two numbers to find differing bits (flips needed)
        int ans = start ^ goal;
        int count = 0;

        for(int i = 0; i <= 31; i++){
            // Check if the ith bit is set in the XOR result (means the bit differs between start and goal)
            if(ans & (1 << i)){
                // Increment the count of differing bits
                count++;
            }
        }
        return count;
    }
};