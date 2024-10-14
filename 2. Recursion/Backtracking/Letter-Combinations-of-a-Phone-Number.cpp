// Letter Combinations of a Phone Number (Leetcode)
// Leetcode Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

// Time Complexity : O(4^n)
// Space Complexity : O(n * 4^n)

class Solution {
public:
    void solve(string digits, map<char, string> &mp, string &s, int start, vector<string> &ans){
        // Base case: if we've processed all digits, add the current combination to ans
        if(start == digits.size()){
            ans.push_back(s);
            return;
        }

        // Loop through each letter mapped to the current digit
        for(int i = 0; i < mp[digits[start]].size(); i++){
            s += mp[digits[start]][i]; // Add current letter to the combination
            solve(digits, mp, s, start+1, ans); // Recur for the next digit
            s.pop_back(); // Backtracking
        }
    }

    vector<string> letterCombinations(string digits) {
        string s;
        vector<string> ans;

        // If the input string is empty, return an empty result
        if(digits.size() == 0) return ans;

        // Map digits to corresponding letters
        map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        solve(digits, mp, s, 0, ans);
        return ans;
    }
};