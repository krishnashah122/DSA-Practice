// Candy (Leetcode)
// Leetcode Link : https://leetcode.com/problems/candy/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> maxCandy(n, 1); // Initialize maxCandy array with 1 candy for each child

        // Step 1: Forward pass - ensure higher rating child gets more candy than left neighbor
        for(int i = 1; i < n; i++){
            if(ratings[i-1] < ratings[i]){
                maxCandy[i] = maxCandy[i-1] + 1;
            }
        }

        int curr = 1; // Track no. of candies the current child hold from Right-to-Left pass
        int right = 1; // Track right neighbor's candy count
        int minCandy = max(maxCandy[n-1], 1); // Initialize minCandy based on last child's candies

        // Step 2: Backward pass - ensure higher rating child gets more candy than right neighbor
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                curr = right + 1;
            }else{
                curr = 1;
            }
            right = curr; // Update right candy count
            minCandy += max(maxCandy[i], curr); // Accumulate the maximum of left or right candy count
        }

        return minCandy;
    }
};