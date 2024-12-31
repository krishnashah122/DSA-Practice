// Making A Large Island (Leetcode)
// Leetcode Link : https://leetcode.com/problems/making-a-large-island/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class DisjointSet {
public:
    vector<int> parent, size;
    
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int largestIsland = 0;

        // Step 1: Connect all neighboring 1-cells to form islands
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;

                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};

                for(int i = 0; i < 4; i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    // Step 2: Union the current cell with its adjacent 1-cell
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                        int currNode = row * n + col;
                        int adjNode = nRow * n + nCol;
                        ds.unionBySize(currNode, adjNode);
                    }
                }
            }
        }

        // Step 3: Try flipping each 0-cell and calculate the new island size
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;

                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};

                set<int> components;
                for(int i = 0; i < 4; i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    // Step 4: Collect all unique islands connected to the current 0-cell
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1){
                        components.insert(ds.find(nRow * n + nCol));
                    }
                }

                // Step 5: Add up the sizes of these islands and include the flipped cell
                int totalSize = 0;
                for(int it : components){
                    totalSize += ds.size[it];
                }

                // Step 6: Track the largest island size
                largestIsland = max(largestIsland, totalSize + 1);
            }
        }

        // Step 7: Check the size of the largest island without flipping any cell
        for(int cell = 0; cell < n * n; cell++){
            int cellParent = ds.find(cell);
            largestIsland = max(largestIsland, ds.size[cellParent]);
        }

        // Step 8: Return the size of the largest possible island after considering all flips
        return largestIsland;
    }
};