// 01 Matrix (Leetcode)
// Leetcode Link : https://leetcode.com/problems/01-matrix/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distance(m, vector<int> (n, -1));
        queue<pair<int, int>> q;

        // Step 1: Add all 0 cells to the queue and set their distance to 0
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        // Step 2: Perform BFS to update distances
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            // Step 3: Explore all 4 neighbors
            for(int k = 0; k < 4; k++){
                int nRow = r + delRow[k];
                int nCol = c + delCol[k];

                // Step 4: If valid neighbor, update distance and add to queue
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && distance[nRow][nCol] == -1){
                    distance[nRow][nCol] = distance[r][c] + 1;
                    q.push({nRow, nCol});
                }
            }
        }
        
        // Step 5: Return the distance matrix
        return distance;
    }
};