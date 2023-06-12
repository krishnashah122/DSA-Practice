// Two Sum (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/two-sum/description/

// Time Complexity : O(n) [The loop runs n times in the worst case and searching in a hashmap takes O(1) generally.]
// Space Complexity : O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            // required number to sum to become target
            int required = target - nums[i];
            // check required number is present in mpp or not
            if(mpp.find(required) != mpp.end()){
                // return the index of required number and current index
                return {mpp[required], i};
            }

            // if required number is not present then add it in the mpp along with its index
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};