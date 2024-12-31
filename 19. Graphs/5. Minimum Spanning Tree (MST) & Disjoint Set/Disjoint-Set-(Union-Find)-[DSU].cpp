// Disjoint Set (Union-Find) [DSU]

// Time Complexity : O(α(n)) [Amortized Time Complexity]
// Space Complexity : O(n)

class DisjointSet {
    vector<int> parent, size, rank;

public:
    DisjointSet(int n) {
        // Step 1: Initialize parent, size, and rank arrays
        parent.resize(n);
        size.resize(n, 1);
        rank.resize(n, 0);

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

    void unionByRank(int u, int v) {
        // Step 1: Find roots of both elements
        int a = find(u);
        int b = find(v);

        // Step 2: If both the elements are from different set, merge lower rank set into higher rank set
        if(a != b) {
            if(rank[a] < rank[b]) {
                swap(a, b);
            } else if(rank[a] == rank[b]) {
                // Step 3: If both the sets are having same rank, increment the rank of the new root
                rank[a]++;
            }
            parent[b] = a;
        }
    }
};