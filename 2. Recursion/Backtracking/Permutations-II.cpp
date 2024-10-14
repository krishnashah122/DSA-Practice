// Permutations II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/permutations-ii/description/

// Time Complexity : O(n * n!)
// Space Complexity : O(n!)

class Solution {
public:
    // Helper function to generate permutations
    void solve(vector<int>& nums, int start, vector<vector<int>>& ans){
        // Base case: if we have reached the last element, add the current permutation to the answer
        if(start == nums.size() - 1){
            ans.push_back(nums);
            return;
        }

        set<int> st; // Set to track duplicate elements

        for(int i = start; i < nums.size(); i++){
            // If nums[i] has not been swapped before, we can proceed
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);  // Mark nums[i] as used

                // Swap the current element with the 'start' element
                swap(nums[start], nums[i]);
                
                // Recur to generate permutations for the next part of the list
                solve(nums, start + 1, ans);
                
                // Backtrack: Undo the swap to restore the original configuration
                swap(nums[start], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};