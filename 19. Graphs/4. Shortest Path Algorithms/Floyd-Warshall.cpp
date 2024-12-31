// Floyd Warshall (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Time Complexity : O(V^3)
// Space Complexity : O(V^2) [Input matrix space]

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int V = mat.size();
        // Step 1: Initialize all unreachable edges (-1) to a large value (1e9)
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 1e9;
                }
            }
        }
        
        // Step 2: Apply Floyd-Warshall Algorithm to compute shortest distances
        for(int via = 0; via < V; via++){
            for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }
        
        // Step 3: Check for the presence of a negative cycle
        for(int i = 0; i < V; i++){
            if(mat[i][i] < 0){
                cout << "Negative cycle exists" << endl;
            }
        }
        
        // Step 4: Convert all unreachable edges (1e9) back to -1
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(mat[i][j] == 1e9){
                    mat[i][j] = -1;
                }
            }
        }
        
        return;
    }
};