// LIS using Binary Search [Longest Increasing Subsequence] (GFG)
// GFG Link : https://shorturl.at/IfWHm

// Time Complexity : O(n * logn)
// Space Complexity : O(n)

class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(vector<int>& arr) {
        // code here
        // Step 1: Initialize a temporary array to track potential LIS
        vector<int> temp;
        
        // Step 2: Start with the first element in the LIS
        temp.push_back(arr[0]);
        int len = 1; // Initialize the LIS length

        // Step 3: Iterate over each element in the array
        for(int i = 1; i < arr.size(); i++) {
            // Step 4: If current element is greater than last in temp, extend LIS
            if(arr[i] > temp.back()) {
                temp.push_back(arr[i]);
                len++;
            } else {
                // Step 5: Replace the smallest element in temp >= arr[i] to maintain LIS
                int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[idx] = arr[i];
            }
        }
        
        // Step 6: Return the LIS length
        return len;
    }
};