// Minimum Platforms (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Time Complexity : O(n + nLogn)
// Space Complexity : O(1)

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        // Step 1: Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms = 0;  // Current no. of platforms needed
        int maxPlatforms = 0;  // Maximum platforms required
        
        int i = 0; // Arrival array pointer
        int j = 0; // Departure array pointer
        
        // Step 2: Traverse the arrays
        while(i < arr.size()) {
            if(arr[i] <= dep[j]) {
                // Step 3: If a train arrives before or when another departs, increment platforms
                platforms++;
                i++;
            } else {
                // Step 4: If a train departs, free up a platform
                platforms--;
                j++;
            }
            // Step 5: Update the maximum number of platforms needed
            maxPlatforms = max(maxPlatforms, platforms);
        }
        
        return maxPlatforms;
    }
};