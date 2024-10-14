// Word Break (GFG)
// GFG Link : https://shorturl.at/uHVm5

// Time Complexity : O(2^n)
// Space Complexity : O(m+n) [where, m is the no. of words in the dictionary.]

class Solution
{
public:
    // Helper function to recursively check for valid word segmentation
    void solve(string s, int start, unordered_set<string> &dictSet, vector<string> &words, int &ans){
        // Base case: if we've reached the end of the string
        if(start == s.size()){
            // Check if all collected words are in the dictionary
            for(auto word : words){
                if(dictSet.find(word) == dictSet.end()){
                    return;  // If any word is not in the dictionary, return
                }
            }
            ans = 1;  // Set answer to 1 if all words are valid
            return;
        }

        string word;
        for(int i = start; i < s.size(); i++){
            word += s[i];  // Build the word character by character
            
            // If word is found in dictionary and ans is not set
            if(dictSet.find(word) != dictSet.end() && !ans){
                words.push_back(word);  // Add word to the current list
                solve(s, i+1, dictSet, words, ans);  // Recursively check the rest of the string
                words.pop_back();  // Backtrack: remove the last added word
            }
        }
    }

    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        int ans = 0;
        vector<string> words;
        unordered_set<string> dictSet; // Set to store dictionary for fast lookup
        dictSet.insert(dictionary.begin(), dictionary.end());
        solve(s, 0, dictSet, words, ans);
        return ans;
    }
};