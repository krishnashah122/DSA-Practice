// Assign Cookies (Leetcode)
// Leetcode Link : https://leetcode.com/problems/assign-cookies/description/

// Time Complexity : O(mLogm + nLogn + min(m,n)) [where, m is the no. of children & n is the no. of cookies.]
// Space Complexity : O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort greed factors of children and sizes of cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0; // Pointer for cookie sizes
        int r = 0; // Pointer for children greed factors
        
        // Iterate through both arrays
        while(l < s.size() && r < g.size()){
            // If current cookie can satisfy the current child
            if(g[r] <= s[l]){
                r++; // Move to the next child
            }
            l++; // Move to the next cookie
        }

        // Return the number of content children
        return r;
    }
};