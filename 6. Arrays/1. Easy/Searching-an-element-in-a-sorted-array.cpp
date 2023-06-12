// Searching an element in a sorted array (GFG)
// GFG Link : https://bit.ly/3KcpHcB

// Algorithm Used : Binary Search
// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    { 
    
       // Your code here
       int low = 0;
       int high = N;
       while(low <= high){
           int mid = (low + high)/2;
           if(arr[mid] == K){
               return 1;
           }
           else if(arr[mid] < K){
               low = mid + 1;
           }
           else if(arr[mid] > K){
               high = mid - 1;
           }
       }
       return -1;
    }
};