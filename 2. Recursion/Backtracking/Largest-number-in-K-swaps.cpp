// Largest number in K swaps (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

// Time Complexity : O(n^k)
// Space Complexity : O(n)

class Solution
{
    public:
    // Helper function to perform swaps and find the maximum number.
    void solve(string &str, int k, int start, string &ans){
        // Base case: end or no swaps left
        if(start == str.size() - 1 || k == 0) return;
        
        char maxi = *max_element(str.begin() + start + 1, str.end()); // Find max in remaining string
        
        for(int i = start + 1; i < str.size(); i++) {
            // Swap if current character is greater and matches the max
            if(str[i] > str[start] && str[i] == maxi) {
                swap(str[start], str[i]); // Swap to get larger number
                if(str > ans) ans = str;  // Update answer if new string is greater
                solve(str, k-1, start+1, ans); // Recurse with remaining swaps
                swap(str[start], str[i]); // Backtrack
            }
        }
        solve(str, k, start+1, ans); // Move to the next position
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       solve(str, k, 0, ans);
       return ans;
    }
};