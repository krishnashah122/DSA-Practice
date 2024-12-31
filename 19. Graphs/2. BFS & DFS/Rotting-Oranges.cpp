// Rotting Oranges (Leetcode)
// Leetcode Link : https://leetcode.com/problems/rotting-oranges/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        int minutes = 0;

        // Step 1: Push all initially rotten oranges into the queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({grid[i][j], i, j});
                }
            }
        }

        // Step 2: Perform BFS to spread the rot to neighboring fresh oranges
        while(!q.empty()){
            int num = q.size();

            for(int i = 0; i < num; i++){
                vector<int> orange = q.front();
                q.pop();

                int row = orange[1];
                int col = orange[2];

                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};

                // Step 3: Check all 4 neighboring cells for fresh oranges
                for(int k = 0; k < 4; k++){
                    int nRow = row + delRow[k];
                    int nCol = col + delCol[k];

                    if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                        grid[nRow][nCol] = 2;
                        q.push({grid[nRow][nCol], nRow, nCol});
                    }
                }
            }

            if(!q.empty()) minutes++;
        }

        // Step 4: Check if there are any fresh oranges left
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        // Step 5: Return the time taken for all oranges to rot
        return minutes;
    }
};