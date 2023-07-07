// Kth Missing Positive Number (Leetcode)
// Leetcode Link : https://leetcode.com/problems/kth-missing-positive-number/description/

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int missingNums = arr[mid] - (mid + 1);
            // if missingNums is less than the given k
            if(missingNums < k){
                low = mid + 1; // to search in right part
            }
            else{
                high = mid - 1; // to search in left part
            }
        }
        return (high + 1 + k); // arr[high] + k - missingNums[i.e. arr[high] - (high + 1)]
    }
};