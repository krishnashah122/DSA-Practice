// Valid Parenthesis String (Leetcode)
// Leetcode Link : https://leetcode.com/problems/valid-parenthesis-string/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;

        for(char ch : s){
            // Increment both min and max for '('
            if(ch == '('){
                min++;
                max++;
            }else if(ch == ')'){
                // Decrement both min and max for ')'
                min--;
                max--;
            }else{
                // Decrement min and increment max for '*'
                min--; // min decreases since '*' can be ')'
                max++; // max increases since '*' can be '('
            }

            if(min < 0) min = 0; // Ensure min doesn't go negative
            if(max < 0) return false; // Invalid if max becomes negative
        }

        return (min == 0); // Valid if no unmatched '(' remains
    }
};