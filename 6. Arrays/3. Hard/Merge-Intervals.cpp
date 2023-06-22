// Merge Intervals (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/merge-intervals/description/
// GFG Link : https://bit.ly/3zRz904

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // sort the array
        sort(intervals.begin(), intervals.end()); // O(nLogn)
        
        for(int i = 0; i < intervals.size(); i++){ // O(n)
            // if ans is empty || start of current interval is > then the end of the previous interval of ans
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                // add the current interval in ans
                ans.push_back(intervals[i]);
            }
            // if overlapping between current interval and the previous interval of ans
            else if(intervals[i][0] <= ans.back()[1]){
                // update the end of the previous interval of ans
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};