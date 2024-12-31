// BFS of graph (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Time Complexity : O(V + E)
// Space Complexity : O(V)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        // Step 1: Initialize visited array, result vector, and queue
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        queue<int> q;

        // Step 2: Start BFS from node 0
        q.push(0);
        ans.push_back(0);
        visited[0] = true;

        // Step 3: Traverse the graph using BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Step 4: Visit all unvisited neighbors
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor); // Add the neighbor in queue
                    visited[neighbor] = true; // Mark the neighbor as visited
                    ans.push_back(neighbor); // Add the neighbor in result
                }
            }
        }

        // Step 5: Return the BFS traversal
        return ans;
    }
};