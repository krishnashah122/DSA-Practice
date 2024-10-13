// Permutation in String (Leetcode)
// Leetcode Link : https://leetcode.com/problems/permutation-in-string/description/

// Time Complexity : O(n)
// Space Complexity : O(26) = O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        int k = s1.size();

        // Count the frequency of each character in s1
        for(char &ch : s1){
            mp[ch]++;
        }

        int left = 0;
        for(int right = 0; right < s2.size(); right++){
            // If the window size exceeds k, shrink the window
            if(k < (right - left + 1)){
                // If the character at the left boundary was in s1, restore its frequency
                if(mp.find(s2[left]) != mp.end()){
                    mp[s2[left]]++;
                }
                left++; // Move the left boundary to the right
            }

            // Decrease the frequency of the current character in the window
            if(mp.find(s2[right]) != mp.end()){
                mp[s2[right]]--;
            }

            // Check if the current window size is k
            if(k == (right - left + 1)){
                bool allZeros = true;
                // Check if all values in the hash map are zero (indicating an anagram)
                for(auto &duo : mp){
                    if(duo.second != 0) allZeros = false;
                }
                // If all values are zero, s2 contains a permutation of s1, return true
                if(allZeros) return true;
            }
        }

        // If s2 doesn't contain the permutation of s1, return false
        return false;
    }
};