// Number of Operations to Make Network Connected (Leetcode)
// Leetcode Link : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

// Time Complexity : O(E * LogV)
// Space Complexity : O(E + V)

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int connectedComponents = 0;
        int countCycles = 0;

        for(auto connection : connections) {
            int u = connection[0];
            int v = connection[1];

            // Step 1: If u & v are already in the same set, increment cycle count
            int parentU = ds.find(u);
            int parentV = ds.find(v);

            if(parentU == parentV) {
                countCycles++;
                continue;
            }

            // Step 2: Perform union operation if u & v are from different set
            ds.unionBySize(u, v);
        }

        // Step 3: Count connected components
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) {
                connectedComponents++;
            }
        }

        // Step 4: Check if cycles are enough to connect all components
        if(countCycles < connectedComponents - 1) {
            return -1;
        }

        // Step 5: Return the no. of minimum operations needed
        return connectedComponents - 1;
    }
};