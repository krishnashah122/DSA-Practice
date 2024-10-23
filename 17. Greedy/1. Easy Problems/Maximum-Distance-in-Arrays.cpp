// Maximum Distance in Arrays (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-distance-in-arrays/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Step 1: Initialize MIN to the first array's front element & MAX to the first array's back element
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();
        int ans = 0;

        for(int i = 1; i < arrays.size(); i++){
            // Step 2: Get the current array's front element & back element
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            // Step 3: Calculate maximum distance based on current MIN, MAX and update ans
            ans = max({ans, abs(currMin - MAX), abs(currMax - MIN)});

            // Step 4: Update MIN and MAX with the current array's values
            MIN = min(MIN, currMin);
            MAX = max(MAX, currMax);
        }

        return ans;
    }
};