// Number Of Islands (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/number-of-islands/1

// Time Complexity : O(k)
// Space Complexity : O((n * m) + k)

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        // Step 1: Initialize parent and size arrays
        parent.resize(n);
        size.resize(n, 1);

        // Step 2: Each element is its own parent initially
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // Step 1: Path compression for efficient find
        if(parent[x] == x) return parent[x];
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v) {
        // Step 1: Find roots of both elements
        int a = find(u);
        int b = find(v);

        // Step 2:  If both elements are from different set, merge smaller set into larger set
        if(a != b) {
            if(size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        // Step 1: Initialize DisjointSet, visited grid, and island count
        DisjointSet ds(n * m);
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> ans;
        int countIslands = 0;

        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            // Step 2: If cell is already visited, add current island count to result
            if(visited[row][col]){
                ans.push_back(countIslands);
                continue;
            }

            // Step 3: Mark cell as visited and increase island count
            visited[row][col] = true;
            countIslands++;

            // Step 4: Check neighboring cells and join islands if connected
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol]){
                    int currNode = row * m + col;
                    int adjNode = nRow * m + nCol;

                    if(ds.find(currNode) != ds.find(adjNode)){
                        ds.unionBySize(currNode, adjNode); // Merge the two islands
                        countIslands--; // Reduce island count after merging
                    }
                }
            }

            // Step 5: Add current island count to the result
            ans.push_back(countIslands);
        }
        
        // Step 6: Return the final list of island counts after all operations
        return ans;
    }
};