// Leaders in an array (GFG)
// GFG Link : https://bit.ly/3bZqbGc

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> leaders;
        int maxi = INT_MIN;
        
        for(int i = n-1; i >= 0; i--){
            // checking if a[i] >= maximum element among all the elements of its right side
            if(a[i] >= maxi){
                // store the element as a leader
                leaders.push_back(a[i]);
                // update the element as the maximum element
                maxi = a[i];
            }
        }
        
        // reverse the leaders to make it in the order of the array
        reverse(leaders.begin(), leaders.end());
        
        return leaders;
    }
};