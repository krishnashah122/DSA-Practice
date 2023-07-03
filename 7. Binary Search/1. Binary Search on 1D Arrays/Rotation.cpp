// Rotation (GFG)
// GFG Link : https://bit.ly/3dEvWJD

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    int low = 0;
        int high = n - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            // if the search space is already sorted then return (low - 0) as the no. of rotation
            if(nums[low] < nums[high]){
                return low - 0;
            }

            // if nums[mid] > nums[high] then it means minimum element is in right part
            if(nums[mid] > nums[high]){
                low = mid + 1; // to search in right part
            }
            // if nums[mid] < nums[high] then it means minimum is in left part
            else{
                high = mid; // to search in left part including mid
            }
        }
        // return (low - 0) as no. the of rotation
        return low - 0;
	}
};