// Most Stones Removed with Same Row or Column (Leetcode)
// Leetcode Link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

// Time Complexity : O(n)
// Space Complexity : O(maxRow + maxCol)

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        // Step 1: Initialize parent and size arrays
        parent.resize(n+1);
        size.resize(n+1, 1);

        // Step 2: Each element is its own parent initially
        for(int i = 0; i <= n; i++) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        int removedStones = 0;

        // Step 1: Determine the maximum row and column indices among stones
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Step 2: Initialize Disjoint Set for union-find operations
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;

        // Step 3: Map each stone's row and column to nodes and perform union operation
        for(auto it : stones){
            int rowNode = it[0];
            int colNode = maxRow + 1 + it[1];
            ds.unionBySize(rowNode, colNode);
            stoneNodes[rowNode] = 1; // Mark row node as present
            stoneNodes[colNode] = 1; // Mark column node as present
        }

        // Step 4: Count the no. of unique connected components
        for(auto it : stoneNodes){
            if(ds.find(it.first) == it.first){
                removedStones++;
            }
        }

        // Step 5: Return the number of stones that can be removed
        return (n - removedStones);
    }
};