// Split Array Largest Sum (Leetcode & Code Studio)
// Leetcode Link : https://leetcode.com/problems/split-array-largest-sum/description/
// Code Studio Link : https://shorturl.at/nFKNU

// Time Complexity : O(nLogm)
// Space Complexity : O(1)

class Solution {
public:
    // function to count the subarrays that can have the largest sum 's'
    int countSubarrays(vector<int>& nums, int s){
        int noOfSubarrays = 1; // count the no. of subarray that can have the largest sum 's'
        int totalSum = 0; // sum of the elements of the subarray

        // count the no. of subarrays that can have the largest sum 's'
        for(int i = 0; i < nums.size(); i++){ // O(n)
            // if totalSum + nums[i] less than or equal to the sum 's'
            if(totalSum + nums[i] <= s){
                totalSum += nums[i]; // add nums[i] to the totalSum
            }
            else{
                noOfSubarrays++; // increase the subarray count by 1
                totalSum = nums[i]; // initialize the totalSum of new subarray with nums[i]
            }
        }
        return noOfSubarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int sum = 0;
        // find the max element of the array and the sum of the elements of the array
        for(int i = 0; i < nums.size(); i++){ // O(n)
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }

        int low = maxi;
        int high = sum;
        while(low <= high){ // O(Logm)
            int mid = low + (high - low) / 2;

            int subarrays = countSubarrays(nums, mid);
            // if subarrays for sum 'mid' is greater than given sum 'k'
            if(subarrays > k){
                low = mid + 1; // to search in right part
            }
            // if subarrays for sum 'mid' is not greater than given sum 'k'
            else{
                high = mid - 1; // to search in left part
            }
        }
        return low;
    }
};