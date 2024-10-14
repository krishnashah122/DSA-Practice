// Palindrome Partitioning (Leetcode)
// Leetcode Link : https://leetcode.com/problems/palindrome-partitioning/description/

// Time Complexity : O(n * 2^n)
// Space Complexity : O(n * 2^n)

class Solution {
public:
    // Function to check if a given string is a palindrome
    bool isPalindrome(string str){
        int i = 0;
        int j = str.size() - 1;

        while(i < j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(string s, int start, vector<string> &palindromes, vector<vector<string>> &ans){
        // Base case: if start index reaches the end of the string
        if(start == s.size()){
            ans.push_back(palindromes); // Add the current partition to the answer
            return;
        }

        string substr; // Temporary string to hold substrings
        for(int i = start; i < s.size(); i++){
            substr += s[i]; // Form substring by adding one character at a time

            // Check if the substring is a palindrome
            if(isPalindrome(substr)){
                palindromes.push_back(substr); // Add palindrome to the list
                solve(s, i+1, palindromes, ans); // Recur for the rest of the string
                palindromes.pop_back(); // Backtrack to explore other partitions
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palindromes;
        solve(s, 0, palindromes, ans);
        return ans;
    }
};