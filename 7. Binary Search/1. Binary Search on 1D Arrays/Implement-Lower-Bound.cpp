// Implement Lower Bound (Code Studio)
// Code Studio Link : https://www.codingninjas.com/studio/problems/lower-bound_8165382

// Time Complexity : O(Logn)
// Space Complexity : O(1)

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0;
	int high = n - 1;
	int ans = n;

	while(low <= high){
		int mid = low + (high - low) / 2;
		
		// it may be an answer
		if(arr[mid] >= x){
			ans = mid;
			// to look for more small index on left
			high = mid - 1;
		}
		else{
			// to look for more small index on right
			low = mid + 1;
		}
	}
	return ans;
}
