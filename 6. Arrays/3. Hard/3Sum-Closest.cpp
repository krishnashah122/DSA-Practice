// 3Sum Closest (Leetcode)
// Leetcode Link : https://leetcode.com/problems/3sum-closest/description/

// Time Complexity : O(n^2)
// Space Complexity : O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = -1;
        int diff = INT_MAX;
        // sort the array
        sort(nums.begin(), nums.end());

        // if the nums[] size is less than 3 then return 0
        if(nums.size() < 3) return 0;

        for(int i = 0; i < nums.size(); i++){ // O(n)
            // avoid duplicates while moving i
            if(i > 0 && nums[i] == nums[i-1]) continue;
            // 2 pointers
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){ // O(n)
                int sum = nums[i] + nums[j] + nums[k];

                // update the diff and closestSum if (sum - target) < diff
                if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    closestSum = sum;
                }

                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return sum;
                }
            }
        }
        return closestSum;
    }
};