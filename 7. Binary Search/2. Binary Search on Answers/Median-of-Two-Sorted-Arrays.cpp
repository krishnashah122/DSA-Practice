// Median of Two Sorted Arrays (Leetcode)
// Leetcode Link : https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Code Studio Link : https://shorturl.at/szIZ3

// Time Complexity : O(Log(min(n1, n1)))
// Space Complexity : O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        // if n1 > n2 then swap then to enusre n1 is smaller than n2
        if(n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = n1;
        while(low <= high) { // O(Logn1)
            int mid1 = (low + high) / 2; // no. of elements from nums1 for the left part
            int mid2 = (n1 + n2 + 1) / 2 - mid1; // no. of elements from nums2 for the left part

            int maxLeft1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int minRight1 = (mid1 == n1) ? INT_MAX : nums1[mid1];

            int maxLeft2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            int minRight2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                int maxLeft = max(maxLeft1, maxLeft2);
                int minRight = min(minRight1, minRight2);

                // if the no. of total elements are even
                if((n1 + n2) % 2 == 0){
                    return (double)(maxLeft + minRight) / 2;
                }
                // if the no. of total elements are odd
                else {
                    return (double)maxLeft;
                }
            } else if(maxLeft1 > minRight2) {
                high = mid1 - 1; // to search in the left part of nums1
            } else {
                low = mid1 + 1; // to search in the right part of nums1
            }
        }
        return -1;
    }
};