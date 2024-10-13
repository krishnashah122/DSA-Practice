// Maximum Average Subarray I (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-average-subarray-i/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        double sum = 0;

        // Calculate the sum of the first 'k' elements in the array.
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        // Calculate the initial average of the first 'k' elements.
        double maxAvg = (sum / k);

        // Slide the k sized window from left to right across the array.
        for(int left = 0, right = k; right < nums.size(); left++, right++){
            // Remove the element going out of the window.
            sum -= nums[left];
            // Add the element coming into the window.
            sum += nums[right];
            // Update the maximum average.
            maxAvg = max(maxAvg, (sum/k));
        }

        return maxAvg;
    }
};