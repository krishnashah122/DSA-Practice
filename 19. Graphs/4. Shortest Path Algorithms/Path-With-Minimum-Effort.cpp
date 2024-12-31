// Path With Minimum Effort (Leetcode)
// Leetcode Link : https://leetcode.com/problems/path-with-minimum-effort/description/

// Time Complexity : O(m * n * Log(m * n))
// Space Complexity : O(m * n)

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Step 1: Min-heap to store {effort, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Step 2: Distance matrix to store minimum effort to reach each cell
        vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
        
        // Step 3: Push starting point into the priority queue
        pq.push({0, 0, 0});
        distance[0][0] = 0;

        while(!pq.empty()){
            // Step 4: Extract the minimum effort path
            int diff = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            // Step 5: If destination is reached, return the minimum effort
            if(r == m-1 && c == n-1) return diff;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            // Step 6: Iterate through all 4 possible directions (up, right, down, left)
            for(int k = 0; k < 4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];

                // Step 7: Check bounds and calculate new effort
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n){
                    int nDiff = max(diff, abs(heights[r][c] - heights[nRow][nCol]));
                    
                    // Step 8: Update distance and push into the priority queue if better effort is found
                    if(nDiff < distance[nRow][nCol]){
                        distance[nRow][nCol] = nDiff;
                        pq.push({nDiff, nRow, nCol});
                    }
                }
            }
        }

        // Step 9: Return 0 as fallback (should never reach here)
        return 0;
    }
};