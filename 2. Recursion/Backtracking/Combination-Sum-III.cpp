// Combination Sum III (Leetcode)
// Leetcode Link : https://leetcode.com/problems/combination-sum-iii/description/

// Time Complexity : O(9^k)
// Space Complexity : O(k * 9^k)

class Solution {
public:
    // Helper function to find combinations of size k that sum to n
    void solve(int k, int n, int start, vector<int> &nums, vector<vector<int>> &ans){
        // If we have selected k numbers
        if(k == 0){
            int sum = 0;
            for(auto num : nums){
                sum += num;  // Calculate the sum of the current combination
            }
            if(sum == n) ans.push_back(nums);  // If sum matches n, add the combination to the result
            return;
        }

        // Try adding numbers from start to 9
        for(int i = start; i <= 9; i++){
            // Ensure numbers are in increasing order
            if(nums.size() == 0 || nums.back() < i){
                nums.push_back(i);  // Add the current number
                solve(k-1, n, start+1, nums, ans);  // Recur to fill remaining k-1 positions
                nums.pop_back();  // Backtrack after exploring this path
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        solve(k, n, 1, nums, ans);
        return ans;
    }
};