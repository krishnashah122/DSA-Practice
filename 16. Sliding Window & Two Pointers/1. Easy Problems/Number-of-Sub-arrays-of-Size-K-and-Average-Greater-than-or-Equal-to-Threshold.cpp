// Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold (Leetcode)
// Leetcode Link : https://shorturl.at/Yrgn5

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int left = 0;
        double avg = INT_MIN;
        int countSubarr = 0;

        for(int right = 0; right < arr.size(); right++){
            // If the window size exceeds k, move the left boundary to the right
            if(k < (right - left + 1)){
                sum -= arr[left]; // Subtract the element that is leaving the window
                left++; // Move the left boundary to the right
            }

            sum += arr[right]; // Add the current element to the sum of the window
            // When the window size equals k, compute the average
            if(k == (right - left + 1)) avg = (double)(sum / k);
            // If the average is greater than or equal to the threshold, increment the subarray count
            if(avg >= threshold) countSubarr++;
        }

        return countSubarr;
    }
};