// Surrounded Regions (Leetcode)
// Leetcode Link : https://leetcode.com/problems/surrounded-regions/description/

// Time Complexity : O(m * n)
// Space Complexity : O(m * n)

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, vector<vector<bool>> &visited){
        int m = board.size();
        int n = board[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Step 1: Explore all 4 directions from the current cell
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            // Step 2: Check bounds, 'O' cell, and if unvisited, then mark it as visited & continue DFS
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && board[nRow][nCol] == 'O' && !visited[nRow][nCol]){
                visited[nRow][nCol] = true;
                dfs(board, nRow, nCol, visited);
            }
        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        stack<pair<int, int>> st;

        // Step 1: Mark all boundary 'O's and push to the stack
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O'){
                        visited[i][j] = true;
                        st.push({i, j});
                    }
                }
            }
        }

        // Step 2: Perform DFS from all boundary 'O's to mark connected 'O's
        while(!st.empty()){
            int row = st.top().first;
            int col = st.top().second;
            st.pop();

            dfs(board, row, col, visited);
        }

        // Step 3: Flip all unvisited 'O's to 'X'
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};