// Count Occurences of Anagrams (GFG)
// GFG Link : https://shorturl.at/6ub2x

// Time Complexity : O(n)
// Space Complexity : O(26) = O(1)

class Solution{
public:
	int search(string pat, string txt) {
	    // code here
        unordered_map<char, int> mp;
        int k = pat.size();
        int countAnagrams = 0;
	    
	    // Count the frequency of each character in the pattern
	    for(char &ch : pat){
	        mp[ch]++;
	    }
	    
	    int left = 0;
	    for(int right = 0; right < txt.size(); right++){
	        // If the window size exceeds k, shrink the window
	        if(k < (right - left + 1)){
	            // If the character at the left boundary was in the pattern, restore its frequency
	            if(mp.find(txt[left]) != mp.end()){
	                mp[txt[left]]++;
	            }
	            left++; // Move the left boundary to the right
	        }
	        
	        // Decrease the frequency of the current character in the window
	        if(mp.find(txt[right]) != mp.end()){
	            mp[txt[right]]--;
	        }
	        
	        // Check if the current window size matches the length of the pattern
	        if(k == (right - left + 1)){
	            bool allZeros = true;
	            // Check if all values in the hash map are zero (indicating an anagram)
	            for(auto &duo : mp){
	                if(duo.second != 0) allZeros = false;
	            }
	            // If all values are zero, increment the count of anagrams
	            if(allZeros) countAnagrams++;
	        }
	    }
	    
	    return countAnagrams;
	}

};