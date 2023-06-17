// Longest Consecutive Sequence (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/longest-consecutive-sequence/description/
// GFG Link : https://bit.ly/3ApytAD

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int longest = 0;

        // store elements in set
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        // iterate through the set
        for(auto it : st){
            // check if it-1 is present in the set or not
            if(st.find(it - 1) == st.end()){
                // if not present then take it as the starting element
                int currElement = it;
                int currCount = 1;
                // keep checking if consecutive elements are present or not
                while(st.find(currElement + 1) != st.end()){
                    currElement++;
                    currCount++;
                }
                // update the length of longest consecutive sequence
                longest = max(longest, currCount);
            }
        }

        return longest;
    }
};