// Word Break II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/word-break-ii/description/

// Time Complexity : O(n * 2^n)
// Space Complexity : O(n * 2^n)

class Solution {
public:
    void solve(string &s, int start, unordered_set<string> &dictSet, vector<string> &words, vector<string> &sentences){
        // Step 1: Base case - if we reach the end of the string, form a sentence and store it
        if(start == s.size()){
            int n = words.size();
            string sentence;
            for(int i = 0; i < n; i++){
                sentence += words[i];
                if(i < n-1) sentence += " "; // Add space between words
            }
            sentences.push_back(sentence); // Store the formed sentence
            return;
        }

        // Step 2: Iterate through the string to extract possible words
        string word;
        for(int i = start; i < s.size(); i++){
            word += s[i];
            // Step 3: Check if the extracted word exists in the dictionary
            if(dictSet.find(word) != dictSet.end()){
                words.push_back(word); // Add the word to the current list
                solve(s, i+1, dictSet, words, sentences); // Recur for the next part of the string
                words.pop_back(); // Backtrack to explore other combinations
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        // Step 4: Save wordDict in a set for fast lookup
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());
        vector<string> words;
        solve(s, 0, dictSet, words, sentences);
        // Step 5: Return all possible sentences
        return sentences;
    }
};