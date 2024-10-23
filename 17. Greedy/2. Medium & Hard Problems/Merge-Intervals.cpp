// Merge Intervals (Leetcode)
// Leetcode Link : https://leetcode.com/problems/merge-intervals/description/

// Time Complexity : O(n + nLogn)
// Space Complexity : O(n)

class Solution {
public:
    // Comparator function to sort intervals by their start time
    bool static comparator(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        // Step 1: Sort intervals based on their start time
        sort(intervals.begin(), intervals.end(), comparator);

        // Step 2: Initialize the first interval
        vector<int> newInterval = intervals[0];

        // Step 3: Iterate through intervals to merge overlapping ones
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] > newInterval[1]) {
                // No overlap, add the current interval to the result
                ans.push_back(newInterval);
                newInterval = intervals[i];
            } else {
                // Overlapping intervals, updating the end time of newInterval
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        // Step 4: Push the last merged interval
        ans.push_back(newInterval);

        return ans;
    }
};