// Implement Upper Bound (Code Studio)
// Code Studio Link : https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383

// Time Complexity : O(Logn)
// Space Complexity : O(1)

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	int low = 0;
	int high = n - 1;
	int ans = n;

	while(low <= high){
		int mid = low + (high - low) / 2;

		// it may be an answer
		if(arr[mid] > x){
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