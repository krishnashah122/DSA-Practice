// Longest Substring Without Repeating Characters (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int i = 0;
        int maxLen = 0;

        for(int j = 0; j < s.size(); j++){
            // If the character at 'j' is already in the set, 
            // remove characters from the left until it's no longer in the set
            while(charSet.find(s[j]) != charSet.end()){
                charSet.erase(s[i]);
                i++;
            }
            // Add the current character to the set
            charSet.insert(s[j]);
            // Update the maximum length of the substring found
            maxLen = max(maxLen, (j-i+1));
        }

        return maxLen;
    }
};