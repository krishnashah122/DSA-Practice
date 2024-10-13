// Contains Duplicate II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/contains-duplicate-ii/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            // Check if the current element is already in the map
            if(mp.find(nums[i]) != mp.end()){
                // Get the last index where the element was seen
                int idx = mp[nums[i]];
                // Check if the difference between the current index and the last index is within k
                if(abs(idx - i) <= k){
                    // If so, return true
                    return true;
                }
            }
            // Insert or update the map with the current index of the element
            mp[nums[i]] = i;
        }

        return false;
    }
};