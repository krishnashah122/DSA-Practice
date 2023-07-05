// Square root of a number (GFG)
// GFG Link : https://bit.ly/3JXtGcE

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int low = 1;
        long long int high = x;
        
        while(low <= high){
            long long int mid = low + (high - low) / 2;
            
            if(mid*mid <= x){
                low = mid + 1; // to search in right part
            }
            else{
                high = mid - 1; // to search in left part
            }
        }
        return high;
    }
};