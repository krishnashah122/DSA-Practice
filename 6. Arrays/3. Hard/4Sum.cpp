// 4Sum (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/4sum/description/
// GFG Link : https://bit.ly/3psQR53

// Algorithm Used : Two Pointer Technique
// Time Complexity : O(n^3)
// Space Complexity : O(4*k) [Where k is the no. of unique quadruplets. Only using this space to store the answer not to solve the problem. So, from that perspective Space Complexity can be written as O(1).]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        // sort the array
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            // avoid the duplicates while moving i
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i + 1; j < nums.size(); j++){
                // avoid the duplicates while moving j
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                // 2 pointers
                int k = j + 1;
                int l = nums.size() - 1;

                while(k < l){
                    // taking bigger data type to avoid integer overflow
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        // skip duplicates
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};