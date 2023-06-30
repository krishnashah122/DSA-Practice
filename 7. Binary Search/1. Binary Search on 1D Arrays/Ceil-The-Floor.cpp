// Ceil The Floor (GFG & Code Studio)
// GFG Link : https://bit.ly/3CgDDjE
// Code Studio Link : https://www.codingninjas.com/codestudio/problems/ceiling-in-a-sorted-array_1825401

// Time Complexity : O(nLogn)
// Space Complexity : O(1)

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    // sort the array
	sort(arr, arr + n); // O(nLogn)

	int low = 0;
	int high = n - 1;
	int floor = -1;
	int ceil = -1;

	while(low <= high){ // O(Logn)
		int mid = low + (high - low) / 2;

		if(arr[mid] == x){
			// x will be floor and ceil both
			return {x, x};
		}
		else if(arr[mid] < x){
			floor = arr[mid];
			low = mid + 1; // to search in right half
		}
		else{
			ceil = arr[mid];
			high = mid - 1; // to search in left half
		}
	}

	pair<int, int> ans = make_pair(floor, ceil);
	return ans;
}