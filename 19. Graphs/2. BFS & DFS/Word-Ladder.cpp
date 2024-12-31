// Word Ladder (Leetcode)
// Leetcode Link : https://leetcode.com/problems/word-ladder/description/

// Time Complexity : O(n * l * 26) [where, n = no. of words, l = length of each word]
// Space Complexity : O(n * l)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Store word list in a set for quick lookup
        unordered_set words(wordList.begin(), wordList.end());

        // Step 2: Initialize queue for BFS and add the begin word & remove it from the set
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);

        while(!q.empty()){
            // Step 3: Get current word and step count
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Step 4: Return steps if end word is found
            if(word == endWord) return steps;

            // Step 5: Try all one-letter transformations
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    // Step 6: If valid transformation, add to queue and remove from set
                    if(words.find(word) != words.end()){
                        words.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // Restore original word
            }
        }

        // Step 7: Return 0 if no path to end word
        return 0;
    }
};