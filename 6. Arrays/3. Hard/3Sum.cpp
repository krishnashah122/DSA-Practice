// 3Sum (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/3sum/description/
// GFG Link : https://bit.ly/3C9uTvQ

// Algorithm Used : Two Pointer Technique
// Time Complexity : O(n^2)
// Space Complexity : O(3*k) [Where k is the no. of unique triplets. Only using this space to store the answer not to solve the problem. So, from that perspective Space Complexity can be written as O(1).]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // sort the array
        sort(nums.begin(), nums.end()); // O(nLogn)

        for(int i = 0; i < nums.size(); i++){ // O(n)
            // avoid the duplicates while moving i
            if(i > 0 && nums[i] == nums[i-1]) continue;
            // 2 pointers
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){ // O(n)
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // skip duplicates
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};