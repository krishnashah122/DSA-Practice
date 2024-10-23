// Insert Interval (Leetcode)
// Leetcode Link : https://leetcode.com/problems/insert-interval/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        // Add all intervals that end before the newInterval starts
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals with the newInterval
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]); // Update start of newInterval
            newInterval[1] = max(intervals[i][1], newInterval[1]); // Update end of newInterval
            i++;
        }
        ans.push_back(newInterval); // Add the merged newInterval

        // Add the remaining intervals that start after the newInterval ends
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};