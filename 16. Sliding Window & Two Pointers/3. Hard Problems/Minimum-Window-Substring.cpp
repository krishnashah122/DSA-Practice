// Minimum Window Substring (Leetcode)
// Leetcode Link : https://leetcode.com/problems/minimum-window-substring/description/

// Time Complexity : O(n)
// Space Complexity : O(26) = O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int count = 0;
        int minLen = INT_MAX;
        int minStart = -1;

        // Populate the hash map with the frequency of each character in t
        for(int i = 0; i < t.size(); i++){
            mp[t[i]]++;
        }

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            // If the current character in s is part of t (i.e., frequency > 0), increment the count
            if(mp[s[right]] > 0){
                count++;
            }

            // Decrement the frequency of the current character in the map
            mp[s[right]]--;

            // When the count equals the size of t, it means the current window contains all characters of t
            while(count == t.size()){
                // Update the minimum length and start position if a smaller window is found
                if((right - left + 1) < minLen){
                    minLen = (right - left + 1);
                    minStart = left;
                }

                // Move the left pointer to shrink the window
                mp[s[left]]++;
                if(mp[s[left]] > 0) count--; // If the character at left is part of t, decrease the count
                left++;
            }
        }

        // If a valid window is found, return the substring, otherwise return an empty stringv
        return minStart < 0 ? "" : s.substr(minStart, minLen);
    }
};