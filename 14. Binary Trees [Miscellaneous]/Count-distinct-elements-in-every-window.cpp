// Count distinct elements in every window (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        map<int, int> mp;
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            // Increment the frequency of the current element in the map
            mp[A[i]]++;
            
            // Check if we have processed at least one full window
            if(i >= k-1){
                // Add no. of distinct elements in the current window
                ans.push_back(mp.size());
                
                // If sliding out element's frequency becomes 1, remove it from the map
                if(mp[A[i+1-k]] == 1){
                    mp.erase(A[i+1-k]);
                }else{
                    // Otherwise, decrement its frequency by 1
                    mp[A[i+1-k]]--;
                }
            }
        }
        
        return ans;
    }
};