// Substrings of Size Three with Distinct Characters (Leetcode)
// Leetcode Link : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3;
        // If string is shorter than 3, no good substrings
        if(s.size() < k) return 0;

        int countSubstr = 0;

        for(int i = 0; i < s.size()-2; i++){
            char ch1 = s[i]; // First character of the substring
            char ch2 = s[i+1]; // Second character of the substring
            char ch3 = s[i+2]; // Third character of the substring

            // Check if all characters are different
            if(ch1 != ch2 && ch1 != ch3 && ch2 != ch3){
                countSubstr++; // Increment count for a good substring
            }
        }

        return countSubstr;
    }
};