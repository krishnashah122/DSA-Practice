// Find Nth root of M (GFG)
// GFG Link : https://bit.ly/3zWNyrL

// Time Complexity : O(Logm * Logn)
// Space Complexity : O(1)

class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low = 1;
	    int high = m;
	    
	    while(low <= high){
	        int mid = low + (high - low) / 2;
	        
	        // if mid^n == m (i.e. nth root of m == mid) then return mid
	        if(pow(mid, n) == m){
	            return mid;
	        }
	        else if(pow(mid, n) < m){
	            low = mid + 1; // to search in right part
	        }
	        else{
	            high = mid - 1; // to search in left part
	        }
	    }
	    return -1;
	}  
};