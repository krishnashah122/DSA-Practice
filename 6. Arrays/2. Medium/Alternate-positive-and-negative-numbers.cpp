// Alternate positive and negative numbers (GFG)
// GFG Link : https://bit.ly/3Qr3sSs

// Time Complexity : O(2n) == O(n)
// Space Complexity : O(n)

class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos; // for storing all the positive numbers
	    vector<int> neg; // for storing all the negative numbers
	    
	    for(int i = 0; i < n; i++){
	        if(arr[i] >= 0){
	            pos.push_back(arr[i]);
	        }
	        else{ // arr[i] < 0
	            neg.push_back(arr[i]);
	        }
	    }
	    
	    int i = 0;
	    int j = 0;
	    int k = 0;
	    while(i < n){
	        // fill the positive number
	        if(i < n && j < pos.size()){
	            arr[i++] = pos[j++];
	        }
	        // fill the negative numbet
	        if(i < n && k < neg.size()){
	            arr[i++] = neg[k++];
	        }
	    }
	}
};