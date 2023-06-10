// Rotate Array (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/rotate-array/
// GFG Link : https://bit.ly/3dyCKZg

// Time Complexity : O(n)
// Space Complexity : O(1)


// For Rotating an Array to Right by K places. (Leetcode)
class Solution {
public:
    void reverse(vector <int> &nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // Reverse the first n-k elements of the array
        reverse(nums, 0, n-k-1);
        // Reverse the last k elements of the array
        reverse(nums, n-k, n-1);
        // Reverse the whole array
        reverse(nums, 0, n-1);
    }
};


// For Rotating an Array for Left by D places. (GFG)
class Solution{   
public:

    void reverse(int arr[], int start, int end){
        while(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void leftRotate(int arr[], int n, int d) {
        // code here
        // Reverse the first d elements of the array
        reverse(arr, 0, d-1);
        // Reverse the last n-d elements of the array
        reverse(arr, d, n-1);
        // Reverse the whole array
        reverse(arr, 0, n-1);
    }
};