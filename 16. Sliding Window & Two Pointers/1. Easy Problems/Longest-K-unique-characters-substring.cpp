// Longest K unique characters substring (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char, int> mp;
        int longestSubstr = -1;
        
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            // Add the current character to the map and update its frequency
            mp[s[right]]++;
            
            // If the no. of unique characters exceeds k, shrink the window from the left
            while(mp.size() > k){
                mp[s[left]]--; // Decrease the frequency of the character at the left boundary
                // If the frequency of the character becomes zero, remove it from the map
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++; // Move the left boundary to the right
            }
            
            // If the no. of unique characters in the current window is k
            if(mp.size() == k){
                // Update the length of the longest substring found so far
                longestSubstr = max(longestSubstr, (right-left+1));
            }
        }
        
        return longestSubstr;
    }
};