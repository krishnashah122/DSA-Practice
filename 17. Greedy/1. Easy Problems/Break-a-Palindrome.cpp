// Break a Palindrome (Leetcode)
// Leetcode Link : https://leetcode.com/problems/break-a-palindrome/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        // Step 1: If length is 1, non-palindrome is not possible so return empty string.
        if(n == 1) return "";

        for(int i = 0; i < n/2; i++){
            // Step 2: Find the first non-'a' char in the first half, change it to 'a' & then return modified palindrome.
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // Step 3: If no changes were made, change the last character to 'b'.
        palindrome[n-1] = 'b';

        return palindrome;
    }
};