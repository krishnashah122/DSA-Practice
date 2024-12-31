// Number of Distinct Islands (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0

// Time Complexity : O(m * n * Log(s)) [where, s is the no. of the distinct islands]
// Space Complexity : O(m * n)

class Solution {
  public:
    vector<pair<int, int>> bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> island;

        // Step 1: Push the starting cell to the queue and mark it as visited
        q.push({i, j});
        island.push_back({i - i, j - j}); // Record the relative position
        visited[i][j] = true;
        
        // Step 2: Perform BFS to explore all connected cells
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Step 3: Define movement directions (up, right, down, left)
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            
            for(int k = 0; k < 4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];
                
                // Step 4: Check if the cell is within bounds, unvisited, and part of the island
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1 && !visited[nRow][nCol]){
                    q.push({nRow, nCol});
                    visited[nRow][nCol] = true;
                    island.push_back({nRow - i, nCol - j}); // Record relative position
                }
            }
        }
        
        // Step 5: Return the shape of the island
        return island;
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        set<vector<pair<int, int>>> islands; // Set to store unique island shapes
        
        // Step 1: Traverse the grid to find unvisited land cells
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    // Step 2: Perform BFS and insert the shape into the set
                    vector<pair<int, int>> island = bfs(grid, i, j, visited);
                    islands.insert(island);
                }
            }
        }
        
        // Step 3: Return the count of distinct islands
        return islands.size();
    }
};