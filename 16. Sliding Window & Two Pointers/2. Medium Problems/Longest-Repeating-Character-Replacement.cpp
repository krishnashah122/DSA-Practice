// Longest Repeating Character Replacement (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-repeating-character-replacement/description/

// Time Complexity : O(n)
// Space Complexity : O(26) = O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int longestSubstr = 0;

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            // Increment the frequency of the current character
            mp[s[right]]++;
            // Update the maximum frequency of any character in the current window
            maxFreq = max(maxFreq, mp[s[right]]);
            
            // Check if the current window size minus the maximum frequency is greater than k
            // If so, we need to shrink the window from the left
            if(((right-left+1) - maxFreq) > k){
                mp[s[left]]--; // Decrease the frequency of the character at the left pointer
                left++; // Move the left pointer to the right
            }

            // Update the length of the longest substring found
            longestSubstr = max(longestSubstr, (right-left+1));
        }

        return longestSubstr;
    }
};