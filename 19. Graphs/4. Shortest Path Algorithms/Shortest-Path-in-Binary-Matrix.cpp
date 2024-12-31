// Shortest Path in Binary Matrix (Leetcode)
// Leetcode Link : https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// Time Complexity : O(n^2 * Logn)
// Space Complexity : O(n^2)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Initialize distance matrix and priority queue
        vector<vector<int>> distance(n, vector<int> (n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Step 2: Check if the starting cell is blocked
        if(grid[0][0] != 0) return -1;

        // Step 3: Add the starting cell to the priority queue and set its distance to 1
        pq.push({1, 0, 0});
        distance[0][0] = 1;

        // Step 4: Process cells until the priority queue is empty
        while(!pq.empty()){
            int weight = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            // Step 5: Traverse all 8 possible directions
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nRow = r + i;
                    int nCol = c + j;

                    // Step 6: If the next cell is valid, unblocked, & provides a shorter path, update the distance & push it into the queue
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0 && weight + 1 < distance[nRow][nCol]){
                        distance[nRow][nCol] = weight + 1;
                        pq.push({distance[nRow][nCol], nRow, nCol});
                    }
                }
            }
        }

        // Step 7: Return the shortest path distance to the bottom-right corner, or -1 if unreachable
        return distance[n-1][n-1] == INT_MAX ? -1 : distance[n-1][n-1];
    }
};