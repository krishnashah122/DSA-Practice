// Minimum Spanning Tree (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Time Complexity : O((V + E) * LogV) - [Prim's Algorithm] & O(E * LogV) - [Kruskal's Algorithm]
// Space Complexity : O(E + V) - [Prim's Algorithm & Kruskal's Algorithm]

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
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // 1. Prim's Algorithm
        // // Step 1: Initialize priority queue (min-heap) and visited array
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // vector<bool> visited(V, false);

        // // Step 2: Push the starting node (weight 0, node 0) into the priority queue
        // pq.push({0, 0});
        // int sumOfMST = 0;

        // while(!pq.empty()){
        //     // Step 3: Extract the node with the smallest weight from the priority queue
        //     int weight = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();

        //     // Step 4: Skip if the node is already visited
        //     if(visited[node]) continue;

        //     // Step 5: Mark the node as visited and add its weight to the MST sum
        //     visited[node] = true;
        //     sumOfMST += weight;

        //     // Step 6: Traverse all adjacent nodes and push unvisited ones into the priority queue
        //     for(auto neighbor : adj[node]){
        //         int vertex = neighbor[0];
        //         int wt = neighbor[1];

        //         if(!visited[vertex]){
        //             pq.push({wt, vertex});
        //         }
        //     }
        // }

        // // Step 7: Return the total weight of the MST
        // return sumOfMST;
        
        
        // 2. Kruskal's Algorithm
        vector<pair<int, pair<int, int>>> edges; // Store edges as (weight, (node1, node2))
        DisjointSet ds(V);
        int sumOfMST = 0;
        
        // Step 1: Create a list of all edges with weights
        for(int i = 0; i < V; i++){
            for(auto neighbor : adj[i]){
                int node = neighbor[0];
                int weight = neighbor[1];
                edges.push_back({weight, {i, node}});
            }
        }
        
        // Step 2: Sort edges by weight to process in increasing order
        sort(edges.begin(), edges.end());
        
        // Step 3: Apply Kruskal's algorithm to find the MST
        for(auto edge : edges){
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            int parentU = ds.find(u);
            int parentV = ds.find(v);
            
            if(parentU == parentV) continue; // Skip if u and v are already connected
            
            ds.unionBySize(u, v); // Union the sets
            sumOfMST += weight; // Add weight to MST
        }
        
        // Step 4: Return the total weight of the MST
        return sumOfMST;
    }
};