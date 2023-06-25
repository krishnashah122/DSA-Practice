// Maximum Product Subarray (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/maximum-product-subarray/description/
// GFG Link : https://bit.ly/3PrlQsU

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        int prefix = 1;
        int suffix = 1;

        for(int i = 0; i < n; i++){
            // if prefix is 0 then reset it to 1
            if(prefix == 0) prefix = 1;
            // if suffix is 0 then reset it to 1
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            maximum = max(maximum, max(prefix, suffix));
        }
        return maximum;
    }
};