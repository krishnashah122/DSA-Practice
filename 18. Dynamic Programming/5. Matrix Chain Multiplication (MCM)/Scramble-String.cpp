// Scramble String (Leetcode)
// Leetcode Link : https://leetcode.com/problems/scramble-string/description/

// Time Complexity : O(n^4)
// Space Complexity : O(n^3)

class Solution {
public:
    bool solve(string s1, string s2, unordered_map<string, bool> &mp){
        // Step 1: Base case: if strings are same, return true
        if(s1 == s2) return true;

        // Step 2: Base case: if sizes of strings don't match, return false
        if(s1.size() != s2.size()) return false;

        // Step 3: Create a unique key from s1 and s2 to store the result in memoization map
        string key = s1 + "_" + s2;
        // Step 4: Check if this state has been solved before
        if(mp.find(key) != mp.end()) return mp[key];

        int n = s1.size();
        bool result = false;
        // Step 5: Try splitting the strings at each position from 1 to n-1
        for(int i = 1; i < n; i++){
            // Step 6: Check if swapping the two halves results in s1 becoming s2
            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i), mp)
                            && solve(s1.substr(i, n-i), s2.substr(0, n-i), mp);
            // Step 7: Check if not swapping the two halves results in s1 becoming s2
            bool notswapped = solve(s1.substr(0, i), s2.substr(0, i), mp)
                            && solve(s1.substr(i, n-i), s2.substr(i, n-i), mp);
            
            // Step 8: If either swapping or not swapping results in a match, mark result as true
            if(swapped || notswapped){
                result = true;
                break;
            }
        }

        // Step 9: Store the result in the map for the current key
        return mp[key] = result;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> mp;
        return solve(s1, s2, mp);
    }
};