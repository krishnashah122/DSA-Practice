// Find All Anagrams in a String (Leetcode)
// Leetcode Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

// Time Complexity : O(n)
// Space Complexity : O(m) [where, m is the size of string p.]

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        unordered_map<char, int> mp;
        int count = 0;

        // Initialize the map with the frequency of each character in 'p'
        for(auto &ch : p){
            mp[ch]++;
        }

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            // If the current character in 's' is in 'p', increment the count
            if(mp[s[right]] > 0) count++;

            // Decrement the frequency of the current character in the map
            mp[s[right]]--;

            // If the window size exceeds the size of 'p', move left pointer to shrink the window
            if(p.size() < (right - left + 1)){
                // Increment the frequency of the character that is being removed from the window
                mp[s[left]]++;
                // If the removed character was part of 'p', decrement the count
                if(mp[s[left]] > 0) count--;
                // Move the left pointer to the right
                left++;
            }

            // If the count matches the size of 'p', it means an anagram is found
            if(count == p.size()){
                indices.push_back(left); // Store the starting index of the anagram
            }
        }

        return indices;
    }
};