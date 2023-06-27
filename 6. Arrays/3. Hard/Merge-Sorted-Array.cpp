// Merge Sorted Array (Leetcode)
// Leetcode Link : https://leetcode.com/problems/merge-sorted-array/description/

// Time Complexity : O(m+n)
// Space Complexity : O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        
        while(m > 0 && n > 0){ // O(m+n)
            if(nums1[m-1] > nums2[n-1]){
                nums1[k] = nums1[m-1];
                m--;
            }else{
                nums1[k] = nums2[n-1];
                n--;
            }
            k--;
        }
        while(n > 0){
            nums1[k] = nums2[n-1];
            n--;
            k--;
        }
    }
};