// Number of Substrings Containing All Three Characters (Leetcode)
// Leetcode Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

// Time Complexity : O(n)
// Space Complexity : O(3) = O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int countSubstr = 0;
        int lastSeen[3] = {-1, -1, -1}; // Array to keep track of the last seen index of 'a', 'b', and 'c'

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            char ch = s[right];
            // Update the last seen index of the current character ('a', 'b', or 'c')
            lastSeen[ch - 'a'] = right;

            // Find the smallest index among the last seen positions of 'a', 'b', and 'c'
            int minIdx = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            // The number of valid substrings that end at the current 'right' index
            // is increased by '1 + minIdx' (1 for the current substring and minIdx for previous valid ones)
            countSubstr += 1 + minIdx;
        }

        return countSubstr;
    }
};