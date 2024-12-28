// Word Break (Leetcode)
// Leetcode Link : https://leetcode.com/problems/word-break/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n + d) [where, d = size of dictionary]

class Solution {
public:
    bool solve(string &s, int start, unordered_set<string> &dictSet, vector<int> &dp){
        // Step 1: If at end of string, return true
        if(start == s.size()) return true;

        // Step 2: Return saved result if already calculated
        if(dp[start] != -1) return dp[start];

        // Step 3: Check all words starting from 'start'
        string word;
        for(int i = start; i < s.size(); i++){
            word += s[i];
            // Step 4: If word is in dictionary and rest can be solved, return true
            if(dictSet.find(word) != dictSet.end() && solve(s, i+1, dictSet, dp)){
                return dp[start] = true;
            }
        }

        // Step 5: Save and return false if no match found
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Step 6: Save wordDict in a set for fast lookup
        unordered_set<string> dictSet;
        dictSet.insert(wordDict.begin(), wordDict.end());
        // Step 7: Create DP array for caching results
        vector<int> dp(s.size(), -1);
        // Step 8: Start solving from index 0
        return solve(s, 0, dictSet, dp);
    }
};