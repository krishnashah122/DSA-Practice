// Floor in a Sorted Array (GFG)
// GFG Link : https://bit.ly/3Cf398N

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        int ans = -1;
        long long low = 0;
        long long high = n - 1;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            
            if(v[mid] <= x){
                ans = (int)mid;
                low = mid + 1; // to search in right half for the larger element
            }
            else{
                high = mid - 1; // to search in left half
            }
        }
        return ans;
    }
};