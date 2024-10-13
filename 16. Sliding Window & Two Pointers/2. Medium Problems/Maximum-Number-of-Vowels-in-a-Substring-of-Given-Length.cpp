// Maximum Number of Vowels in a Substring of Given Length (Leetcode)
// Leetcode Link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels = 0;
        int maxVowels = 0;
        
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            // If the current window size exceeds k, move the left pointer to shrink the window
            if(k < (right - left + 1)){
                // If the character at the left pointer is a vowel, decrement the vowel count
                if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u'){
                    vowels--;
                }
                left++; // Move the left pointer to the right to shrink the window
            }

            // If the current character is a vowel, increment the vowel count
            if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u'){
                vowels++;
            }

            // Update the maximum number of vowels found so far
            maxVowels = max(maxVowels, vowels);
        }

        return maxVowels;
    }
};