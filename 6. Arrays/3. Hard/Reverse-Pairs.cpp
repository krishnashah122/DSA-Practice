// Reverse Pairs (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/reverse-pairs/description/
// GFG Link : https://practice.geeksforgeeks.org/problems/count-reverse-pairs/1

// Algorithm Used : Merge Sort
// Time Complexity : O(nLogn)
// Space Complexity : O(n)

class Solution {
public:

    // Function to count pairs
    int countPairs(vector<int> &arr, int low, int mid, int high){
        int right = mid + 1;
        int count = 0;
        
        for(int i = low; i <= mid; i++){
            while(right <= high && (long long)arr[i] > (long long)2*arr[right]){
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }
  
    // Function to merge sort the array
    void merge(vector < int > &arr, int low, int mid, int high){
        vector <int> temp; // Empty Array
        int left = low; // Starting index of left half array
        int right = mid+1; // Starting index of right half array
    
        // Two halves : [low to mid] and [mid+1 to high]
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
    
        // Copying left-out elements from left half
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
    
        // Copying left-out elements form right half
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
    
        // Inserting form temp array to original array
        for(int i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }
    }
    
    int mergeSort(vector < int > & arr, int low, int high) {
        int count = 0;
    
        // Base Case
        if(low >= high){
            return count;
        }
        int mid = (low + high)/2;
    
        // Left Half
        count += mergeSort(arr, low, mid);
        // Right Half
        count += mergeSort(arr, mid+1, high);
        // Count the no. of pairs
        count += countPairs(arr, low, mid, high);    
        // Merge the Left and Right Half returned array
        merge(arr, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};