// Number of Enclaves (Leetcode)
// Leetcode Link : https://leetcode.com/problems/number-of-enclaves/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<int, int>> q;
        int enclaves = 0;

        // Step 1: Mark all the boundary land cells and their reachable cells as visited
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 1){
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        // Step 2: Perform BFS to visit all reachable land cells from the boundary
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0){
                    visited[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }

        // Step 3: Count the land cells that are not visited, representing the enclaves
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != visited[i][j]){
                    enclaves++;
                }
            }
        }

        // Step 4: Return the total count of enclave land cells
        return enclaves;
    }
};