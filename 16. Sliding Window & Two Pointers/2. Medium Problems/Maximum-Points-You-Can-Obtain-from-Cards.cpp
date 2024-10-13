// Maximum Points You Can Obtain from Cards (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

// Time Complexity : O(k)
// Space Complexity : O(1)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0;
        int rSum = 0;

        // Calculate the sum of the first 'k' elements from the left
        for(int i = 0; i < k; i++){
            lSum += cardPoints[i];
        }

        int maxSum = lSum; // Initialize maxSum with lSum
        int rIdx = cardPoints.size() - 1; // Right index starts from the end of the array

        // Slide the window from the end of the array towards the start
        for(int i = k-1; i >= 0; i--){
            lSum -= cardPoints[i]; // Remove the current leftmost card value
            rSum += cardPoints[rIdx]; // Add the current rightmost card value
            rIdx--; // Move the right index leftwards
            // Update maxSum with the maximum of current maxSum and the new sum
            maxSum = max(maxSum, (lSum + rSum));
        }

        return maxSum;
    }
};