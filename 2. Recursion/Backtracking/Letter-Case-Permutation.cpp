// Letter Case Permutation (Leetcode)
// Leetcode Link : https://leetcode.com/problems/letter-case-permutation/description/

// Time Complexity : O(n * 2^l) [where, n is the no. of permutations and l is the length of the string.]
// Space Complexity : O(n * 2^l)

class Solution {
public:
    void solve(string &s, int start, set<string> &permutations){
        // Base case: if we reach the end of the string, add the permutation to the set
        if(start == s.size()){
            permutations.insert(s);
            return;
        }

        for(int i = start; i < s.size(); i++){
            // If the current character is a digit, continue without changing case
            if(isdigit(s[i])){
                solve(s, i+1, permutations);
            }else{
                // If the current character is an alphabet
                s[i] = toupper(s[i]); // Change the current char to uppercase
                solve(s, i+1, permutations); // Recur after changing the case of current char
                s[i] = tolower(s[i]); // Backtrack: Change the current char back to lowercase
                solve(s, i+1, permutations); // Recur after changing the case of current char
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        set<string> permutations; // Set to store unique permutations
        solve(s, 0, permutations);
        vector<string> ans(permutations.begin(), permutations.end()); // Convert set to vector
        return ans;
    }
};