// Find the Smallest Divisor Given a Threshold (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// GFG Link : https://bit.ly/3SJogFR

// Time Complexity : O(nLogm)
// Space Complexity : O(1)

class Solution {
public:
    // function to find the smallest divisor
    bool isSmallestDivisor(vector<int>& nums, int mid, int threshold){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){ // O(n)
            sum += ceil((double)nums[i] / (double)mid);
        }

        // if sum is less than or equal to the threshold then return true else return false
        if(sum <= threshold) return true;

        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MIN;
        // find the max element of the array and assign it to high
        for(int i = 0; i < nums.size(); i++){ // O(n)
            high = max(high, nums[i]);
        }

        // if the size of the array is greater than the threshold then return -1
        if(nums.size() > threshold) return -1;

        while(low < high){ // O(Logm)
            int mid = low + (high - low) / 2;

            // if mid is possible smallest divisor then search smaller than mid in left part
            if(isSmallestDivisor(nums, mid, threshold)){
                high = mid; // to search in left part
            }
            // if mid is not possible smallest divisor then search smallest divisor in right part
            else{
                low = mid + 1; // to search in right part including mid
            }
        }
        return low;
    }
};