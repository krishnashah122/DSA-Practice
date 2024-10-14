// Non-decreasing Subsequences (Leetcode)
// Leetcode Link : https://leetcode.com/problems/non-decreasing-subsequences/description/

// Time Complexity : O(n * 2^n)
// Space Complexity : O(n * 2^n)

class Solution {
public:
    // Recursive function to find subsequences
    void solve(vector<int> &nums, int start, vector<int> &arr, set<vector<int>> &result){
        // Base case: if start reaches the end of the nums array, return
        if(start == nums.size()){
            return;
        }

        for(int i = start; i < nums.size(); i++){
            // If arr is empty, just add the current number
            if(arr.empty()){
                arr.push_back(nums[i]);
                solve(nums, i+1, arr, result); // Recursive call to continue finding subsequences
                arr.pop_back(); // Backtrack by removing the last element
            }else{
                // If current number is >= last element of arr, add it to subsequence
                if(nums[i] >= arr.back()){
                    arr.push_back(nums[i]);
                    result.insert(arr); // Insert the subsequence into the set to maintain uniqueness
                    solve(nums, i+1, arr, result); // Recursive call to continue finding subsequences
                    arr.pop_back(); // Backtrack by removing the last element
                }
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> arr;
        solve(nums, 0, arr, result);
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};