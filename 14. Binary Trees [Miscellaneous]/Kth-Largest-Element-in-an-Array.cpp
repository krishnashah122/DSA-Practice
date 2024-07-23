// Kth Largest Element in an Array (Leetcode)
// Leetcode Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Time Complexity : O(n) [Average] and O(n^2) [Worst]
// Space Complexity : O(1)

class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int pivotElement = nums[low];
        int i = low + 1;
        int j = high;

        while(i <= j){
            // Swap elements to move smaller elements to the left and larger elements to the right
            if(nums[i] < pivotElement && pivotElement < nums[j]){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            // Move the left pointer to the right if the current element is greater than or equal to the pivot
            if(nums[i] >= pivotElement) i++;
            // Move the right pointer to the left if the current element is less than or equal to the pivot
            if(pivotElement >= nums[j]) j--;
        }
        swap(nums[low], nums[j]);

        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int pivotIdx = 0;

        while(true){
            pivotIdx = partition(nums, low, high);

            // If the pivot index matches (k-1), we found the k-th largest element
            if(pivotIdx == k-1){
                break;
            }else if(pivotIdx > k-1){
                // If pivot index is greater, search the left part
                high = pivotIdx - 1;
            }else{
                // If pivot index is smaller, search the right part
                low = pivotIdx + 1;
            }
        }

        return nums[pivotIdx];
    }
};