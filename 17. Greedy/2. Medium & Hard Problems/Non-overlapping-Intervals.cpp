// Non-overlapping Intervals (Leetcode)
// Leetcode Link : https://leetcode.com/problems/non-overlapping-intervals/description/

// Time Complexity : O(n + nLogn)
// Space Complexity : O(1)

class Solution {
public:
    // Comparator to sort intervals by their end time
    static bool comparator(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int overlapping = 0;

        // Sort intervals by end times
        sort(intervals.begin(), intervals.end(), comparator);

        // Track the end of the last non-overlapping interval
        int prevEnd = intervals[0][1];
        
        for(int i = 1; i < n; i++){
            // If there's an overlap, increment the count
            if(prevEnd > intervals[i][0]){
                overlapping++;
            } else {
                // No overlap, update prevEnd to the current interval's end
                prevEnd = intervals[i][1];
            }
        }

        return overlapping;
    }
};