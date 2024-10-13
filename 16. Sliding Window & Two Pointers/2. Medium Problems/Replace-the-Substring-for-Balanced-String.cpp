// Replace the Substring for Balanced String (Leetcode)
// Leetcode Link : https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/

// Time Complexity : O(n)
// Space Complexity : O(4) = O(1)

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        int target = s.size() / 4;
        int ans = s.size();

        // Populate the frequency map with the counts of each character in the string
        for(auto &ch : s){
            mp[ch]++;
        }

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            // Decrease the count of the current character
            mp[s[right]]--;

            // Check if the current window is valid
            // A window is valid if all characters are within the target frequency
            while (left < s.size() && mp['Q'] <= target && mp['W'] <= target &&
                mp['E'] <= target && mp['R'] <= target) {
                // Update the answer with the minimum length of a valid window
                ans = min(ans, (right - left + 1));
                
                // Increase the count of the character at the left pointer
                mp[s[left]]++;
                
                // Move the left pointer to the right
                left++;
            }
        }

        return ans;
    }
};