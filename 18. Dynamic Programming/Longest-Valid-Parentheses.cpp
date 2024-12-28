// Longest Valid Parentheses (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-valid-parentheses/description/

// Time Complexity : O(n)
// Space Complexity : (n)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0;
        int close = 0;
        int longest = 0;

        // Step 1: Traverse from left to right
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                open++; // Increment open if '(' is found
            }else{
                close++; // Increment close if ')' is found
            }

            if(open == close){
                longest = max(longest, 2 * open); // Update longest if valid substring found
            }else if(close > open){
                open = close = 0; // Reset counters when ')' exceeds '('
            }
        }

        // Step 2: Reset counters for second traversal
        open = 0;
        close = 0;

        // Step 3: Traverse from right to left
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ')'){
                close++; // Increment close if ')' is found
            }else{
                open++; // Increment open if '(' is found
            }

            if(open == close){
                longest = max(longest, 2 * open); // Update longest if valid substring found
            }else if(open > close){
                open = close = 0; // Reset counters when '(' exceeds ')'
            }
        }
        
        return longest;
    }
};