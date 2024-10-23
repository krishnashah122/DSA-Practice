// Shortest Job first (GFG)
// GFG Link : https://shorturl.at/yRdpH

// Time Complexity : O(n + nLogn)
// Space Complexity : O(1)

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        // Step 1: Sort burst times in ascending order
        sort(bt.begin(), bt.end());
        
        int t = 0; // Time passed so far
        int WT = 0; // Total waiting time
        
        // Step 2: Calculate the total waiting time for all process
        for(int i = 0; i < bt.size(); i++){
            WT += t; // Add the time a process waited before its execution
            t += bt[i]; // Update time passed after executing the current process
        }
        
        // Step 3: Return average waiting time
        return (long long) (WT / bt.size());
    }
};