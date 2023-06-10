// Second Largest (GFG)
// GFG Link : https://bit.ly/3pFvBcN

// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int print2largest(int arr[], int n) {
	    // code here
	    int largest = arr[0];
	    int secondLargest = -1;
	    for(int i = 0; i < n; i++){
	        if(arr[i] > largest){
	            secondLargest = largest;
	            largest = arr[i];
	        }
	        else if(arr[i] < largest && arr[i] > secondLargest){
	            secondLargest = arr[i];
	        }
	    }
	    return secondLargest;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}