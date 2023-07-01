// Number of occurrence (GFG)
// GFG Link : https://bit.ly/3SVcOqW

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	// function to find the first occurrence
    int firstOccurrence(int arr[], int n, int x){
        int first = -1;
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] == x){
                first = mid;
                high = mid - 1; // to search in left half
            }
            else if(arr[mid] > x){
                high = mid - 1; // to search in left half
            }
            else{
                low = mid + 1; // to search in right half
            }
        }
        return first;
    }

    // function to find the last occurrence
    int lastOccurrence(int arr[], int n, int x){
        int last = -1;
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] == x){
                last = mid;
                low = mid + 1; // to search in right half
            }
            else if(arr[mid] > x){
                high = mid - 1; // to search in left half
            }
            else{
                low = mid + 1; // to search in right half
            }
        }
        return last;
    }
		
	int count(int arr[], int n, int x) {
	    // code here
	    // first occurrence of element
        int first = firstOccurrence(arr, n, x);

        // if element not exist then first and last occurrence will be -1
        if(first == -1) return 0;

        // last occurrence of element
        int last = lastOccurrence(arr, n, x);
        
        // calculate the total no. of occurrence
        int count = last - first + 1;
        
        return count;
	}
};