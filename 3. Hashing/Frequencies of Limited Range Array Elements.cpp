// Frequencies of Limited Range Array Elements (GFG)

// Time Complexity for map : O(Logn)
// Time Complexity for unordered_map : O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        // Precomputing
        unordered_map<int, int> mpp; // Map stores all the values in sorted order
        for(int i = 0; i < N; i++){
            mpp[arr[i]]++;
        }
        for(int i = 0; i < N; i++){
            arr[i] = mpp[i + 1];
        }
    }
};

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}

