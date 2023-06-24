// Count Inversions (GFG)
// GFG Link : https://bit.ly/3PtLWLM

// Algorithm Used : Merge Sort
// Time Complexity : O(nLogn)
// Space Complexity : O(n)

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    
    // Function to merge sort the array
    long long merge(long long arr[], long long low, long long mid, long long high){
        vector <long long> temp; // Empty Array
        long long left = low; // Starting index of left half array
        long long right = mid+1; // Starting index of right half array
        long long count = 0;
    
        // Two halves : [low to mid] and [mid+1 to high]
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            // right is smaller
            else{
                temp.push_back(arr[right]);
                right++;
                count += (mid - left + 1);
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
        for(long long i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }
        
        return count;
    }

    long long mergeSort(long long arr[], long long low, long long high) {
        // Write your code here.
        long long count = 0;
    
        // Base Case
        if(low >= high){
            return count;
        }
        long long mid = (low + high)/2;
    
        // Left Half
        count += mergeSort(arr, low, mid);
        // Right Half
        count += mergeSort(arr, mid+1, high);
        // Merge the Left and Right Half returned array
        count += merge(arr, low, mid, high);
        return count;
    }
    
    
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }
};