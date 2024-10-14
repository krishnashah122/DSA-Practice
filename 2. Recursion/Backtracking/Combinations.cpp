// Combinations (Leetcode)
// Leetcode Link : https://leetcode.com/problems/combinations/description/

// Time Complexity : O(nCk) = O(n! / (k! * (n-k)!))
// Space Complexity : O(n * nCk) = O(n * (n! / (k! * (n-k)!)))

class Solution {
public:
    // Helper function to find all combinations
    void solve(int n, int k, int start, vector<int> &combination, vector<vector<int>> &ans){
        // If k elements are selected, add the current combination to the answer
        if(k == 0){
            ans.push_back(combination);
            return;
        }

        for(int i = start; i <= n; i++){
            combination.push_back(i);  // Add the current number in the combination
            solve(n, k-1, i+1, combination, ans);  // Recur to find the next number
            combination.pop_back();  // Backtracking
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combination;
        solve(n, k, 1, combination, ans);
        return ans;
    }
};